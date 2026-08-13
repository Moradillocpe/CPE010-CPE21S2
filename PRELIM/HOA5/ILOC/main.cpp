#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "printer.h"

void printMenu() {
    std::cout << "\n=================================\n";
    std::cout << "     SHARED PRINTER SIMULATOR\n";
    std::cout << "=================================\n";
    std::cout << "1. Add Print Job\n";
    std::cout << "2. Process Next Job\n";
    std::cout << "3. View Print Queue\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter choice: ";
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // seed for auto page generation

    Printer printer;
    int choice = 0;
    std::string username;

    std::cout << "Welcome to the Shared Printer Simulation!\n";
    std::cout << "(Job IDs and page counts are generated automatically.)\n";

    while (choice != 4) {
        printMenu();
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "\n[ERROR] Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                std::cout << "\nEnter Username: ";
                std::cin >> username;
                printer.addJob(username);
                break;

            case 2:
                printer.dequeue();
                break;

            case 3:
                printer.displayQueue();
                break;

            case 4:
                std::cout << "\nExiting simulation. Goodbye!\n";
                break;

            default:
                std::cout << "\n[ERROR] Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}

