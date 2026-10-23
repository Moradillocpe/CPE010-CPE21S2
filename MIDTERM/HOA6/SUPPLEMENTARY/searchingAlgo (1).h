#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

#include <iostream>
#include "node.h"

// Standard Linear Search for Arrays
template <typename T>
void linearSearchAR(int size, T dataFind, T array[]) {
    for (int i = 0; i < size; i++) {
        if (dataFind == array[i]) {
            std::cout << "Searching is successful\n";
            return;
        }
    }
    std::cout << "Searching is unsuccessful\n";
}

// Standard Linear Search for Linked Lists
template <typename T>
void linearSearchLL(Node<T> *nodes, T dataFind) {
    while (nodes != nullptr) {
        if (nodes->data == dataFind) {
            std::cout << "The data: " << nodes->data << " was found successfully.\n";
            return;
        }
        nodes = nodes->next;
    }
    std::cout << "Searching is unsuccessful.\n";
}

// Problem 1: Linear Search for Array with Comparison Count
template <typename T>
int linearSearchARCount(int size, T dataFind, T array[]) {
    int comparisons = 0;
    for (int i = 0; i < size; i++) {
        comparisons++;
        if (array[i] == dataFind) {
            std::cout << "Searching is successful (Array)\n";
            return comparisons;
        }
    }
    std::cout << "Searching is unsuccessful (Array)\n";
    return comparisons;
}

// Problem 1: Linear Search for Linked List with Comparison Count
template <typename T>
int linearSearchLLCount(Node<T> *head, T dataFind) {
    int comparisons = 0;
    Node<T> *current = head;
    while (current != nullptr) {
        comparisons++;
        if (current->data == dataFind) {
            std::cout << "Searching is successful (Linked List)\n";
            return comparisons;
        }
        current = current->next;
    }
    std::cout << "Searching is unsuccessful (Linked List)\n";
    return comparisons;
}

// Problem 2: Modified Sequential Search to return repeating count
template <typename T>
int countOccurrences(int size, T k, T array[]) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] == k) {
            count++;
        }
    }
    return count;
}

// Problem 3: Standard Iterative Binary Search with Iteration Output
template <typename T>
int binarySearchArrTrace(T array[], int arrSize, T dataFind) {
    int low = 0;
    int high = arrSize - 1;
    int iteration = 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        std::cout << "Iteration " << iteration++ 
                  << ": low=" << low << ", high=" << high 
                  << ", mid=" << mid << " (val=" << array[mid] << ")\n";

        if (array[mid] == dataFind) {
            std::cout << "Searching is successful\n";
            return mid;
        } else if (dataFind < array[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    std::cout << "Searching is unsuccessful\n";
    return -1;
}

// Problem 4: Modified Recursive Binary Search
template <typename T>
int recursiveBinarySearch(T array[], int low, int high, T dataFind, int step = 1) {
    if (low > high) {
        std::cout << "Searching is unsuccessful\n";
        return -1;
    }

    int mid = low + (high - low) / 2;
    std::cout << "Step " << step 
              << ": low=" << low << ", high=" << high 
              << ", mid=" << mid << " (val=" << array[mid] << ")\n";

    if (array[mid] == dataFind) {
        std::cout << "Searching is successful\n";
        return mid;
    } else if (dataFind < array[mid]) {
        return recursiveBinarySearch(array, low, mid - 1, dataFind, step + 1);
    } else {
        return recursiveBinarySearch(array, mid + 1, high, dataFind, step + 1);
    }
}

// Helper functions for Linked List Binary Search
template <typename T>
Node<T>* getMiddle(Node<T> *start, Node<T> *last) {
    Node<T> *slow = start;
    Node<T> *fast = start;

    while (fast != last && fast->next != last) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

template <typename T>
void binarySearchLL(Node<T> *start, T dataFind) {
    Node<T> *last = nullptr;

    while (start != last) {
        Node<T> *middle = getMiddle(start, last);

        if (middle->data == dataFind) {
            std::cout << "Searching is successful\n";
            return;
        } else if (middle->data > dataFind) {
            last = middle;
        } else {
            start = middle->next;
        }
    }
    std::cout << "Searching is unsuccessful\n";
}

#endif