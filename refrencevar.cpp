#include <iostream>
using namespace std;

void update(int &n){ // & is used for reference variable to make changes in n in main function
    n++;
}

int main(){
    int n;
    cin>>n;

    update(n);
    cout<<n;
}