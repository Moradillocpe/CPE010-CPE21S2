#include <iostream>
#include "sortingAlgo.h"
 
const int maxSize = 15;
 
void displayArr(int arr[]);
 
int main(){
 
    //create an array with unsorted list
    int unsortedArr[maxSize] ={4, 34, 29, 48, 53, 87, 12, 30, 44, 25, 93, 67, 43, 19,74};

    std::cout<< "Merge Sort\n";
 
    std::cout << "Unsorted Array:\n";
    //display the randomly generated arr
    displayArr(unsortedArr);

 
    std::cout << "\nSorted Array :\n";
    displayArr(unsortedArr);
    
    std::cout<<std::endl;
 
    //reset the array back to its original unsorted order before testing
    //quick sort, since unsortedArr is already sorted from merge sort above
    int unsortedArr2[maxSize] ={4, 34, 29, 48, 53, 87, 12, 30, 44, 25, 93, 67, 43, 19,74};

    std::cout<< "\nQuick Sort";
 
    std::cout << "\nUnsorted Array:\n";
    displayArr(unsortedArr2);
   
 
    std::cout << "\nSorted Array :\n";
    displayArr(unsortedArr2);
 
    return 0;
}
 
void displayArr(int arr[]){
    for(int i = 0; i < maxSize; i++){
        std::cout << arr[i] << " ";
        if ((i%10) == 9){
            std::cout << '\n';
        }
    }
}


