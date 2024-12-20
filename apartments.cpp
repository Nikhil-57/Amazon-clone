#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> arr(n); // desired apartments size (n)
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());

        vector<int> arr1(m); // Size of each apartment (m)
        for (int i = 0; i < m; i++)
        {
            cin >> arr1[i];
        }
        sort(arr1.begin(), arr1.end());

        int score = 0;

        for (int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                if(arr[j] == arr1[k] - k || arr[j] == arr1[k] + k || arr[j] == arr1[k]){
                    score++;
                }
            }
        }
        cout << score;
        
    }
    return 0;
}

