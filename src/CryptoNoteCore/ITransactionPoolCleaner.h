/*
 * Copyright (c) 2018, The Marcoin Developers.
 * Portions Copyright (c) 2012-2017, The CryptoNote Developers, The Bytecoin Developers.
 *
 * This file is part of Marcoin.
 *
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE', which is part of this source code package.
 */

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

  virtual std::vector<Crypto::Hash> clean() = 0;
};

} //namespace CryptoNote
