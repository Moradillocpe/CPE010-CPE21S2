#include <iostream>
#include "BST.h"

int main(){

    //create the root node
    BinarySearchTree<int> tree(2);

    tree.insert(3);
    tree.insert(9);
    tree.insert(18);
    tree.insert(0);
    tree.insert(1);
    tree.insert(4);
    tree.insert(5);

    
    std::cout << "PreOrder : ";
    tree.preOrder();
    std::cout << std::endl;

    std::cout << "InOrder : ";
    tree.InOrder();
    std::cout << std::endl;

    std::cout <<"PostOrder: " ;
    tree.PostOrder();
    std::cout << std::endl;

    return 0;
}


