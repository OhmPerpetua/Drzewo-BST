#include "BST.h"

BST::BST() : root(nullptr) {}

BST::~BST() {
    clear();
}

void BST::insert(int value) {
    insert(root, value);
}

void BST::insert(Node*& node, int value) {
    if (!node) {
        node = new Node(value);
    }
    else if (value < node->data) {
        insert(node->left, value);
    }
    else {
        insert(node->right, value);
    }
}

void BST::remove(int value) {
    remove(root, value);
}

void BST::remove(Node*& node, int value) {
    if (!node) return;

    if (value < node->data) {
        remove(node->left, value);
    }
    else if (value > node->data) {
        remove(node->right, value);
    }
    else {
        // Found the node to be removed
        if (!node->left) {
            Node* temp = node->right;
            delete node;
            node = temp;
        }
        else if (!node->right) {
            Node* temp = node->left;
            delete node;
            node = temp;
        }
        else {
            // Node with two children
            Node* temp = node->right;
            while (temp->left) {
                temp = temp->left;
            }
            node->data = temp->data;
            remove(node->right, temp->data);
        }
    }
}

void BST::clear() {
    clear(root);
}

void BST::clear(Node*& node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
        node = nullptr;
    }
}

void BST::findPath(int value) {
    std::vector<int> path;
    findPath(root, value, path);
    for (int v : path) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

void BST::findPath(Node* node, int value, std::vector<int>& path) {
    if (!node) return;
    path.push_back(node->data);
    if (node->data == value) return;
    if (value < node->data) {
        findPath(node->left, value, path);
    }
    else {
        findPath(node->right, value, path);
    }
}

void BST::displayPreorder() {
    displayPreorder(root);
    std::cout << std::endl;
}

void BST::displayPreorder(Node* node) {
    if (!node) return;
    std::cout << node->data << " ";
    displayPreorder(node->left);
    displayPreorder(node->right);
}

void BST::displayInorder() {
    displayInorder(root);
    std::cout << std::endl;
}

void BST::displayInorder(Node* node) {
    if (!node) return;
    displayInorder(node->left);
    std::cout << node->data << " ";
    displayInorder(node->right);
}

void BST::displayPostorder() {
    displayPostorder(root);
    std::cout << std::endl;
}

void BST::displayPostorder(Node* node) {
    if (!node) return;
    displayPostorder(node->left);
    displayPostorder(node->right);
    std::cout << node->data << " ";
}

void BST::saveToTextFile(const std::string& filename) {
    std::ofstream file(filename);
    saveToTextFile(root, file);
    file.close();
}

void BST::saveToTextFile(Node* node, std::ofstream& file) {
    if (!node) return;
    file << node->data << " ";
    saveToTextFile(node->left, file);
    saveToTextFile(node->right, file);
}
