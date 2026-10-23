#include <iostream>
#include <cstdlib> //for generating random integers
#include <time.h>  //will be used for our seeding function
#include "searchingAlgo.h"

const int max_size = 50;

int main() {

    int dataset[max_size];
    srand(time(0));
    for (int i = 0; i < max_size; i++) {
        dataset[i] = rand();
    }

    std::cout << "Generated dataset:\n";
    for (int i = 0; i < max_size; i++) {
        std::cout << dataset[i] << " ";
    }
    std::cout << "\n\n";


    std::cout << "What number to find: ";
    int choice;
    std::cin >> choice;
    linearSearchAR(max_size, choice, dataset);
    std::cout << "\n";


    Node<char> *char1 = new_node('J');
    Node<char> *char2 = new_node('I');
    Node<char> *char3 = new_node('M');
    Node<char> *char4 = new_node('L');
    Node<char> *char5 = new_node('O');
    Node<char> *char6 = new_node('R');
    Node<char> *char7 = new_node('D');

    char1->next = char2;
    char2->next = char3;
    char3->next = char4;
    char4->next = char5;
    char5->next = char6;
    char6->next = char7;
    char7->next = nullptr;

    linearSearchLL(char1, 'D');
    std::cout << "\n";


    const int arrSize = 10;
    int sortedArr[arrSize];
    for (int i = 0; i < arrSize; i++) {
        sortedArr[i] = i; // already sorted: 0,1,2,...,9
    }

    std::cout << "Sorted array: ";
    for (int i = 0; i < arrSize; i++) {
        std::cout << sortedArr[i] << " ";
    }
    std::cout << "\n";

    std::cout << "-- Searching for 5 (exists) --\n";
    binarySearchArr(sortedArr, arrSize, 5);

    std::cout << "\n-- Searching for 100 (does not exist) --\n";
    binarySearchArr(sortedArr, arrSize, 100);
    std::cout << "\n";




    Node<int> *n1 = new_node(2);
    Node<int> *n2 = new_node(4);
    Node<int> *n3 = new_node(6);
    Node<int> *n4 = new_node(8);
    Node<int> *n5 = new_node(10);
    Node<int> *n6 = new_node(12);
    Node<int> *n7 = new_node(14);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = nullptr;

    std::cout << "-- Searching for 8 (exists) --\n";
    binarySearchLL(n1, 8);

    std::cout << "\n-- Searching for 20 (does not exist) --\n";
    binarySearchLL(n1, 20);

    return 0;
}