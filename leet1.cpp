#include <iostream>
#include <string>
using namespace std;

bool allVowelsPresent(int vowelCount[5]) {
    for (int i = 0; i < 5; i++) {
        if (vowelCount[i] == 0)
            return false;
    }
    return true;
}

int getVowelIndex(char ch) {
    if (ch == 'a') return 0;
    if (ch == 'e') return 1;
    if (ch == 'i') return 2;
    if (ch == 'o') return 3;
    if (ch == 'u') return 4;
    return -1;
}

int countSubstringsWithVowelsAndKConsonants(const string& word, int k) {
    int n = word.size();
    int vowelCount[5] = {0};
    int consonantCount = 0;
    int start = 0, result = 0;

    for (int end = 0; end < n; ++end) {
        char currentChar = word[end];
        int vowelIndex = getVowelIndex(currentChar);
        if (vowelIndex != -1) {
            vowelCount[vowelIndex]++;
        } else if (isalpha(currentChar)) {
            consonantCount++;
        }

        while (consonantCount > k) {
            char startChar = word[start];
            int startVowelIndex = getVowelIndex(startChar);
            if (startVowelIndex != -1) {
                vowelCount[startVowelIndex]--;
            } else if (isalpha(startChar)) {
                consonantCount--;
            }
            start++;
        }

        if (allVowelsPresent(vowelCount) && consonantCount == k) {
            result++;
        }
    }

    return result;
}

int main() {
    string word1 = "aeioqq";
    int k1 = 1;
    cout << "Output for word1: " << countSubstringsWithVowelsAndKConsonants(word1, k1) << endl;

    string word2 = "aeiou";
    int k2 = 0;
    cout << "Output for word2: " << countSubstringsWithVowelsAndKConsonants(word2, k2) << endl;

    string word3 = "ieaouqqieaouqq";
    int k3 = 1;
    cout << "Output for word3: " << countSubstringsWithVowelsAndKConsonants(word3, k3) << endl;

    return 0;
}
