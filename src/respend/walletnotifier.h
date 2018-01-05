// Copyright (c) 2018 The Bitcoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef BITCOIN_RESPEND_WALLETNOTIFYER_H
#define BITCOIN_RESPEND_WALLETNOTIFYER_H

#include "respend/respendaction.h"
#include "primitives/transaction.h"

namespace respend {

// Notifies the wallet of a potentially conflicting double spend.
class WalletNotifier : public RespendAction {
    public:
        WalletNotifier();

        bool AddOutpointConflict(
                const COutPoint&, const CTransaction* originalTx,
                const CTransaction& respendTx,
                bool seenBefore, bool isEquivalent) override;

        bool IsInteresting() const override;
        void SetValid(bool v) override;
        void Trigger() override;

    private:
        CTransaction respendTx;
        bool valid;
        bool interesting;
};

} // ns respend

#endif
