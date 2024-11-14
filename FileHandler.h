#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "BST.h"

class FileHandler {
public:
    static void saveBinary(const BST& tree, const std::string& filename);
    static void loadBinary(BST& tree, const std::string& filename);
    static void loadText(BST& tree, const std::string& filename);
};

#endif