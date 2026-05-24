//
// Created by Noran on 5/24/2026.
//
#include "Transaction.h"
#include "Utilities.h"

void TransactionDumpInfo(const Transaction& transaction, ofstream& file) {
    file << "Sender Name:" << " " << transaction.sender;
    file << "Receiver Name:" << " " << transaction.receiver;
    file << "Transaction Value:" << " " << transaction.value;
}

string TransactionHashedMessage(const Transaction& transaction) {
    int key = static_cast<int>(transaction.value);
    return hash(key,transaction.sender,transaction.receiver);
}


