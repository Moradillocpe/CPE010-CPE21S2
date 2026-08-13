#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>
#include "job.h"
struct Node {
    Job data;
    Node* next;
};

class Printer {
private:
    Node* frontPtr;   // points to the job that will be processed next
    Node* backPtr;    // points to the most recently added job
    int size;          // number of jobs currently waiting

public:
    Printer() : frontPtr(nullptr), backPtr(nullptr), size(0) {}

    // Destructor: clears any jobs still left in the queue
    ~Printer() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() const {
        return frontPtr == nullptr;
    }

    int getSize() const {
        return size;
    }

    //inserts a new job at the rear of the queue
    //The job ID and page count are generated automatically
    void addJob(const std::string& username) {
        Job newJob(username);
        Node* newPtr = new Node;
        newPtr->data = newJob;
        newPtr->next = nullptr;

        if (isEmpty()) {
            // inserting into an empty queue
            frontPtr = newPtr;
            backPtr = newPtr;
        } else {
            // inserting into a nonempty queue
            backPtr->next = newPtr;
            backPtr = newPtr;
        }
        size++;

        std::cout << "\nJob ID: " << newJob.getID() << " (auto-generated)\n";
        std::cout << "Pages: " << newJob.getPages() << " (auto-generated)\n";
        std::cout << "\nPrint Job Added Successfully!\n";
    }

    // dequeue(): removes and "processes" the job at the front of the queue.
    void dequeue() {
        if (isEmpty()) {
            std::cout << "\n[ERROR] No jobs to process. Queue is empty.\n";
            return;
        }

        Node* tempPtr = frontPtr;
        Job processedJob = tempPtr->data;

        if (frontPtr == backPtr) {
            // deleting the only item left in the queue
            frontPtr = nullptr;
            backPtr = nullptr;
        } else {
            // deleting from a queue of more than one item
            frontPtr = frontPtr->next;
            tempPtr->next = nullptr;
        }

        delete tempPtr;
        size--;

        std::cout << "\nProcessing Job ID: " << processedJob.getID()
                   << " for " << processedJob.getUsername()
                   << " (" << processedJob.getPages() << " pages)... Done!\n";
    }

    void displayQueue() const {
        std::cout << "\n========== PRINT QUEUE ==========\n";

        if (isEmpty()) {
            std::cout << "\n(Queue is empty)\n";
        } else {
            Node* current = frontPtr;
            int position = 0;
            while (current != nullptr) {
                std::cout << "\nPosition [" << position << "]\n";
                std::cout << "----------------------------\n";
                std::cout << "Job ID: " << current->data.getID() << "\n";
                std::cout << "Username: " << current->data.getUsername() << "\n";
                std::cout << "Pages: " << current->data.getPages() << "\n";
                std::cout << "----------------------------\n";
                current = current->next;
                position++;
            }
        }
        std::cout << "==================================\n";
    }
};

#endif
