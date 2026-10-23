#ifndef SORTALGORITHMS_H
#define SORTALGORITHMS_H

#include<iostream>


template <typename T>
void shellSort(T arr[], size_t arrSize){
    //step1: start with a gap of arrSize/2 and halve it each pass until gap = 0
    for (int gap = arrSize/2; gap > 0; gap /= 2){
        //step2: for each element from gap to arrSize-1, insertion-sort it
        //       against the elements that are "gap" apart
        for (int i = gap; i < arrSize; i++){
            T temp = arr[i];
            int j = i;
            //step3: shift elements greater than temp to the right by "gap"
            for (; j >= gap && arr[j-gap] > temp; j -= gap){
                arr[j] = arr[j-gap];
            }
            arr[j] = temp;
        }
    }
}


template <typename T>
void mergeSort(T arr[], int left, int right){
    //step1: base case, a sub list of 0 or 1 elements is already sorted
    if (left < right){
        int mid = left + (right - left)/2;
        //step2: sort the left half and right half recursively
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
 
        //step3: merge the two sorted halves back together
        int leftSize = mid - left + 1;
        int rightSize = right - mid;
 
        T* leftArr = new T[leftSize];
        T* rightArr = new T[rightSize];
 
        for (int i = 0; i < leftSize; i++) leftArr[i] = arr[left+i];
        for (int j = 0; j < rightSize; j++) rightArr[j] = arr[mid+1+j];
 
        int i = 0, j = 0, K = left;
        //repeatedly place the smaller of the two front elements back into arr
        for (; i < leftSize && j < rightSize; K++){
            if (leftArr[i] <= rightArr[j]){
                arr[K] = leftArr[i];
                i++;
            } else {
                arr[K] = rightArr[j];
                j++;
            }
        }
        //copy over any leftover elements
        for (; i < leftSize; i++, K++) arr[K] = leftArr[i];
        for (; j < rightSize; j++, K++) arr[K] = rightArr[j];
 
        delete[] leftArr;
        delete[] rightArr;
    }
}



template <typename T>
//array, low index, high index -> returns the pivot's final sorted position
int pivot(T arr[], int low, int high){
    T pivot = arr[high];
    int i = low - 1;
    //step1: move elements smaller than the pivot to the left side
    for (int j = low; j < high; j++){
        if (arr[j] < pivot){
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    //step2: place the pivot in its correct sorted position
    std::swap(arr[i+1], arr[high]);
    return i+1;
}

template <typename T>
void quickSort(T arr[], int low, int high){
    if (low < high){
        int pivotPos = pivot(arr, low, high);
        //step: sort the left sub list and right sub list independently
        quickSort(arr, low, pivotPos - 1);
        quickSort(arr, pivotPos + 1, high);
    }
}

#endif