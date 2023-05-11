//#include "Tables/avl_tree_table/AVLTreeTable.h"
#include "Tables/linear_array_table/linear_array_table.h"
#include "Tables/hash_chain_table/hash_chain_table.h"
using namespace std;

int main()
{
	//AVLTreeTable<std::string, Polynomial> t;

	CList<TableNode<std::string, Polynomial>> list;
	CList<Monomial> listm;
	Monomial m("1 1 1 1"), m2("1 2 3 4");
	listm.push_back(m);
	listm.push_back(m2);
	Polynomial p(listm);
	list.push_back(TableNode<std::string, Polynomial>("sdf", p));

	//AVLTree<int> tt;
	//tt.insert(10);
	//tt.insert(20);
	//tt.insert(30);
	//tt.insert(5);

	//tt.remove(5);
	//for (auto i : list) {
	//	std::cout << i << " ";
	//}
	//
	//for (auto i : list) {
	//	std::cout << i << " ";
	//}

	HashChainTable<std::string, Polynomial> hct;

	hct.add("asd", p);
	hct.remove("asd");
	hct.getAll();
}
