#ifndef TREETRAVERSALS_H
#define TREETRAVERSALS_H

#include "GeneralTree.h"
#include <iostream>
#include <string>

//pre order
template <typename T>
void preOrder(GeneralTree<T>* node) {
    if (node == nullptr) return;

    std::cout << node->getRootVal() << " ";

    GeneralTree<T>* child = node->getFirstChild();
    while (child != nullptr) {
        preOrder(child);
        child = child->getNextSibling();
    }
}

//in order
template <typename T>
void inOrder(GeneralTree<T>* node) {
    if (node == nullptr) return;

    GeneralTree<T>* firstChild = node->getFirstChild();

    if (firstChild != nullptr) {
        inOrder(firstChild);
    }

    std::cout << node->getRootVal() << " ";

    if (firstChild != nullptr) {
        GeneralTree<T>* nextChild = firstChild->getNextSibling();
        while (nextChild != nullptr) {
            inOrder(nextChild);
            nextChild = nextChild->getNextSibling();
        }
    }
}

//post order
template <typename T>
void postOrder(GeneralTree<T>* node) {
    if (node == nullptr) return;

    GeneralTree<T>* child = node->getFirstChild();
    while (child != nullptr) {
        postOrder(child);
        child = child->getNextSibling();
    }

    std::cout << node->getRootVal() << " ";
}

//flag so we stop once we find it and dont print twice
static bool foundFlag = false;

//does the actual searching depending on which traversal we picked
template <typename T>
void searchHelper(GeneralTree<T>* node, std::string choice, T key) {
    if (node == nullptr || foundFlag) return;

    if (choice == "PRE") {
        if (node->getRootVal() == key) {
            std::cout << key << " was found" << std::endl;
            foundFlag = true;
            return;
        }
        GeneralTree<T>* child = node->getFirstChild();
        while (child != nullptr && !foundFlag) {
            searchHelper(child, choice, key);
            child = child->getNextSibling();
        }
    }
    else if (choice == "POST") {
        GeneralTree<T>* child = node->getFirstChild();
        while (child != nullptr && !foundFlag) {
            searchHelper(child, choice, key);
            child = child->getNextSibling();
        }
        if (!foundFlag && node->getRootVal() == key) {
            std::cout << key << " was found" << std::endl;
            foundFlag = true;
        }
    }
    else if (choice == "IN") {
        GeneralTree<T>* firstChild = node->getFirstChild();
        if (firstChild != nullptr && !foundFlag) {
            searchHelper(firstChild, choice, key);
        }
        if (!foundFlag && node->getRootVal() == key) {
            std::cout << key << " was found" << std::endl;
            foundFlag = true;
        }
        if (firstChild != nullptr && !foundFlag) {
            GeneralTree<T>* nextChild = firstChild->getNextSibling();
            while (nextChild != nullptr && !foundFlag) {
                searchHelper(nextChild, choice, key);
                nextChild = nextChild->getNextSibling();
            }
        }
    }
}

//findData(root, choice, key) and prints if it exists
template <typename T>
void findData(GeneralTree<T>* root, std::string choice, T key) {
    foundFlag = false; //reset every time
    searchHelper(root, choice, key);
}

#endif