#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;

class shape{ // Abstract Class
    virtual void draw () = 0;// Pure virtual function
};

class circle:public shape{
public:
    void draw(){
        cout << "Drawing a cirle";
    }

};

int main(){
    circle c1;
    c1.draw();
}