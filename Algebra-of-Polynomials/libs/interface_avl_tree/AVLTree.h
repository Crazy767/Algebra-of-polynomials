#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

template <class T>
class Node {
public:
    T data;
    Node<T>* left;
    Node<T>* right;

    Node(T data) : data(data), left(nullptr), right(nullptr) {}
};

template <class T>
class BinaryTree {
protected:
    Node<T>* root;

public:
    BinaryTree() : root(nullptr) {}

    void insert(T data) {
        insert(root, data);
    }

    Node<T>* search(T data) {
        return search(root, data);
    }

    void printTree() {
        printTree(root, "");
    }
private:
    void insert(Node<T>*& node, T data) {
        if (!node) {
            node = new Node<T>(data);
            return;
        }

        if (data < node->data) {
            insert(node->left, data);
        }
        else if (data > node->data) {
            insert(node->right, data);
        }
    }

    Node<T>* search(Node<T>* node, T data) {
        if (!node) {
            return nullptr;
        }

        if (node->data == data) {
            return node;
        }
        else if (data < node->data) {
            return search(node->left, data);
        }
        else {
            return search(node->right, data);
        }
    }

    void printTree(Node<string>* node, string prefix) {
        if (node == nullptr) {
            return;
        }

        bool has_left = (node->left != nullptr);
        bool has_right = (node->right != nullptr);

        if (!has_left && !has_right) {
            cout << prefix << "#~~" << node->data << endl;
            return;
        }

        cout << prefix;
        cout << "@~~";
        cout << node->data << endl;

        if (has_left) {
            printTree(node->left, prefix + (has_right ? "|  " : "   "));
        }

        if (has_right) {
            printTree(node->right, prefix + "|  ");
        }
    }
};