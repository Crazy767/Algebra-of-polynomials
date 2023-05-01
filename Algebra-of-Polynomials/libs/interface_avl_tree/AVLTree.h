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
    int height;

    Node(T data) : data(data), left(nullptr), right(nullptr), height(1) {}
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

protected:
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

    void printTree(Node<T>* node, string prefix) {
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

template <class T>
class AVLTree : public BinaryTree<T> {
public:
    AVLTree() : BinaryTree<T>() {}

    void insert(T data) {
        this->root = insert(this->root, data);
    }

private:
    Node<T>* insert(Node<T>* node, T data) {
        if (!node) {
            node = new Node<T>(data);
            return node;
        }

        if (data < node->data) {
            node->left = insert(node->left, data);
        }
        else if (data > node->data) {
            node->right = insert(node->right, data);
        }
        else {
            return node;
        }

        // Обновляем высоту текущего узла
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        // Получаем коэффициент баланса текущего узла
        int balance_factor = getBalanceFactor(node);

        // Если дерево стало несбалансированным, то есть разность высот поддеревьев больше 1, 
        // то выполняем соответствующий случай балансировки
        if (balance_factor > 1 && data < node->left->data) {
            // Случай левого левого
            return rotateRight(node);
        }
        else if (balance_factor < -1 && data > node->right->data) {
            // Случай правого правого
            return rotateLeft(node);
        }
        else if (balance_factor > 1 && data > node->left->data) {
            // Случай левого правого
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        else if (balance_factor < -1 && data < node->right->data) {
            // Случай правого левого
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    int getHeight(Node<T>* node) {
        if (!node) {
            return 0;
        }
        return node->height;
    }

    int getBalanceFactor(Node<T>* node) {
        if (!node) {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    Node<T>* rotateLeft(Node<T>* node) {
        Node<T>* new_root = node->right;
        Node<T>* subtree = new_root->left;

        // выполнить поворот
        new_root->left = node;
        node->right = subtree;

        // обновление высот узлов
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        new_root->height = 1 + max(getHeight(new_root->left), getHeight(new_root->right));

        return new_root;
    }

    Node<T>* rotateRight(Node<T>* node) {
        Node<T>* new_root = node->left;
        Node<T>* subtree = new_root->right;
        
        new_root->right = node;
        node->left = subtree;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        new_root->height = 1 + max(getHeight(new_root->left), getHeight(new_root->right));

        return new_root;
    }
};
