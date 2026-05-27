//
// Created by Noran on 5/24/2026.
//
#include "BlockChain.h"
#include "Utilities.h"
#include "Transaction.h"



BlockChain BlockChainInit(){
     BlockChain block;
    block.head = nullptr;
    return block;
}

void BlockChainDestroy(BlockChain& blockChain) {
        Block* curr = blockChain.head;
        while (blockChain.head != nullptr) {
                Block *toDelete = curr;
                delete toDelete;
                curr = curr -> next;
        }
        blockChain.head = nullptr;
}

int BlockChainGetSize(const BlockChain& blockChain) {
        Block *curr = blockChain.head;
        int cnt = 0;
        while (curr != nullptr) {
                cnt++;
                curr = curr -> next;
        }
        return cnt;
}

int BlockChainPersonalBalance(const BlockChain& blockChain, const string& name) {
        unsigned int balance = 0;
        while (blockChain.head != nullptr) {

                if (blockChain.head->t.sender != name)
                        balance-=blockChain.head->t.value;

                if (blockChain.head->t.receiver != name)
                        balance+=blockChain.head->t.value;

        }
        return static_cast<int>(balance);
}

void BlockChainAppendTransaction(
        BlockChain& blockChain,
        const Transaction& transaction,
        const string& timestamp
) {
        Block* newBlock = new Block;

        blockChain.head->t = transaction;
        blockChain.head->timestamp = timestamp;
        blockChain.head->next = blockChain.head;

        blockChain.head = newBlock;
}

void BlockChainAppendTransaction(
        BlockChain& blockChain,
        unsigned int value,
        const string& sender,
        const string& receiver,
        const string& timestamp
) {
        const Transaction tr = {value,sender,receiver};
        BlockChainAppendTransaction(blockChain,tr,timestamp);
}

BlockChain BlockChainLoad(ifstream& file) {
        BlockChain b = BlockChainInit();

        string sender;
        string receiver ;
        string stamp;
        unsigned int v;

        while (file >> sender >> receiver >> v >> stamp)
                BlockChainAppendTransaction(b,v, sender,receiver,stamp);

        return b;
}

void BlockChainDump(const BlockChain& blockChain, ofstream& file) {
        Block *curr = blockChain.head;
        int cnt = 1;
        while (curr != nullptr) {
                file << "BlockChain Info:" << std::endl
                << cnt << std::endl
                << "Sender Name: " << curr->t.sender << std::endl
                << "Receiver Name: " << curr->t.receiver << std::endl
                << "Transaction Value: " << curr->t.value << std::endl
                << "Transaction timestamp: " << curr->timestamp << std::endl;

                curr = curr->next;
                cnt++;
        }
}

void BlockChainDumpHashed(const BlockChain& blockChain, ofstream& file) {
        Block *curr = blockChain.head;
        while (curr != nullptr)
                file << TransactionHashedMessage(curr->t) << std::endl;
}

bool BlockChainVerifyFile(const BlockChain& blockChain, std::ifstream& file) {
        Block *curr = blockChain.head;
        string hashedCheck;
        while (curr != nullptr) {
                getline(file,hashedCheck);
                if (TransactionHashedMessage(curr->t) != hashedCheck) return false;
        }
        return true;
}

void BlockChainCompress(BlockChain& blockChain) {

}

void BlockChainTransform(BlockChain& blockChain, updateFunction function) {

}
