#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
};

class Teacher : public Person {
public:
    string subject;
};

// This is Hierarchical Inheritance
class Student : public Person {
public:
    int rollno;
};

int main() {
    Student s1;
    s1.name = "Pokemon";
    s1.rollno = 23;
    // s1.subject = "Physics"; // This line is incorrect since `Student` does not have a `subject` member
    cout << s1.name << endl;
    // cout << s1.subject << endl; // This line is incorrect since `Student` does not have a `subject` member
    cout << s1.rollno << endl;
    return 0;
}
