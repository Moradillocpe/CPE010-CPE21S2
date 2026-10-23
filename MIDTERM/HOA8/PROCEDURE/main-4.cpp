#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingAlgo.h"

const int maxSize = 100;
void displayArr(int arr[]);



int main(){

    //create an array with unsorted list
    int unsortedArr[maxSize];
    //use time (0) as seed for random values
    srand(time(0));
    //populate the array with random values
    for(int i = 0; i < maxSize; i++){
        unsortedArr[i] = rand() % 500; //random values between 0 and 499
    }
    //display the randomly generated array
    std::cout<<"unsorted array: "<<std::endl;
    displayArr(unsortedArr);

    std::cout<<"shell sort: "<<std::endl;
    shellSort(unsortedArr, maxSize);
    displayArr(unsortedArr);

    std::cout<<"merge sort: "<<std::endl;
    mergeSort(unsortedArr, 0, maxSize - 1);
    displayArr(unsortedArr);

    std::cout<<"quick sort: "<<std::endl;
    quickSort(unsortedArr, 0, maxSize - 1);
    displayArr(unsortedArr);

}

void displayArr(int arr[]){
    for (int i = 0; i < maxSize; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

}