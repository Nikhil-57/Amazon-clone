#include <iostream>
#include <vector>
using namespace std;

// Condition: if arr[i] < n -> remove that element
// if arr[i] > n -> don't remove just decrease the n value by 1
// repeat the same process 

class Solution {
public:
    int channel(vector<int> arr, int n) {
        int m = arr.size();
        if (m == 0) return -1;
        
        int index = 0; 
        while (arr.size() > 1) {
            index = (index + n - 1) % arr.size();
            if (arr[index] < n) {
                arr.erase(arr.begin() + index); 
            } else {
                n--; // Decrease n by 1
            }
        }
        return arr[0]; 
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, step;
        cin >> n >> step; 
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution sol;
        cout << sol.channel(arr, step) << endl; 
    }

    return 0;
}
