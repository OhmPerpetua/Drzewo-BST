#include "FileHandler.h"
#include <fstream>

void FileHandler::saveBinary(const BST& tree, const std::string& filename) {
    // Implementacja zapisu binarnego drzewa
}

void FileHandler::loadBinary(BST& tree, const std::string& filename) {
    // Implementacja odczytu binarnego drzewa
}

void FileHandler::loadText(BST& tree, const std::string& filename) {
    std::ifstream file(filename);
    int value;
    while (file >> value) {
        tree.insert(value);
    }
}