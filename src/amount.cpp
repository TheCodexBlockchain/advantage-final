// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2017-2019 The PIVX developers
// Copyright (c) 2021-2022 The DECENOMY Core Developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "amount.h"

#include "tinyformat.h"

const std::string CURRENCY_UNIT = "__USDX__";

CFeeRate::CFeeRate(const CAmount& nFeePaid, size_t nSize)
{
    // New fee rate as a percentage of the transaction amount
    double newFeeRate = 0.0395;

    // Calculate the new fee in satoshis per kilobyte
    nSatoshisPerK = (nSize > 0) ? (nFeePaid * newFeeRate) / (nSize / 1000) : 0;
}

CAmount CFeeRate::GetFee(size_t nSize) const
{
    // New fee rate as a percentage of the transaction amount
    double newFeeRate = 0.0395;
    CAmount newFee = (nSize * nSatoshisPerK * 1000 * newFeeRate) / 100;
    // Return the new fee, but no less than the original fee rate
    return (newFee > 0) ? newFee : nSatoshisPerK;
}

std::string CFeeRate::ToString() const
{
    return strprintf("%d.%08d %s/kB", nSatoshisPerK / COIN, nSatoshisPerK % COIN, CURRENCY_UNIT);
}
