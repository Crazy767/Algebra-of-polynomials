#include "Core/avl_tree/AVLTree.h"
#include "Tables/interface_table/ITable.h"

template <class TKey, class TValue>
class AVLTreeTable : public Table<TKey, TValue> {
    AVLTree<TableNode<TKey, TValue>> tree;
public:
    void add(const TKey key, const TValue value) override {
        TableNode<TKey, TValue> node(key, value);
        tree.insert(node);
    }

    void remove(TKey key) override {
        TableNode<TKey, TValue> node(key);
        tree.remove(node);
    }

    bool contains(TKey key) override {
        TableNode<TKey, TValue> node(key);
        return tree.search(node) != nullptr;
    }

    TValue get(TKey key) override {
        TableNode<TKey, TValue> node(key);
        BNode<TableNode<TKey, TValue>>* result = tree.search(node);
        if (result != nullptr) {
            return result->data.value;
        }
        else {
            throw std::out_of_range("Key not found");
        }
    }

    CList<TableNode<TKey, TValue>>& getAll() override {
        return tree.getAll();
    }

    void clear() override {
        tree.clear();
    }
};