#include "FileHandler.h"
#include "BST.h"
#include <fstream>
#include <functional>
#include <iostream>

void FileHandler::saveToBinaryFile(BST& bst, const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }

    // Save tree to binary file (preorder traversal)
    std::function<void(Node*)> saveNode = [&file, &saveNode](Node* node) {
        if (!node) return;
        file.write(reinterpret_cast<char*>(&node->data), sizeof(node->data));
        saveNode(node->left);
        saveNode(node->right);
        };

    saveNode(bst.root);
    file.close();
}

void FileHandler::loadFromBinaryFile(BST& bst, const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error opening file for reading: " << filename << std::endl;
        return;
    }

    // Load tree from binary file
    bst.clear();
    std::function<Node* ()> loadNode = [&file, &loadNode]() -> Node* {
        int data;
        if (!file.read(reinterpret_cast<char*>(&data), sizeof(data))) {
            return nullptr;
        }
        Node* node = new Node(data);
        node->left = loadNode();
        node->right = loadNode();
        return node;
        };

    bst.root = loadNode();
    file.close();
}

void FileHandler::loadFromTextFile(BST& bst, const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file for reading: " << filename << std::endl;
        return;
    }

    bst.clear();
    int value;
    while (file >> value) {
        bst.insert(value);
    }
    file.close();
}
