#include <iostream>

//global declaration
#define maxCap 10

int stackArr[maxCap];
int top = -1, newData;

//prototype functions
void push();
void pop();
void Top();
void displayStack();
bool isEmpty();
bool isFull();
void exit();

bool isEmpty() {
    //how do we verify if the stack is empty
    if (top == -1) return true;
    return false;
}

bool isFull() {
    if (top == maxCap - 1) return true;
    return false;
}

void push() {
    //error checking
    if (isFull()) {
        std::cout << "Stack Overflow" << std::endl;
        return;
    }
    //pushing to the stack
    std::cout << "Enter a new Value: " << std::endl;
    std::cin >> newData;
    // how do we insert the data into the stack
    stackArr[++top] = newData;
}

void pop() {
    //error checking
    if (isEmpty()) {
        std::cout << "Stack underflow" << std::endl;
        return;
    }

    //Display the value that we are going to pop
    std::cout << "Popping: " << stackArr[top] << std::endl;
    //decrement the top value from the stack
    top--;
}

void Top() {
    //error catching:
    if (isEmpty()) {
        std::cout << "the stack is empty" << std::endl;
        return;
    }
    //check the top value
    std::cout << "top element: " << stackArr[top] << std::endl;
}

void displayStack() {
    if (isEmpty()) {
        std::cout << "The stack is empty." << std::endl;
        return;
    }

    std::cout << "Stack elements (top to bottom):" << std::endl;
    for (int i = top; i >= 0; i--) {
        std::cout << stackArr[i] << std::endl;
    }
}

void exit() {
    std::cout << "Exiting the program." << std::endl;
    std::exit(0);
}

//main driver
int choice;
int main() {
    while (true) {
        std::cout << "======================================" << std::endl;
        std::cout << "               Stack Operations" << std::endl;
        std::cout << "  1. PUSH 2. POP 3. TOP 4. isEmpty 5. isFull 6. Display the stack  7.Exit" << std::endl;
        std::cout << "--------------------------------------" << std::endl;
        std::cin >> choice;

        switch (choice) {
            case 1: push();
                break;
            case 2: pop();
                break;
            case 3: Top();
                break;
            case 4: std::cout << "is the stack empty? " << isEmpty() << std::endl;
                break;
            case 5: std::cout << "is the stack full? " << isFull() << std::endl;
                break;
            case 6: displayStack();
                break;
            case 7: exit();
                break;
            default: std::cout << "Invalid choice" << std::endl;
                break;
        }
    }
}