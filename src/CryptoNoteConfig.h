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

#include <cstddef>
#include <cstdint>
#include <limits>
#include <initializer_list>

namespace CryptoNote {
namespace parameters {

#define CRYPTONOTE_MAX_BLOCK_NUMBER                     500000000
#define CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                  500000000
#define CRYPTONOTE_MAX_TX_SIZE                          1000000000
#define CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX         8943 // starts with "h2"
#define CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW            30
#define CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT              360 //keep it to 6 minutes to prevent bad behavior. 

#define BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW               60

#define MONEY_SUPPLY                                    84000000
#define MIN_MIXIN                                       0
#define MANDATORY_MIXIN_BLOCK_VERSION                   0
#define KILL_HEIGHT                                     0
#define ZAWY_DIFFICULTY_BLOCK_INDEX                     0
#define ZAWY_DIFFICULTY_V2                              1
#define ZAWY_DIFFICULTY_DIFFICULTY_BLOCK_VERSION        0


#define EMISSION_SPEED_FACTOR                           20
#define GENESIS_BLOCK_REWARD                            4560000

#define CRYPTONOTE_REWARD_BLOCKS_WINDOW                 100
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE       100000
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2    90000
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1    80000
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE
#define CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE          600
#define CRYPTONOTE_MONEY_DECIMAL_POINT                  12
#define CRYPTONOTE_MONEY_DECIMAL_UNITS                  (uint64_t)pow(10, CRYPTONOTE_MONEY_DECIMAL_POINT)
#define MINIMUM_FEE                                     (uint64_t)pow(10, CRYPTONOTE_MONEY_DECIMAL_POINT / 2)
#define DEFAULT_FEE                                     (uint64_t)pow(10, CRYPTONOTE_MONEY_DECIMAL_POINT - 2)
#define DEFAULT_DUST_THRESHOLD                          MINIMUM_FEE

#define MARCOIN_TRANSACTION_SIZE_LIMIT                    100000 
#define MEMPOOL_POLLING_INTERVAL                        60 // how often to clean mempool

#define DIFFICULTY_TARGET                               180
#define EXPECTED_NUMBER_OF_BLOCKS_PER_DAY               24 * 60 * 60 / DIFFICULTY_TARGET
#define DIFFICULTY_WINDOW                               EXPECTED_NUMBER_OF_BLOCKS_PER_DAY
#define DIFFICULTY_WINDOW_V1                            DIFFICULTY_WINDOW
#define DIFFICULTY_WINDOW_V2                            DIFFICULTY_WINDOW
#define DIFFICULTY_WINDOW_V4                            62
#define DIFFICULTY_WINDOW_V5                            90
#define DIFFICULTY_CUT                                  60
#define DIFFICULTY_CUT_V1                               DIFFICULTY_CUT
#define DIFFICULTY_CUT_V2                               DIFFICULTY_CUT
#define DIFFICULTY_LAG                                  15
#define DIFFICULTY_LAG_V1                               DIFFICULTY_LAG
#define DIFFICULTY_LAG_V2                               DIFFICULTY_LAG

#define ITERS_V5                                         0x100000
#define MAX_BLOCK_SIZE_INITIAL                          100 * 1024
#define MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR           100 * 1024
#define MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR         365 * 24 * 60 * 60 / DIFFICULTY_TARGET

#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS       1
#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS      DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS

#define CRYPTONOTE_MEMPOOL_TX_LIVETIME                  60 * 60 * 24
#define CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME   CRYPTONOTE_MEMPOOL_TX_LIVETIME * 7
#define CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL 7

#define FUSION_TX_MIN_INPUT_COUNT                       12
#define FUSION_TX_MIN_IN_OUT_COUNT_RATIO                4

#define KEY_IMAGE_CHECKING_BLOCK_INDEX                  0
#define UPGRADE_HEIGHT_V2                               1
#define UPGRADE_HEIGHT_V3                               2
#define UPGRADE_HEIGHT_V4                               17500
#define UPGRADE_HEIGHT_V5                               150000

#define UPGRADE_VOTING_THRESHOLD                        90
#define UPGRADE_VOTING_WINDOW                           EXPECTED_NUMBER_OF_BLOCKS_PER_DAY
#define UPGRADE_WINDOW                                  EXPECTED_NUMBER_OF_BLOCKS_PER_DAY

#define CRYPTONOTE_BLOCKS_FILENAME                      "blocks.bin"
#define CRYPTONOTE_BLOCKINDEXES_FILENAME                "blockindexes.bin"
#define CRYPTONOTE_POOLDATA_FILENAME                    "poolstate.bin"
#define P2P_NET_DATA_FILENAME                           "p2pstate.bin"
#define MINER_CONFIG_FILE_NAME                          "miner_conf.json"

} // parameters

#define CRYPTONOTE_NAME                                 "marcoin"
#define CRYPTONOTE_GENESIS_TX                           "011e01ff000180a99602020334c839ca2aaeaba7b13a5f81d5a3846ab336cfccab1cfb9511741f18c7c13f21013df5c1a0f54d09531ea6b3374206ef244a3d85134177276ef31bc676c1070ad8"

#define TRANSACTION_VERSION_1                           1
#define TRANSACTION_VERSION_2                           2
#define CURRENT_TRANSACTION_VERSION                     TRANSACTION_VERSION_1
#define BLOCK_MAJOR_VERSION_1                           1
#define BLOCK_MAJOR_VERSION_2                           2
#define BLOCK_MAJOR_VERSION_3                           3
#define BLOCK_MAJOR_VERSION_4                           4
#define BLOCK_MAJOR_VERSION_5                           5


#define BLOCK_MINOR_VERSION_0                           0
#define BLOCK_MINOR_VERSION_1                           1

#define BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT          20000
#define BLOCKS_SYNCHRONIZING_DEFAULT_COUNT              4096
#define COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT           1000

#define P2P_DEFAULT_PORT                                8606
#define RPC_DEFAULT_PORT                                8607

#define P2P_LOCAL_WHITE_PEERLIST_LIMIT                  1000
#define P2P_LOCAL_GRAY_PEERLIST_LIMIT                   5000

#define P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE            64 * 1024 * 1024
#define P2P_DEFAULT_CONNECTIONS_COUNT                   8
#define P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT       70
#define P2P_DEFAULT_HANDSHAKE_INTERVAL                  60
#define P2P_DEFAULT_PACKET_MAX_SIZE                     50000000
#define P2P_DEFAULT_PEERS_IN_HANDSHAKE                  250
#define P2P_DEFAULT_CONNECTION_TIMEOUT                  5000
#define P2P_DEFAULT_PING_CONNECTION_TIMEOUT             2000
#define P2P_DEFAULT_INVOKE_TIMEOUT                      60 * 2 * 1000
#define P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT            5000


const std::initializer_list<const char*> SEED_NODES {
   "46.101.195.19:8606",
    "206.189.56.177:8606",
	"207.154.226.50:8606",
	"185.45.75.36:8606"
};

struct CheckpointData {
  uint32_t index;
  const char* blockId;
};

#ifdef __GNUC__
__attribute__((unused))
#endif

const std::initializer_list<CheckpointData> CHECKPOINTS {
  { 1, "ac98a6e9486986bf74f46fa540f935307290f41b5446b4a86e47777206bc6042" },
  { 2500, "f10324b11b25322955ba890335ee135d83e41d53a8e4f57da678a5ce25d086d2" },
  { 5000, "ff6ec01f2f62accf724dd731c083bf275a6d386b4f95658fc76b84c17057eda0" },
  {11000, "4aaa9bb347414f7bd19d64148d263ae47417e8cc934c2bdf5284d1b7ac2b9fe3" },
  {17500, "1acb57fa10d191c77694a532271c56fb6ec810f604a4c5ac16a9c26c726a2a4a"},
  {17501, "f3ad14f4d19e2b687429b45872543e7251d71874880bb58f5de702c0ba0c67e5"},
  {17502, "2db4cc802094d905ac77ee86fe366ca7af709a261c46e19e78603b60287ab655"},
  {17503, "df4ac514f27ad6dc0a735ed36e02d676f4cb8baa0b6a20cf8b992378c13ccbed"},
  {17504, "e771b4952a630c2344141931a9abf2b5e0a92cf73846cc5003d5e662302fd634"}

  };

} // CryptoNote


