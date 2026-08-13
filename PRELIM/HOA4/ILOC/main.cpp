#include <iostream>
#include <string>

const size_t maxCap = 100;

char stackArr[maxCap];
int top = -1;

void push(char c);
char pop();
bool isEmpty();
bool isMatching(char openSym, char closeSym);
bool isBalanced(const std::string &expr);

int main() {
    std::string expressions[] = {
        "(A+B)+(C-D)",
        "((A+B)+(C-D)",
        "((A+B)+[C-D])",
        "((A+B]+[C-D]}"
    };

    for (int i = 0; i < 4; i++) {
        top = -1; // reset the stack before checking the next expression

        std::cout << "Expression: " << expressions[i] << std::endl;

        if (isBalanced(expressions[i]))
            std::cout << "Valid? Y" << std::endl;
        else
            std::cout << "Valid? N" << std::endl;

        std::cout << std::endl;
    }

    return 0;
}

bool isEmpty() {
    if (top == -1)
        return true;
    return false;
}

void push(char c) {
    if (top == (int)maxCap - 1) {
        std::cout << "Stack Overflow." << std::endl;
        return;
    }

    stackArr[++top] = c;
}

char pop() {
    if (isEmpty()) {
        std::cout << "Stack Underflow." << std::endl;
        return '\0';
    }

    return stackArr[top--];
}

bool isMatching(char openSym, char closeSym) {
    if (openSym == '(' && closeSym == ')') return true;
    if (openSym == '{' && closeSym == '}') return true;
    if (openSym == '[' && closeSym == ']') return true;

    return false;
}

bool isBalanced(const std::string &expr) {
    for (size_t i = 0; i < expr.length(); i++) {
        char c = expr[i];

        // a) not a symbol to be balanced - ignore it
        if (c != '(' && c != ')' && c != '{' && c != '}' && c != '[' && c != ']')
            continue;

        // b) opening symbol - push it onto the stack
        if (c == '(' || c == '{' || c == '[') {
            push(c);
            continue;
        }

        // c) closing symbol
        // i) report an error if the stack is empty
        if (isEmpty()) {
            std::cout << "Error: '" << c << "' has no matching opening symbol." << std::endl;
            return false;
        }

        // ii) otherwise, pop the stack
        char openSym = pop();

        // d) if the symbol popped does not match, report an error
        if (!isMatching(openSym, c)) {
            std::cout << "Error: '" << openSym << "' does not match '" << c << "'." << std::endl;
            return false;
        }
    }

    // 3) at the end of input, if the stack is not empty: report an error
    if (!isEmpty()) {
        std::cout << "Error: unmatched opening symbol(s) remain." << std::endl;
        return false;
    }

    return true;
}