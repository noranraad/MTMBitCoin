//
// Created by Noran on 5/31/2026.
//
#include "Utilities.h"
#include "Transaction.h"
#include "BlockChain.h"
#include "iostream"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cerr << getErrorMessage() << std::endl;
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

    else if (op == "hash") {
        ifstream sourceFile(argv[2]);
        ofstream targetFile(argv[3]);

        BlockChain b = BlockChainLoad(sourceFile);
        BlockChainDumpHashed(b,targetFile);
        BlockChainDestroy(b);
    }

    else if (op == "compress") {
        ifstream sourceFile(argv[2]);
        ofstream targetFile(argv[3]);

        BlockChain b = BlockChainLoad(sourceFile);
        BlockChainCompress(b);
        BlockChainDump(b,targetFile);
        BlockChainDestroy(b);
    }

    else if (op == "verify") {
        ifstream sourceFile(argv[2]);
        ifstream targetFile(argv[3]);

        BlockChain b = BlockChainLoad(sourceFile);

        if (!BlockChainVerifyFile(b, targetFile)) {
            std::cout << "Verification failed" << std::endl;
        } else {
            std::cout << "Verification passed" << std::endl;
        }

        BlockChainDestroy(b);
    }

    else {
        std::cerr << getErrorMessage() << std::endl;
    }

    return 0;
}
