#include <iostream>
#include <queue>

void display(std::queue<char> copyQ);

int main(){
//create an object
std::queue<char> myQ;
//use the enqueue operation
myQ.push('E');
myQ.push('U');
myQ.push('N');
myQ.push('I');
std::cout<<"The current back is: "<<myQ.front()<<std::endl;
std::cout<<"The current back is: "<<myQ.back()<<std::endl;
display(myQ);
//use the dequeue operation
myQ.pop();
display(myQ);
myQ.pop();
display(myQ);
myQ.pop();
std::cout<<"After dequeue. the front is: "<<myQ.front()<<std::endl;
//check if queue empty
std::cout<<"is the queue empty? "<<myQ.empty()<<std::endl;
return 0;
}
//note only use the member functions of the queue STL
void display(std::queue<char> copyQ){
//create a copy of the queue
std::queue<char> temp = copyQ;
//loop until empty
while (!temp.empty()){
//display the front
std::cout<<" "<<temp.front()<<" ";
//display the back
temp.pop();
}
//add a new line
std::cout <<std::endl;
}

