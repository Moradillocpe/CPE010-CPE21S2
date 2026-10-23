#ifndef BST_H
#define BST_H

template<typename T>
class BinarySearchTree{
    private:
    //create a key
    T key;
    //pointers for left and right
    BinarySearchTree<T>* left;
    BinarySearchTree<T>* right;


    public:
    //constructor
    BinarySearchTree(T value);

    //insert left and eight
    void insert(T value);
    void preOrder();
    void InOrder();
    void PostOrder();



    //traversing


    //searching
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree (T value){
    key = value;
    left = nullptr;
    right = nullptr;
}




template<typename T>
void BinarySearchTree<T>::insert(T value){
    //left or right


    //go left if value < key inset to left
    if(value < key){
        if (left == nullptr){
        left = new BinarySearchTree<T>(value);
        }else{
            left -> insert(value);   
        }
    }else if(value > key) {
        if (right == nullptr) {
            right = new BinarySearchTree<T>(value);
        }
    else {
        right->insert(value);
        }
        
    }
}
template <typename T>
void BinarySearchTree<T>::preOrder(){

    std::cout<<key << " ";
    if (left != nullptr){
        left -> preOrder();
    }

    if(right != nullptr){
        right -> preOrder();
    }
}
template <typename T>
void BinarySearchTree<T>::InOrder(){
    //go left
    if (left != nullptr){
        left -> InOrder();
    }
    std::cout<< key << " ";
    //go right
    if (right != nullptr){
       right -> InOrder();
    }
}

template<typename T>
void BinarySearchTree<T>::PostOrder(){
    //go left
    if (left != nullptr){
        left -> PostOrder();
    }
    //go right
    if (right != nullptr){
       right -> PostOrder();
    }
    std::cout<< key << " ";
}



#endif