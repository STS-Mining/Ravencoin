// Copyright (c) 2015-2016 The Bitcoin Core developers
// Copyright (c) 2017-2019 The Raven Core developers
// Copyright (c) 2024-2025 The Memeium Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef MEMEIUM_ZMQ_ZMQNOTIFICATIONINTERFACE_H
#define MEMEIUM_ZMQ_ZMQNOTIFICATIONINTERFACE_H

#include "validationinterface.h"
#include <list>
#include <map>
#include <string>

class CBlockIndex;
class CZMQAbstractNotifier;

class CZMQNotificationInterface final : public CValidationInterface
{
public:
    virtual ~CZMQNotificationInterface();

    static CZMQNotificationInterface* Create();

protected:
    bool Initialize();
    void Shutdown();

    // CValidationInterface
    void TransactionAddedToMempool(const CTransactionRef& tx) override;
    void BlockConnected(const std::shared_ptr<const CBlock>& pblock, const CBlockIndex* pindexConnected, const std::vector<CTransactionRef>& vtxConflicted) override;
    void BlockDisconnected(const std::shared_ptr<const CBlock>& pblock) override;
    void UpdatedBlockTip(const CBlockIndex* pindexNew, const CBlockIndex* pindexFork, bool fInitialDownload) override;
    void NewAssetMessage(const CMessage& message) override;

private:
    CZMQNotificationInterface();

    void* pcontext;
    std::list<CZMQAbstractNotifier*> notifiers;
};

#endif // MEMEIUM_ZMQ_ZMQNOTIFICATIONINTERFACE_H
