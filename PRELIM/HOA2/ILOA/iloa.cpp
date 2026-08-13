#include <iostream>
#include <string>

class Student {
private:
    std::string studentName;
    int studentAge;
public:
    // Default constructor
    Student() : studentName(""), studentAge(0) {
        std::cout << "Constructor Called." << std::endl;
    }
    // Parameterized constructor
    Student(std::string name, int age) : studentName(name), studentAge(age) {
        std::cout << "Constructor Called." << std::endl;
    }
    // Copy constructor
    Student(const Student &source) {
        studentName = source.studentName;
        studentAge = source.studentAge;
        std::cout << "Copy Constructor is called." << std::endl;
    }
    // Copy assignment operator
    Student& operator=(const Student &source) {
        std::cout << "Copy Assignment Operator Called" << std::endl;
        if (this == &source) {
            return *this;
        }
        studentName = source.studentName;
        studentAge = source.studentAge;
        return *this;
    }
    // Destructor
    ~Student() {
        std::cout << "Deconstructor Called." << std::endl;
    }

    void printDetails() {
        std::cout << studentName << " " << studentAge << std::endl;
    }
};

int main() {
    Student student1("Roman", 28);
    Student student2(student1);
    Student student3;
    student3 = student2;

    return 0;
}

//Student Lists (Loop A + Loop B)

///int main() {
 //   const size_t j = 5;
   // Student studentList[j] = {};
  //  std::string nameList[j] = {"Carly", "Freddy", "Sam", "Zack", "Cody"};
  //  int ageList[j] = {15, 16, 18, 19, 16};

  //  for (int i = 0; i < j; i++) { //loop A
  //      Student *ptr = new Student(nameList[i], ageList[i]);
   //     studentList[i] = *ptr;
   //     delete ptr;   // frees the temporary object created with new
  //  }

  //  for (int i = 0; i < j; i++) { //loop B
 //       studentList[i].printDetails();
  //  }

  //  return 0;
//}