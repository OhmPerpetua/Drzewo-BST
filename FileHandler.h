#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "BST.h"
#include <string>

class FileHandler {
public:
    void saveToBinaryFile (BST& bst, const std::string& filename);
    void loadFromBinaryFile (BST& bst, const std::string& filename);
    void loadFromTextFile (BST& bst, const std::string& filename);
};

#endif
