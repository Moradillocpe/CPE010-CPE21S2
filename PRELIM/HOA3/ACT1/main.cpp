#include <iostream>
#include "singly_ll.h"

int main() {
    //creation of nodes "3,I,M,Q" (in this run: C,P,E,1)

    //creating a node stored in the stack
    SingleList<char>* head = nullptr;
    SingleList<char>* second = nullptr;
    SingleList<char>* third = nullptr;
    SingleList<char>* fourth = nullptr;

    //allocates memory in the heap
    head = new SingleList<char>;
    second = new SingleList<char>;
    third = new SingleList<char>;
    fourth = new SingleList<char>;

    //storing a value inside the node
    head->data = 'C';
    second->data = 'P';
    third->data = 'E';
    fourth->data = '1';

    //linking the nodes:
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = nullptr;

    std::cout << "Testing Traversal\n";
    ListTraversal(head);

    std::cout << "Testing of sllInsertHead:\n";
    sllInsertHead('G', &head);
    ListTraversal(head);

    std::cout << "Testing of sllGeneralInsert:\n";
    sllGeneralInsert('E', head->next->next);
    ListTraversal(head);

    std::cout << "Testing of sllInsertEnd:\n";
    sllInsertEnd('0', &head);
    ListTraversal(head);

    std::cout << "Testing of deleting the node:\n";
    sllDeleteNode('C', &head);
    ListTraversal(head);
    sllDeleteNode('P', &head);
    ListTraversal(head);

    std::cout << "Deleting all node:\n";
    sllDeleteList(&head);
    ListTraversal(head);

    return 0;
}

