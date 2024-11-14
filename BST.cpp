#include "BST.h"
#include <iostream>
#include <fstream>

BST::BST() : root(nullptr) {}

BST::~BST() {
    clear();
}

void BST::insert(int value) {
    root = insert(root, value);
}

Node* BST::insert(Node* node, int value) {
    if (!node) return new Node(value);
    if (value < node->data) node->left = insert(node->left, value);
    else node->right = insert(node->right, value);
    return node;
}

void BST::remove(int value) {
    root = remove(root, value);
}

Node* BST::remove(Node* node, int value) {
    if (!node) return node;
    if (value < node->data) node->left = remove(node->left, value);
    else if (value > node->data) node->right = remove(node->right, value);
    else {
        if (!node->left) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (!node->right) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* temp = node->right;
        while (temp && temp->left) temp = temp->left;
        node->data = temp->data;
        node->right = remove(node->right, temp->data);
    }
    return node;
}

void BST::clear() {
    clear(root);
    root = nullptr;
}

void BST::clear(Node* node) {
    if (!node) return;
    clear(node->left);
    clear(node->right);
    delete node;
}

Node* BST::search(int value) {
    return search(root, value);
}

Node* BST::search(Node* node, int value) {
    if (!node || node->data == value) return node;
    if (value < node->data) return search(node->left, value);
    else return search(node->right, value);
}

void BST::display(int order) {
    switch (order) {
    case 1: displayPreorder(root); break;
    case 2: displayInorder(root); break;
    case 3: displayPostorder(root); break;
    }
    std::cout << std::endl;
}

void BST::displayPreorder(Node* node) {
    if (!node) return;
    std::cout << node->data << " ";
    displayPreorder(node->left);
    displayPreorder(node->right);
}

void BST::displayInorder(Node* node) {
    if (!node) return;
    displayInorder(node->left);
    std::cout << node->data << " ";
    displayInorder(node->right);
}

void BST::displayPostorder(Node* node) {
    if (!node) return;
    displayPostorder(node->left);
    displayPostorder(node->right);
    std::cout << node->data << " ";
}

void BST::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        saveToFile(root, file);
        file.close();
    }
}

void BST::saveToFile(Node* node, std::ofstream& file) {
    if (!node) return;
    file << node->data << " ";
    saveToFile(node->left, file);
    saveToFile(node->right, file);
}