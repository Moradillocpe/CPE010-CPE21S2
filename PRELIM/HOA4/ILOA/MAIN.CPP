#include <iostream>
#include <stack>

int main() {
    std::stack<int> stack1;
    std::cout << "\n --- STACK 1 --- " << std::endl;
    std::cout << "Testing the stack STL" << std::endl;

    //push
    std::cout << "is the stack empty? " << stack1.empty() << std::endl;

    stack1.push(10);
    std::cout << "the top of the stack is " << stack1.top() << std::endl;

    stack1.push(9);
    std::cout << "the top of the stack is " << stack1.top() << std::endl;

    stack1.push(7);
    std::cout << "the top of the stack is " << stack1.top() << std::endl;

    stack1.push(4);
    std::cout << "the top of the stack is " << stack1.top() << std::endl;

    stack1.push(3);
    std::cout << "the top of the stack is " << stack1.top() << std::endl;

    stack1.push(2);
    std::cout << "the top of the stack is " << stack1.top() << std::endl;

    stack1.pop();

    std::cout << "the top of the stack is " << stack1.top() << std::endl;

    std::cout << "is the stack empty? " << stack1.empty() << std::endl;

    std::cout << "the size of the stack is " << stack1.size() << std::endl;

    std::stack<int> stack2;
    std::cout << "\n ...- STACK 2 --- " << std::endl;

    stack2.emplace(5);
    std::cout << "The top of the stack 2 is: " << stack2.top() << std::endl;

    stack2.emplace(6);
    std::cout << "The top of the stack 2 is: " << stack2.top() << std::endl;

    stack2.emplace(1);
    std::cout << "The top of the stack 2 is: " << stack2.top() << std::endl;

    stack2.emplace(9);
    std::cout << "The top of the stack 2 is: " << stack2.top() << std::endl;

    std::cout << "\nBefore swap:" << std::endl;
    std::cout << "The top of the stack 1 is: " << stack1.top() << std::endl;
    std::cout << "The top of the stack 2 is: " << stack2.top() << std::endl;
    stack1.swap(stack2);

    std::cout << "\nAfter swap:" << std::endl;
    std::cout << "The top of the stack 1 is: " << stack1.top() << std::endl;
    std::cout << "The top of the stack 2 is: " << stack2.top() << std::endl;
}