// Copyright (c) 2012-2017, The CryptoNote developers, The Marcoin developers
// Copyright (c) 2018, The Marcoin Developers
// 
// Please see the included LICENSE file for more information.

#pragma once

#include <vector>

#include "CryptoNoteCore/ITransactionPool.h"

namespace Crypto {
struct Hash;
}

namespace CryptoNote {

class ITransactionPoolCleanWrapper: public ITransactionPool {
public:
  virtual ~ITransactionPoolCleanWrapper() {}

  virtual std::vector<Crypto::Hash> clean(const uint32_t height) = 0;
};

} //namespace CryptoNote
