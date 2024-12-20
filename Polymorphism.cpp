#include<bits/stdc++.h>
using namespace std;

// class Person {
// public:
//     string name;

//     Person(){
//         cout<<"I am Non-Parameterized";
//     }
//     Person(string name){
//         this->name = name;
//         cout<<"I am Parameterized";
//     }
// };

// int main() {
//     Person p1("Nikhil");

// }

// Comile Time Polymorphism

// class Print{
// public:
//     void show(int x){
//         cout << x;
//     }

//     void show(char ch){
//         cout << ch;
//     }
// };

// int main() {
//     Print p1;
//     p1.show('f');// During compile Time, It automatically detect that which should be compile
// }

//  Run Time Polymorphism

// class Teacher {
// public:
//     void getInfo(){
//         cout << "Parent Class";
//     }
// };
// class Student: public Teacher{
// public:
//     void getInfo(){
//         cout << "Child Class";
//     }
// };

// int main () {
//     // Student s1;
//     Teacher t1;
//     t1.getInfo();
//     // s1.getInfo();
// }
class Teacher {
public:
    void getInfo(){ // virtual function
        cout << "Parent Class";
    }
    virtual void hello(){ // virtual function
        cout << "Hello from Parent";
    }
};
class Student: public Teacher{
public:
    void getInfo(){
        cout << "Child Class";
    }
    void hello(){ // virtual function
        cout << "Hello from child";
    }

};

int main () {
    Student s1;

    s1.hello();
    // s1.getInfo();
}

