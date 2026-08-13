#include <iostream>
#include "queueLL.h"

int main() {

    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;

    std::cout << "======================================\n";
    std::cout << "           QUEUE OPERATIONS           \n";
    std::cout << "======================================\n";
    std::cout << "[ Enqueuing letters: E U N I C E ]\n";
    enqueue('E', &front, &back);
    enqueue('U', &front, &back);
    enqueue('N', &front, &back);
    enqueue('I', &front, &back);
    enqueue('C', &front, &back);
    enqueue('E', &front, &back);
    std::cout << "Current Queue:\n";
    displayALL(&front, &back);
    std::cout << "   Front -> " << front->data << std::endl;
    std::cout << "   Back  -> " << back->data << std::endl;
    std::cout << "   Empty? " << (isEmpty(&front, &back) ? "Yes" : "No") << std::endl;

    std::cout << "-------------------------------------\n";
    std::cout << "         DEQUEUING ELEMENTS           \n";
    std::cout << "--------------------------------------\n";

 dequeue(&front, &back);
    displayALL(&front, &back);

    dequeue(&front, &back);
    displayALL(&front, &back);

    dequeue(&front, &back);
    displayALL(&front, &back);

    dequeue(&front, &back);
    displayALL(&front, &back);

    dequeue(&front, &back);
    displayALL(&front, &back);

    std::cout << "\nIs Empty? " << (isEmpty(&front, &back) ? "Yes" : "No") << std::endl;

    // Test dequeue on empty queue
    dequeue(&front, &back);

    return 0;
}

