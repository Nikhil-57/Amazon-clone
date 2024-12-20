#include<iostream>
using namespace std;

void recur(int count){
    if(count < 0) return;
    cout << 1;
    recur(count - 1);
}
int main(){
    recur(10);
    return 0;
}