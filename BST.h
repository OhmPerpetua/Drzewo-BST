#ifndef BST_H
#define BST_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;
    void insert(Node*& node, int value);
    void remove(Node*& node, int value);
    void clear(Node*& node);
    void findPath(Node* node, int value, std::vector<int>& path);
    void displayPreorder(Node* node);
    void displayInorder(Node* node);
    void displayPostorder(Node* node);
    void saveToTextFile(Node* node, std::ofstream& file);

    friend class FileHandler;

public:
    BST();
    ~BST();
    void insert(int value);
    void remove(int value);
    void clear();
    void findPath(int value);
    void displayPreorder();
    void displayInorder();
    void displayPostorder();
    void saveToTextFile(const std::string& filename);
};

#endif // BST_H
