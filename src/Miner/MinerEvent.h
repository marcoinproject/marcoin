// Copyright (c) 2012-2017, The CryptoNote developers, The Marcoin developers
// Copyright (c) 2018, The Marcoin Developers
//
// Please see the included LICENSE file for more information.

#pragma once

namespace Miner
{
    enum class MinerEventType: uint8_t
    {
        BLOCK_MINED,
        BLOCKCHAIN_UPDATED,
    };

    struct MinerEvent
    {
        MinerEventType type;
    };
}
