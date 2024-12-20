class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return (a * b) / gcd(a, b);
    }

    long long totalgcd(const vector<long long>& vec) {
        long long result = vec[0];
        for (size_t i = 1; i < vec.size(); ++i) {
            result = gcd(result, vec[i]);
        }
        return result;
    }

    long long totallcm(const vector<long long>& vec) {
        long long result = vec[0];
        for (size_t i = 1; i < vec.size(); ++i) {
            result = lcm(result, vec[i]);
        }
        return result;
    }

    long long maxScore(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0] * nums[0];

        vector<long long> longNums(nums.begin(), nums.end());
        long long overallGCD = gcdOfVector(longNums);
        long long overallLCM = lcmOfVector(longNums);
        long long maxScore = overallGCD * overallLCM;

        for (int i = 0; i < n; ++i) {
            vector<long long> temp = longNums;
            temp.erase(temp.begin() + i);
            long long currentGCD = gcdOfVector(temp);
            long long currentLCM = lcmOfVector(temp);
            long long currentScore = currentGCD * currentLCM;
            maxScore = max(maxScore, currentScore);
        }

        return maxScore;
    }
};