#ifndef SORTINGALGO_H
#define SORTINGALGO_H

//
template <typename T>
void bubbbleSort(T arr[], size_t arrSize){
    //step1: for i = 0 to N-1 repeat inner loop
    for (int i = 0 ; i < arrSize; i++){
        // step 2 inner loop that for k = i+1 to N-1 repeat step 3
            for(int j= i+1; j < arrSize; j++){
            //step 3:swap if arr[j > arr[i]
            if(arr[i]> arr[j]){
                // swap arr[i] and arr[j]
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

template <typename T>
//array, current position, size of array
int routineSmallest(T arr[], int K, const int arrSize){
    int position;
    T smallestElem = arr[K];

  for (int j = K+1; j< arrSize; j++){
    if(arr[j] < smallestElem){
        smallestElem = arr[j];
        position = j;
    }
  }
  return position;
}

template <typename T>
void selectionSort(T arr[], size_t arrSize){
    int POS, temp, pass;
    for (int i= 0; i < arrSize; i++){
        POS = routineSmallest(arr, i, arrSize);
        //swapping: 
        temp = arr[i];
        arr[i] = arr[POS];
        arr[POS] = temp;
        //for verification and counting of number of passes that was done
        pass++;
    }

}

template <typename T>
void insertionSort(T arr[], size_t arrSize){
    int pass = 0;
    for (int K = 1; K < arrSize; K++){
        T temp = arr[K];
        int J = K - 1;

        for (; J >= 0 && temp <= arr[J]; J--){
            arr[J+1] = arr[J];
        }

        arr[J+1] = temp;
        pass++; //finished placing arr[K], count it as one pass
    }
    std::cout << "number of passes: " << pass << std::endl;
}



#endif