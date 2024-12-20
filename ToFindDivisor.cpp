#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> ToFindDivisor(int n) {
    vector<int> nums;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            nums.push_back(i);
            if (n / i != i) {
                nums.push_back(n / i);
            }
        }
    }
    return nums;
}

int main() {
    int n;
    cin >> n;
    vector<int> divisors = ToFindDivisor(n);
    for (int i = 0; i < divisors.size(); i++) {
        sort(divisors.begin(), divisors.end());
        cout << divisors[i] << " ";
    }
    return 0;
}
