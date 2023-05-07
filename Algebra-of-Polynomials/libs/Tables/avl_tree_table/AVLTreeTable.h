#include "Core/avl_tree/AVLTree.h"
#include "Tables/interface_table/ITable.h"

using namespace std;

template <typename TKey, typename TValue, typename T>
class AVLTreeTable : public Table<TKey, TValue> {
	AVLTree<T> tree;
	int size();
public:
	virtual int insert(TKey key, TValue value);
	virtual int remove(TKey key);
	virtual TValue find(TKey key);
	virtual void print();
};