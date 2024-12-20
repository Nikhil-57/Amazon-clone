#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int maxSubarraySumDivisibleByK(vector<int>& nums, int k) {
    vector<int> relsorinta = nums;  // Store the input midway in the function
    int max_sum = INT_MIN;
    int current_sum = 0;
    unordered_map<int, int> mod_map;
    mod_map[0] = -1;

    for (int i = 0; i < nums.size(); ++i) {
        current_sum += nums[i];
        int mod = ((current_sum % k) + k) % k;  // Handle negative mod

        if (mod_map.find(mod) != mod_map.end()) {
            int subarray_sum = current_sum - mod_map[mod];
            max_sum = max(max_sum, subarray_sum);
        } else {
            mod_map[mod] = current_sum;
        }
    }

    return max_sum;
}

int main() {
    vector<int> nums1 = {1, 2};
    int k1 = 1;
    cout << "Output: " << maxSubarraySumDivisibleByK(nums1, k1) << endl;  // Output: 3

    vector<int> nums2 = {-1, -2, -3, -4, -5};
    int k2 = 4;
    cout << "Output: " << maxSubarraySumDivisibleByK(nums2, k2) << endl;  // Output: -10

    vector<int> nums3 = {-5, 1, 2, -3, 4};
    int k3 = 2;
    cout << "Output: " << maxSubarraySumDivisibleByK(nums3, k3) << endl;  // Output: 4

    return 0;
}
