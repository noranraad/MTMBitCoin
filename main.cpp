//
// Created by Noran on 5/31/2026.
//
#include "Utilities.h"
#include "Transaction.h"
#include "BlockChain.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        getErrorMessage();
        return 0;
    }

    string op = argv[1];

    if (op == "format") {
        ifstream sourceFile(argv[2]);
        ofstream targetFile(argv[3]);

        BlockChain b = BlockChainLoad(sourceFile);
        BlockChainDump(b,targetFile);
        BlockChainDestroy(b);
    }

    if (op == "hash") {
        
    }

    if (op == "compress"){}

    if (op == "verify"){}
}
