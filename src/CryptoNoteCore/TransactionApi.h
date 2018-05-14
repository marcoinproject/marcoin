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

#include <memory>
#include "ITransaction.h"

namespace CryptoNote {
  std::unique_ptr<ITransaction> createTransaction();
  std::unique_ptr<ITransaction> createTransaction(const BinaryArray& transactionBlob);
  std::unique_ptr<ITransaction> createTransaction(const Transaction& tx);

  std::unique_ptr<ITransactionReader> createTransactionPrefix(const TransactionPrefix& prefix, const Crypto::Hash& transactionHash);
  std::unique_ptr<ITransactionReader> createTransactionPrefix(const Transaction& fullTransaction);
}
