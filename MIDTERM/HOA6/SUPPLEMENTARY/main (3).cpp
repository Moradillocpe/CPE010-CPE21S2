#include <iostream>
#include "node.h"
#include "searchingAlgo.h"

int main() {
   
    int p1_data[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int p1_size = 10;
    int p1_key = 18;

    // Display the Array list
    std::cout << "Array List: [";
    for (int i = 0; i < p1_size; i++) {
        std::cout << p1_data[i] << (i < p1_size - 1 ? ", " : "");
    }
    std::cout << "]\n";

    int arrComps = linearSearchARCount(p1_size, p1_key, p1_data);
    std::cout << "Array Comparisons needed to find key " << p1_key << ": " << arrComps << "\n";

    // Build and display the Linked List
    Node<int> *head = new_node(p1_data[0]);
    Node<int> *curr = head;
    for (int i = 1; i < p1_size; i++) {
        curr->next = new_node(p1_data[i]);
        curr = curr->next;
    }

    std::cout << "Linked List: ";
    Node<int> *temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << (temp->next != nullptr ? " -> " : "");
        temp = temp->next;
    }
    std::cout << "\n";

    int llComps = linearSearchLLCount(head, p1_key);
    std::cout << "Linked List Comparisons needed to find key " << p1_key << ": " << llComps << "\n";





    int k = 18;
    int occurrences = countOccurrences(p1_size, k, p1_data);
    std::cout << "Count of repeating instances for '" << k << "': " << occurrences << "\n";

   




    int p3_data[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int p3_size = 10;
    int p3_key = 8;

    int p3_index = binarySearchArrTrace(p3_data, p3_size, p3_key);
    std::cout << "Found at index: " << p3_index << "\n";




    int p4_index = recursiveBinarySearch(p3_data, 0, p3_size - 1, p3_key);
    std::cout << "Found at index: " << p4_index << "\n";

    return 0;
}


