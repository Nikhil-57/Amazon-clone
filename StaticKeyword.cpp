#include <iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

//Static Variables
// void func(){
//     //int x = 0;// here x created in stack so it will delete after function execution
//     static int x = 0; //here x created in the memory so it will not delete even function ends
//     cout << "x: " << x << endl;
//     x++;
// }

//Static Class

// class func{
// public:
//     int x;
//     void incx(){
//         x = x + 1;
//     }
// };

// Static Objects

class ABC{
public:
    ABC (){
        cout << "Constructor\n";
    }
    ~ABC (){
        cout << "Destructor\n";
    }

};



int main(){
    if(true){
        // ABC obj;
        static ABC obj; //
    }
    cout << "End of Function";
    return 0;
}