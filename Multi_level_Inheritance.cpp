#include <iostream>
#include <string>
using namespace std;

class Teacher {
public:
    string name;
    int age;
};

// This is Multi-level Inheritance
class Student : public Teacher {
public:
    int rollno;
};

class GradStudent: public Student {
public:
    string research;
};

int main() {
    GradStudent s1;
    s1.name = "Pokemon";
    s1.research = "Lightning";
    cout << s1.name << endl;
    cout << s1.research << endl;
    return 0;
}
