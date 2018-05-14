@echo off

mkdir build
del /s /q build
cd build

if "%1"=="dyn" goto :dyn
echo Static Build
cmake.exe -G  "Visual Studio 14 2015 Win64"  ..
msbuild Marcoin.sln /p:Configuration=Release


EXIT /B 



:dyn
echo Dynamic Build
cmake.exe -G  "Visual Studio 14 2015 Win64"  -DSTATIC=NO  ..
msbuild Marcoin.sln /p:Configuration=Release

echo Copying libs
del /s /q \opt\marcoin\libs
md \opt\marcoin\libs
for /r "\opt\marcoin" %%x in (*.lib) do copy "%%x" "\opt\marcoin\libs"

 

