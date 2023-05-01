#include <iostream>
#include "AVLTree.h"

using namespace std;

int main() {
    AVLTree<int> tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    cout << "AVL Tree after inserting 10, 20, 30, 40, 50, 25:" << endl;
    tree.printTree();

    tree.insert(60);
    tree.insert(70);
    tree.insert(80);
    tree.insert(90);

    cout << "\nAVL Tree after inserting 60, 70, 80, 90:" << endl;
    tree.printTree();

    return 0;
}
