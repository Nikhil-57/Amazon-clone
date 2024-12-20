#include <iostream>
#include <string>
using namespace std;

// class Teacher {
// private:
//     double salary;

// public:
//     string name;
//     string subject;
//     string dept;

// Non-Parameterized Constructor
    // Teacher(){ // No parameters in the parenthesis
    //     cout << "Hi, I am Constructor \n";
    // }

// Parameterized Constructor
    // Teacher(string name, string subject, string dept, double salary){ // No parameters in the parenthesis
    //     this->name = name; // to access the properties we use this pointer || same name of object
    //     this->subject = subject;
    //     this->dept = dept;
    //     this->salary = salary;
    // }

    
    // void changedept(string newDept){
    //     dept = newDept;
    // }
    // //copy constructor
    // Teacher (Teacher &orgObj) 
    // {
    //     cout << "I am custom copy constructor \n";
    //     this->name = orgObj.name;
    //     this->subject = orgObj.subject;
    //     this->dept = orgObj.dept;
    //     this->salary = orgObj.salary;

    // }
    
    //setter
    // void setSalary(double s){
    //     salary = s;
    // }
    
    // //getter
    // double getSalary(){
    //     return salary;
    // }

class Student{
public:
    string name;
    // cgpa;// static memory allocation
    double *cgpaptr;// dynamic memory allocation

    Student(string name, double cgpa){
        this->name = name;
        cgpaptr = new double;
        *cgpaptr = cgpa;
    }
    Student(Student &obj){
        this->name = obj.name;
        cgpaptr = new double;
        *cgpaptr = *(obj.cgpaptr);
    }

    // Inheritance
    class

    //destructor - To deallocate memory which are unused
    ~Student(){
        cout << " Hi, I am destructor- I delete everything \n" ;
        delete cgpaptr; // Very imp task in the company - It does not delete the cgpaptr, it deletes the memory address where cgpaptr points  - memory leak
    }


    void getInfo(){
        cout << "name: " << name << endl;
        cout << "cgpa: " << *cgpaptr << endl;
    } 
};

int main () {
    Student s1("Nikhil", 8.9);
    Student s2(s1);// custom copy constructor invoke
    //t1.getInfo();
    //Teacher t2(t1);// default copy constructor invoked
    s1.getInfo();
    *(s2.cgpaptr) = 9.2; // sahil cgpa change
    s2.name = "Sahil";
    s1.getInfo();
    s2.getInfo();
}