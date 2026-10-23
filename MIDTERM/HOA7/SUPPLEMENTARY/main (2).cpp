#include <iostream>
#include <cstdlib>
#include<ctime>
#include <string>
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
        unsortedArr[i] = rand() % 100; //random values between 0 and 99
    }
    //display the randomly generated array
    std::cout<<"unsorted array: "<<std::endl;
    displayArr(unsortedArr);

  //  std::cout<<"bubble sort: "<<std::endl;
  //  bubbbleSort(unsortedArr, maxSize);
   // displayArr(unsortedArr);

 //  std::cout<<"selection sort: "<<std::endl;
// selectionSort(unsortedArr, maxSize);
  // displayArr(unsortedArr);

   std::cout<<"insertion sort: "<<std::endl;
    insertionSort(unsortedArr, maxSize);
    displayArr(unsortedArr);

    //---------- Supplementary Activity: Vote Counting ----------
    const int numCandidates = 5;
    std::string candidateNames[numCandidates + 1] = {
        "", //index 0 unused, candidates are numbered 1-5
        "Bo Dalton Capistrano",
        "Cornelius Raymon Agustin",
        "Deja Jayla Banaga",
        "Lalla Brielle Yabut",
        "Franklin Relano Castro"
    };

    //generate an array of 100 votes, values ranging from 1 to 5
    int votesArr[maxSize];
    for(int i = 0; i < maxSize; i++){
        votesArr[i] = (rand() % numCandidates) + 1; //random values between 1 and 5
    }

    std::cout<<"\nunsorted votes array: "<<std::endl;
    displayArr(votesArr);

    //sort the votes using insertion sort (prints number of passes internally)
    insertionSort(votesArr, maxSize);

    std::cout<<"sorted votes array: "<<std::endl;
    displayArr(votesArr);

    //since the array is sorted, tally each candidate's votes in a single pass
    int voteTally[numCandidates + 1] = {0};
    for(int i = 0; i < maxSize; i++){
        voteTally[votesArr[i]]++;
    }

    //determine the winning candidate
    int winner = 1;
    for(int c = 2; c <= numCandidates; c++){
        if(voteTally[c] > voteTally[winner]){
            winner = c;
        }
    }

    std::cout<<"\nvote count result: "<<std::endl;
    for(int c = 1; c <= numCandidates; c++){
        std::cout<<"Candidate "<<c<<" ("<<candidateNames[c]<<"): "<<voteTally[c]<<" votes"<<std::endl;
    }
    std::cout<<"\nwinning candidate: Candidate "<<winner<<" ("<<candidateNames[winner]<<") with "<<voteTally[winner]<<" votes"<<std::endl;

}

void displayArr(int arr[]){
    for (int i = 0; i < maxSize; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

}