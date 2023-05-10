#include "base.h"
#include "Core/clist/CList.h"
using namespace std;

template <class T>
class BNode {
public:
    BNode() : left(nullptr), right(nullptr) {}
    BNode(const T& data) : data(data), left(nullptr), right(nullptr), height(1) {}
    T data;
    BNode<T>* left;
    BNode<T>* right;
    int height;
};

template <class T>
class BinaryTree {
protected:
    BNode<T>* root;

public:
    BinaryTree() : root(nullptr) {}

    void insert(T data) {
        insert(root, data);
    }

    BNode<T>* search(T data) {
        return search(root, data);
    }

    void printTree() {
        printTree(root, "");
    }

    void clear() {
        clear(root);
        root = nullptr;
    }

    CList<T>& getAll() {
        CList<T> result;
        getAll(root, result);
        return result;
    }

protected:
    void insert(BNode<T>* node, T data) {
        if (!node) {
            node = new BNode<T>(data);
            return;
        }

        if (data < node->data) {
            insert(node->left, data);
        }
        else if (data > node->data) {
            insert(node->right, data);
        }
    }

    BNode<T>* search(BNode<T>* node, T data) {
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

    void printTree(BNode<T>* node, string prefix) {
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

    void clear(BNode<T>* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }


    void getAll(BNode<T>* node, CList<T>& result) {
        if (!node) {
            return;
        }
        getAll(node->left, result);
        result.push_back(node->data);
        getAll(node->right, result);
    }

};

template <class T>
class AVLTree : public BinaryTree<T> {
public:
    AVLTree() : BinaryTree<T>() {}

    void insert(T data) {
        this->root = insert(this->root, data);
    }

    void remove(T data) {
        this->root = remove(this->root, data);
    }

private:
    BNode<T>* insert(BNode<T>* node, T data) {
        if (!node) {
            return new BNode<T>(data);
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

        node = updateBNode(node);
        return balance(node, data);
    }

    BNode<T>* remove(BNode<T>* node, T data) {
        if (!node) {
            return nullptr;
        }

        if (data < node->data) {
            node->left = remove(node->left, data);
        }
        else if (data > node->data) {
            node->right = remove(node->right, data);
        }
        else {
            if (!node->left || !node->right) {
                BNode<T>* temp = node->left ? node->left : node->right;

                if (!temp) {
                    temp = node;
                    node = nullptr;
                }
                else {
                    *node = *temp;
                }
                delete temp;
            }
            else {
                BNode<T>* temp = findMin(node->right);
                node->data = temp->data;
                node->right = remove(node->right, temp->data);
            }
        }

        if (!node) {
            return node;
        }

        node = updateBNode(node);
        return balanceBNode(node);
    }

    int getHeight(BNode<T>* node) {
        if (!node) {
            return 0;
        }
        return node->height;
    }

    int getBalanceFactor(BNode<T>* node) {
        if (!node) {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    BNode<T>* updateBNode(BNode<T>* node) {
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        return node;
    }

    BNode<T>* balance(BNode<T>* node, T data) {
        int balance_factor = getBalanceFactor(node);

        if (balance_factor > 1) {
            if (data > node->left->data) {
                node->left = rotateLeft(node->left);
            }
            return rotateRight(node);
        }
        if (balance_factor < -1) {
            if (data < node->right->data) {
                node->right = rotateRight(node->right);
            }
            return rotateLeft(node);
        }

        return node;
    }

    BNode<T>* balanceBNode(BNode<T>* node) {
        int balance_factor = getBalanceFactor(node);

        if (balance_factor > 1) {
            if (getBalanceFactor(node->left) < 0) {
                node->left = rotateLeft(node->left);
            }
            return rotateRight(node);
        }
        if (balance_factor < -1) {
            if (getBalanceFactor(node->right) > 0) {
                node->right = rotateRight(node->right);
            }
            return rotateLeft(node);
        }

        return node;
    }

    BNode<T>* rotateLeft(BNode<T>* x) {
        BNode<T>* y = x->right;
        BNode<T>* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    BNode<T>* rotateRight(BNode<T>* y) {
        BNode<T>* x = y->left;
        BNode<T>* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    BNode<T>* findMin(BNode<T>* node) {
        BNode<T>* current = node;

        while (current->left != nullptr)
            current = current->left;

        return current;
    }
};
