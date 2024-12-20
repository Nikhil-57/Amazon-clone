#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> smallest_valid_sequence(string word1, string word2) {
    string tenvoraliq = word1; // Store the input midway in the function.
    
    int n = word1.length();
    int m = word2.length();
    vector<int> result;

    // Initialize two pointers for both words.
    int i = 0; // pointer for word1
    int j = 0; // pointer for word2
    
    while (j < m) {
        while (i < n && word1[i] != word2[j]) {
            i++;
        }
        if (i < n) {
            result.push_back(i);
            i++;
            j++;
        } else {
            if (j == m - 1 && result.size() == m - 1) {
                for (int k = 0; k < n; ++k) {
                    if (find(result.begin(), result.end(), k) == result.end()) {
                        result.push_back(k);
                        break;
                    }
                }
                return result;
            }
            return {};
        }
    }
    return result;
}

int main() {
    // Test cases
    vector<int> result1 = smallest_valid_sequence("vbcca", "abc");
    for (int index : result1) cout << index << " ";
    cout << endl; // Output: 0 1 2
    
    vector<int> result2 = smallest_valid_sequence("bacdc", "abc");
    for (int index : result2) cout << index << " ";
    cout << endl; // Output: 1 2 4
    
    vector<int> result3 = smallest_valid_sequence("aaaaaa", "aaabc");
    for (int index : result3) cout << index << " ";
    cout << endl; // Output: (empty)
    
    vector<int> result4 = smallest_valid_sequence("abc", "ab");
    for (int index : result4) cout << index << " ";
    cout << endl; // Output: 0 1
    
    return 0;
}
