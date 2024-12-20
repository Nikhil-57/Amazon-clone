#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

bool ToCheckPrime(int n){
    int count = 0;
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            count++;
        }
        if(n/i != i){
            count++;
        }
        if(count == 2){
            return true;
        }
    }
    return false;
}

int main(){
    int n; 
    cin >> n;
    if(ToCheckPrime(n)){
        cout<<"Yes";
    }else{
        cout<<"No";
    }

    return 0;
}
