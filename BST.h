#ifndef BST_H
#define BST_H

#include "Node.h"

class BST {
public:
    BST();
    ~BST();

    void insert(int value);
    void remove(int value);
    void clear();
    Node* search(int value);
    void display(int order);
    void saveToFile(const std::string& filename);

private:
    Node* root;

    Node* insert(Node* node, int value);
    Node* remove(Node* node, int value);
    void clear(Node* node);
    Node* search(Node* node, int value);
    void displayPreorder(Node* node);
    void displayInorder(Node* node);
    void displayPostorder(Node* node);
    void saveToFile(Node* node, std::ofstream& file);
};

#endif