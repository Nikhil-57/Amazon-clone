#include <iostream>
#include <string>
using namespace std;

class Teacher {
public:
    string name;
    int age;

    // Parameterized Constructor
    Teacher(string name, int age) {
        this->name = name;
        this->age = age;
    }
};

// THis is single type of Inheritance
class Student : public Teacher { // First calls the parent constructor then it calls child constructor
public:
    int rollno;

    // Correct constructor initialization list
    Student(string name, int age, int rollno) : Teacher(name, age) {
        this->rollno = rollno;
    }

    void getInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll no: " << rollno << endl;
    }
};

int main() {
    Student s1("Rahul", 45, 3432);
    s1.getInfo();
    return 0;
}
