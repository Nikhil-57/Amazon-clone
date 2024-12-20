#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "aabb";  // Example input
    string original = s;  // Store the original string

    s.clear();

    for(char c : original) {
        int value = c - 'a' + 1;
        s += to_string(value);
    }
    int result = stoi(s);

    cout << "The resulting integer is: " << result << endl;

    return 0;
}
