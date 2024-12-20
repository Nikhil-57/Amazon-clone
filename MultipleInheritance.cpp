#include <iostream>
#include <string>
using namespace std;

class Teacher {
public:
    string name;
    int age;
};

// This is Multiple Inheritance
class Student{
public:
    int rollno;
};

class TA: public Student, public Teacher {
public:
    string subject;
    int salary;
};

int main() {
    TA s1;
    s1.name = "Pokemon";
    s1.subject = "Physics";
    s1.rollno = 23;
    cout << s1.name << endl;
    cout << s1.subject << endl;
    cout << s1.rollno << endl;
    return 0;
}
