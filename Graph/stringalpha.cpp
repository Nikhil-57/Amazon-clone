#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
// Create a program that outputs
//  Input: "geeksForGeeks"
//  output: GEEKS
//          FOR
//          GEEKS
//  all the words in different line
class Solution
{
public:
    string wordmake(string s)
    {
        vector<string> arr;

        for(char &ch : s){
            if(ch >= 'a' && ch <= 'z'){
                char alpha = toupper(ch);
                arr.push_back(alpha);
            }
        }
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
    }

    return 0;
}
