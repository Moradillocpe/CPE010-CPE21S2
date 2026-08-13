#include <iostream>
#include <string.h>

class Grocery_Item {
protected:
    std::string itemName;
    int itemPrice, itemQuantity;
public:
    // Constructor
    Grocery_Item(std::string itemName = "None", int itemPrice = 0, int itemQuantity = 0) {
        this->itemName = itemName;
        this->itemPrice = itemPrice;
        this->itemQuantity = itemQuantity;
    }

    // Virtual runs the correct version based on the object's real type,
    // even when called through a base class pointer.
    virtual int calculateSum() {
        return itemPrice * itemQuantity;
    }

    virtual ~Grocery_Item() {
        std::cout << itemName << " has been removed from memory." << std::endl;
    }

    // Copy constructor
    Grocery_Item(const Grocery_Item &sourceItem) {
        std::cout << "Copy constructor called" << std::endl;
        itemName = sourceItem.itemName;
        itemPrice = sourceItem.itemPrice;
        itemQuantity = sourceItem.itemQuantity;
    }

    // Copy assignment operator
    Grocery_Item& operator=(const Grocery_Item &sourceItem) {
        std::cout << "Copy Assignment operator called" << std::endl;
        if (this != &sourceItem) {
            itemName = sourceItem.itemName;
            itemPrice = sourceItem.itemPrice;
            itemQuantity = sourceItem.itemQuantity;
        }
        return *this;
    }

    // Print details
    void displayInfo() {
        std::cout << "Item: " << itemName << std::endl;
        std::cout << "Price: PHP " << itemPrice << std::endl;
        std::cout << "Quantity: x" << itemQuantity << std::endl;
    }
};

class Fruit : public Grocery_Item {
public:
    Fruit(std::string itemName = "None", int itemPrice = 0, int itemQuantity = 0)
        : Grocery_Item(itemName, itemPrice, itemQuantity) {}

    Fruit(const Fruit &sourceFruit) : Grocery_Item(sourceFruit) {
        std::cout << "Copy constructor called" << std::endl;
    }

    Fruit& operator=(const Fruit &sourceFruit) {
        std::cout << "Copy Assignment operator called" << std::endl;
        Grocery_Item::operator=(sourceFruit);
        return *this;
    }
    // No destructor needed here because the base class destructor already handles it.
};

class Vegetable : public Grocery_Item {
public:
    Vegetable(std::string itemName = "None", int itemPrice = 0, int itemQuantity = 0)
        : Grocery_Item(itemName, itemPrice, itemQuantity) {}

    Vegetable(const Vegetable &sourceVegetable) : Grocery_Item(sourceVegetable) {
        std::cout << "Copy constructor called" << std::endl;
    }

    Vegetable& operator=(const Vegetable &sourceVegetable) {
        std::cout << "Copy Assignment operator called" << std::endl;
        Grocery_Item::operator=(sourceVegetable);
        return *this;
    }
};

// Problem 3: adds up calculateSum() for every item in the list
int TotalSum(Grocery_Item *GroceryList[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (GroceryList[i] != nullptr) {
            sum += GroceryList[i]->calculateSum();
        }
    }
    return sum;
}

int main() {
    // array holding all items from Jenna's Grocery List
    Grocery_Item *GroceryList[4];
    GroceryList[0] = new Fruit("Apple", 10, 7);
    GroceryList[1] = new Fruit("Banana", 10, 8);
    GroceryList[2] = new Vegetable("Broccoli", 60, 12);
    GroceryList[3] = new Vegetable("Lettuce", 50, 10);

    for (int i = 0; i < 4; i++) {
        GroceryList[i]->displayInfo();
        std::cout << "Subtotal: PHP " << GroceryList[i]->calculateSum() << std::endl;
        std::cout << std::endl;
    }

    int grandTotal = TotalSum(GroceryList, 4);
    std::cout << "Total Amount to Pay: PHP " << grandTotal << std::endl;

    // delete Lettuce and de-allocate its memory
    delete GroceryList[3];
    GroceryList[3] = nullptr;
    std::cout << "Lettuce has been deleted from the grocery list." << std::endl;

    return 0;
}