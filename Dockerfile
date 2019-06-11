# daemon runs in the background
# run something like tail /var/log/marcoind/current to see the status
# be sure to run with volumes, ie:
# docker run -v $(pwd)/marcoind:/var/lib/marcoind -v $(pwd)/wallet:/home/marcoin --rm -ti marcoin:0.2.2
ARG base_image_version=0.10.0
FROM phusion/baseimage:$base_image_version

ADD https://github.com/just-containers/s6-overlay/releases/download/v1.21.2.2/s6-overlay-amd64.tar.gz /tmp/
RUN tar xzf /tmp/s6-overlay-amd64.tar.gz -C /

ADD https://github.com/just-containers/socklog-overlay/releases/download/v2.1.0-0/socklog-overlay-amd64.tar.gz /tmp/
RUN tar xzf /tmp/socklog-overlay-amd64.tar.gz -C /

ARG MARCOIN_BRANCH=master
ENV MARCOIN_BRANCH=${MARCOIN_BRANCH}

# install build dependencies
# checkout the latest tag
# build and install
RUN apt-get update && \
    apt-get install -y \
      build-essential \
      python-dev \
      gcc-4.9 \
      g++-4.9 \
      git cmake \
      libboost1.58-all-dev && \
    git clone https://github.com/marcoinproject/marcoin.git /src/marcoin && \
    cd /src/marcoin && \
    git checkout $MARCOIN_BRANCH && \
    mkdir build && \
    cd build && \
    cmake -DCMAKE_CXX_FLAGS="-g0 -Os -fPIC -std=gnu++11" .. && \
    make -j$(nproc) && \
    mkdir -p /usr/local/bin && \
    cp src/marcoind /usr/local/bin/marcoind && \
    cp src/walletd /usr/local/bin/walletd && \
    cp src/zedwallet /usr/local/bin/zedwallet && \
    cp src/miner /usr/local/bin/miner && \
    strip /usr/local/bin/marcoind && \
    strip /usr/local/bin/walletd && \
    strip /usr/local/bin/zedwallet && \
    strip /usr/local/bin/miner && \
    cd / && \
    rm -rf /src/marcoin && \
    apt-get remove -y build-essential python-dev gcc-4.9 g++-4.9 git cmake libboost1.58-all-dev && \
    apt-get autoremove -y && \
    apt-get install -y  \
      libboost-system1.58.0 \
      libboost-filesystem1.58.0 \
      libboost-thread1.58.0 \
      libboost-date-time1.58.0 \
      libboost-chrono1.58.0 \
      libboost-regex1.58.0 \
      libboost-serialization1.58.0 \
      libboost-program-options1.58.0 \
      libicu55

# setup the marcoind service
RUN useradd -r -s /usr/sbin/nologin -m -d /var/lib/marcoind marcoind && \
    useradd -s /bin/bash -m -d /home/marcoin marcoin && \
    mkdir -p /etc/services.d/marcoind/log && \
    mkdir -p /var/log/marcoind && \
    echo "#!/usr/bin/execlineb" > /etc/services.d/marcoind/run && \
    echo "fdmove -c 2 1" >> /etc/services.d/marcoind/run && \
    echo "cd /var/lib/marcoind" >> /etc/services.d/marcoind/run && \
    echo "export HOME /var/lib/marcoind" >> /etc/services.d/marcoind/run && \
    echo "s6-setuidgid marcoind /usr/local/bin/marcoind" >> /etc/services.d/marcoind/run && \
    chmod +x /etc/services.d/marcoind/run && \
    chown nobody:nogroup /var/log/marcoind && \
    echo "#!/usr/bin/execlineb" > /etc/services.d/marcoind/log/run && \
    echo "s6-setuidgid nobody" >> /etc/services.d/marcoind/log/run && \
    echo "s6-log -bp -- n20 s1000000 /var/log/marcoind" >> /etc/services.d/marcoind/log/run && \
    chmod +x /etc/services.d/marcoind/log/run && \
    echo "/var/lib/marcoind true marcoind 0644 0755" > /etc/fix-attrs.d/marcoind-home && \
    echo "/home/marcoin true marcoin 0644 0755" > /etc/fix-attrs.d/marcoin-home && \
    echo "/var/log/marcoind true nobody 0644 0755" > /etc/fix-attrs.d/marcoind-logs

VOLUME ["/var/lib/marcoind", "/home/marcoin","/var/log/marcoind"]

ENTRYPOINT ["/init"]
CMD ["/usr/bin/execlineb", "-P", "-c", "emptyenv cd /home/marcoin export HOME /home/marcoin s6-setuidgid marcoin /bin/bash"]
