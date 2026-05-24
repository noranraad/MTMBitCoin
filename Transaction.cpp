//
// Created by Noran on 5/24/2026.
//
#include "Transaction.h"
#include "Utilities.h"


void TransactionDumpInfo(const Transaction& transaction, ofstream& file) {
    file << "Sender Name:" << " " << transaction.sender << std::endl;
    file << "Receiver Name:" << " " << transaction.receiver << std::endl;
    file << "Transaction Value:" << " " << transaction.value << std::endl;
}

string TransactionHashedMessage(const Transaction& transaction) {
    int const key = static_cast<int>(transaction.value);
    return hash(key,transaction.sender,transaction.receiver);
}

bool TransactionVerifyHashedMessage(
        const Transaction& transaction,
        string hashedMessage
) {
    string temp = TransactionHashedMessage(transaction);
    if (hashedMessage == temp) return true;
    return false;
}


