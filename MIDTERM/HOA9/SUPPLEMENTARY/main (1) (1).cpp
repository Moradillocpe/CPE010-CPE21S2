#include "GeneralTree.h"
#include "TreeTraversals.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>

template <typename T>
int getHeight(GeneralTree<T>* node) {
    if (node->isLeaf()) return 0;

    int tallest = -1;
    GeneralTree<T>* child = node->getFirstChild();
    while (child != nullptr) {
        tallest = std::max(tallest, getHeight(child));
        child = child->getNextSibling();
    }
    return 1 + tallest;
}

template <typename T>
void printDepths(GeneralTree<T>* node, int depth,
                  std::vector<std::pair<T, int>>& out) {
    out.push_back({node->getRootVal(), depth});

    GeneralTree<T>* child = node->getFirstChild();
    while (child != nullptr) {
        printDepths(child, depth + 1, out);
        child = child->getNextSibling();
    }
}

int main() {
    // Build the tree exactly as shown in the figure
    GeneralTree<char>* A = new GeneralTree<char>('A');

    GeneralTree<char>* B = A->insertChild('B');
    GeneralTree<char>* C = A->insertChild('C');
    GeneralTree<char>* D = A->insertChild('D');
    GeneralTree<char>* E = A->insertChild('E');
    GeneralTree<char>* F = A->insertChild('F');
    GeneralTree<char>* G = A->insertChild('G');

    GeneralTree<char>* H = D->insertChild('H');

    GeneralTree<char>* I = E->insertChild('I');
    GeneralTree<char>* J = E->insertChild('J');

    GeneralTree<char>* P = J->insertChild('P');
    GeneralTree<char>* Q = J->insertChild('Q');

    GeneralTree<char>* K = F->insertChild('K');
    GeneralTree<char>* L = F->insertChild('L');
    GeneralTree<char>* M = F->insertChild('M');

    GeneralTree<char>* N = G->insertChild('N');

    std::cout << "Tree structure:\n";
    A->printTree();
    std::cout << std::endl;

    // ---- Task 2: height/depth table ----
    std::vector<std::pair<char, int>> depths;
    printDepths(A, 0, depths);

    std::vector<GeneralTree<char>*> order = {A,B,C,D,E,F,G,H,I,J,K,L,M,N,P,Q};

    std::cout << std::left << std::setw(8) << "Node"
              << std::setw(8) << "Height"
              << std::setw(8) << "Depth" << "\n";

    for (auto n : order) {
        int depth = 0;
        for (auto& pr : depths) {
            if (pr.first == n->getRootVal()) { depth = pr.second; break; }
        }
        std::cout << std::left << std::setw(8) << n->getRootVal()
                  << std::setw(8) << getHeight(n)
                  << std::setw(8) << depth << "\n";
    }
    std::cout << std::endl;

    // ---- Task 3: traversals ----
    std::cout << "Pre-order: ";
    preOrder(A);
    std::cout << std::endl;

    std::cout << "In-order: ";
    inOrder(A);
    std::cout << std::endl;

    std::cout << "Post-order: ";
    postOrder(A);
    std::cout << std::endl << std::endl;

    // ---- Table 9-5: findData test ----
    std::cout << "Testing findData:" << std::endl;
    findData(A, "IN", 'J');
    findData(A, "POST", 'M');
    std::cout << std::endl;

    // ---- Table 9-6: add O under G, then search for it ----
    G->insertChild('O');
    std::cout << "Adding node O under G" << std::endl << std::endl;

    std::cout << "Running findData for O:" << std::endl;
    findData(A, "PRE", 'O');

    return 0;
}