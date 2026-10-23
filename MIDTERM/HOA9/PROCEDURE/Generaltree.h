#ifndef GENERALTREE_H
#define GENERALTREE_H

#include <iostream>

template <typename T>
class GeneralTree {
private:
    T key;
    GeneralTree<T>* firstChild;
    GeneralTree<T>* nextSibling;

public:
    //constructor
    GeneralTree(T rootObj);

    //inserting a child node, gets added after the existing ones and returns the new node
    GeneralTree<T>* insertChild(T newNode);

    GeneralTree<T>* getFirstChild();
    GeneralTree<T>* getNextSibling();

    T getRootVal();
    void setRootVal(T obj);

    bool isLeaf();

    //just to check the tree looks right
    void printTree(int depth = 0);
};

template <typename T>
GeneralTree<T>::GeneralTree(T rootObj) {
    key = rootObj;
    firstChild = nullptr;
    nextSibling = nullptr;
}

template <typename T>
GeneralTree<T>* GeneralTree<T>::insertChild(T newNode) {
    GeneralTree<T>* newChild = new GeneralTree<T>(newNode);

    if (firstChild == nullptr) {
        //no kids yet so this is the first one
        firstChild = newChild;
    } else {
        //otherwise go to the end of the sibling list and stick it there
        GeneralTree<T>* temp = firstChild;
        while (temp->nextSibling != nullptr) {
            temp = temp->nextSibling;
        }
        temp->nextSibling = newChild;
    }

    return newChild;
}

template <typename T>
GeneralTree<T>* GeneralTree<T>::getFirstChild(){
    return firstChild;
}

template <typename T>
GeneralTree<T>* GeneralTree<T>::getNextSibling(){
    return nextSibling;
}

template <typename T>
T GeneralTree<T>::getRootVal() {
    return key;
}

template <typename T>
void GeneralTree<T>::setRootVal(T obj) {
    key = obj;
}

template <typename T>
bool GeneralTree<T>::isLeaf() {
    return firstChild == nullptr;
}

template <typename T>
void GeneralTree<T>::printTree(int depth) {
    for (int i = 0; i < depth; i++) {
        std::cout << "  ";
    }
    std::cout << key << std::endl;

    if (firstChild != nullptr) {
        firstChild->printTree(depth + 1); //go down
    }
    if (nextSibling != nullptr) {
        nextSibling->printTree(depth); //next one over
    }
}

#endif