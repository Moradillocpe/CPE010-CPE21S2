#ifndef QUEUEARR_H
#define QUEUEARR_H
#include <iostream>

//array-Based circularqueue
template <typename T>
class queueArr {
    private:
   //pointer ti dynamically allocate array
   T* q_array;
    // maximum number of the elements a queue can hold
    size_t q_capacity;
    //current number of the elements in the queue
    size_t q_size;
    //index if the front element
    int q_front;
    //index of the back element
    int q_back;

    public:
    //constructor
    queueArr(size_t capacity = 10);
    //copy constructor
    queueArr(const queueArr<T>& other);
    //copy assignment operator
    queueArr & operator=(const queueArr<T>& other);
    //destructor
    ~queueArr();

    //queue operations
    bool Empty();
    bool Full();
    size_t Size();
    void Clear();
    T front();
    T Back();
    void Enqueue(T value);
    T Dequeue();

};

//constructor
template<typename T>
queueArr<T>::queueArr(size_t capacity) {
    //initialize the capacity, size, front, and back
    q_capacity = capacity;
    q_size = 0;
    q_front = 0;
    q_back = -1;
    // allocate memory for the array
    q_array = new T[q_capacity];
}

//copy constructor
template<typename T>
queueArr<T>::queueArr(const queueArr<T>& other){
    //copy the capacity
    q_capacity = other.q_capacity;
    //copy the size
    q_size = other.q_size;
    //copy the front index
    q_front = other.q_front;
    //copy the back index
    q_back = other.q_back;
    //dynamically allocate memory for the array
    q_array = new T[q_capacity];
    //copy the elements from the other queue to this queue
    for (size_t i = 0; i < q_size; i++) {
        q_array[(q_front + i) % q_capacity] = other.q_array[(other.q_front + i) % other.q_capacity];
    }
};

//copy assignment operator
template<typename T>
queueArr<T>& queueArr<T>::operator=(const queueArr<T>& other) {
    if (this != &other) {
        //delete the existing array
        delete[] q_array;
        //copy the capacity
        q_capacity = other.q_capacity;
        //copy the size
        q_size = other.q_size;
        //copy the front index
        q_front = other.q_front;
        //copy the back index
        q_back = other.q_back;
        //dynamically allocate memory for the array
        q_array = new T[q_capacity];
        //copy the elements from the other queue to this queue
        for (size_t i = 0; i < q_size; i++) {
            q_array[(q_front + i) % q_capacity] = other.q_array[(other.q_front + i) % other.q_capacity];
        }
    }
    return *this;
}

//destructor
template<typename T>
queueArr<T>::~queueArr(){
    delete[] q_array;
}


//Empty()
template <typename T>
bool queueArr<T>::Empty() {
    return q_size == 0;
}

//Full()
template<typename T>
bool queueArr<T>::Full() {
    //check if the size reached the maximum capacity
    return q_size == q_capacity;
}

//size()
template<typename T>
size_t queueArr<T>::Size() {
    //find the size of the array
    return q_size;
}

//front()
template<typename T>
T queueArr<T>::front(){
    //check if the queue is empty
    if (Empty()) {
       std::cout << "Queue is Empty." << std::endl;
       return T{};
    }
    //return front
    return q_array[q_front];
}

//back()
template<typename T>
T queueArr<T>::Back() {
    //check if the queue is empty
    if (Empty()) {
        std::cout << "Queue is Empty." << std::endl;
        return T{};
    }
    //return back
    return q_array[q_back];
}

//clear()
template<typename T>
void queueArr<T>::Clear() {
    //reset the q_size, q_front, and q_back 
    q_size = 0;
    q_front = 0;
    q_back = -1;
}

//Enqueue()
template<typename T>
void queueArr<T>::Enqueue(T value) {
    //check if the queue is full?
    if (Full()) {
        std::cout << "Queue is Full." << std::endl;
        return;
    }
    //move q_back circularly
    q_back = (q_back + 1) % q_capacity;
    //store new value to the back
    q_array[q_back] = value;
    //increment the q_size
    q_size++;
}

//T Dequeue()
template<typename T>
T queueArr<T>::Dequeue() {
    //check if empty
    if (Empty()) {
        std::cout << "Queue is Empty." << std::endl;
        return T{};
    }
    //create a temporary variable to store the current front
    T temp = q_array[q_front];
    //move q_front circularly
    q_front = (q_front + 1) % q_capacity;
    //decrement the q_size
    q_size--;
    //reset the indexes if the queue becomes empty
    if (Empty()) Clear();
    //return the temporary variable
    return temp;
}

#endif //Queue_h