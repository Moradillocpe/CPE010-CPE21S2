#include "node.h"

#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

template <typename T>
void linearSearchAR(int size, T dataFind,T array[]){

    //while loop
    int i = 0;

    while(i < size){
        if(dataFind == array[i]){
            std::cout<<"Searching is successful\n";
            return;
        }
        i++;
    }
    std::cout<<"Searching is unsuccessful\n";

    //for loopp
    for(int j = 0; j < size; j++){
        if(dataFind == array[j]){
             std::cout<<"Searching is successful\n";
             return;
        }
    }
    std::cout<<"Searching is unsuccessful\n";
} 

template <typename T>
void linearSearchLL(Node<T> *nodes, T dataFind){
    //repeat the loop until the the current node is not null

    while(nodes != nullptr){
        //checks if the item - current node data
        if(nodes->data  == dataFind){
            std::cout << "The data: "<< nodes->data<< " was found successfully.\n";
            return;
        }
        //move on to the next node
        nodes = nodes->next;
    }
    //display unsucessfull
    std::cout << "Searching is unsucessful.\n";
}

template <typename T>
void binarySearchArr(T array[], int arrSize, T dataFind){
    //set the boundaries of the search
    int low = 0;
    int high = arrSize - 1;
    int middle;

    while(low <= high){
        //get the middle index
        middle = (int)((low + high) / 2);

        //checks if the item = middle element
        if(dataFind == array[middle]){
            std::cout << "Searching is successful\n";
            return;
        }
        //if item is smaller, search the left half
        else if(dataFind < array[middle]){
            high = middle - 1;
        }
        //if item is bigger, search the right half
        else{
            low = middle + 1;
        }
    }
    std::cout << "Searching is unsuccessful\n";
}

template <typename T>
Node<T>* getMiddle(Node<T> *start, Node<T> *last){
    //slow moves 1 node at a time, fast moves 2 nodes at a time
    Node<T> *slow = start;
    Node<T> *fast = start;

    while(fast != last && fast->next != last){
        slow = slow->next;
        fast = fast->next->next;
    }
    //when fast reaches the end, slow is at the middle
    return slow;
}

template <typename T>
void binarySearchLL(Node<T> *start, T dataFind){
    Node<T> *last = nullptr;

    while(start != last){
        //find the middle node between start and last
        Node<T> *middle = getMiddle(start, last);

        //checks if the item = middle node data
        if(middle->data == dataFind){
            std::cout << "Searching is successful\n";
            return;
        }
        //if item is smaller, search the left half
        else if(middle->data > dataFind){
            last = middle;
        }
        //if item is bigger, search the right half
        else{
            start = middle->next;
        }
    }
    std::cout << "Searching is unsuccessful\n";
}

#endif