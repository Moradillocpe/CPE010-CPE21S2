#include<iostream>
using namespace std;

int main(){
    int quiz1, quiz2,quiz3;
    int total, avg;

    cout << " ENTER THE SCORE OF QUIZ 1: ";
    cin >> quiz1;
    cout << " ENTER THE SCORE OF QUIZ 2: ";
    cin >> quiz2;
    cout << " ENTER THE SCORE OF QUIZ 3: ";
    cin >> quiz3;

    total = quiz1 + quiz2 + quiz3;
    avg = total/ 3;

    cout << "The total of the quiz scores: " << total <<endl;
    cout << " The average of the quiz scores: " << avg;

return 0;
} 