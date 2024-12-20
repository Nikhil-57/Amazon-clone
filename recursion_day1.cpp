#include <iostream>
using namespace std;
/*
int factorial(int n){
    if(n == 0){
        return 1;
    }
    int badi = n * factorial(n-1);//recursive approach
    return badi;
}

int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<endl;
    cout<<factorial(n);
}
*/


// void print(int n){
//     if(n == 0){
//         return;
//     }
//     //recursive relation
//     cout<<n<<endl;
//     print(n-1);
// }
// int main(){
//     int n;
//     cout<<"Enter the number ";
//     cin>>n;
//     cout<<endl;
//     print(n);
// }

int fib(int n){
    if(n == 0 || n == 1){
        return n;
    }
    //recursive relation
    // fib(1) = 1;

    int ans = fib(n-1) + fib(n-2);
    return ans;
}

int main(){
    int n;
    cout<<"Enter the number ";
    cin>>n;

    cout<<fib(n);
}