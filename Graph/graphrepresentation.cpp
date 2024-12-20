#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution(){
    bool courseschedule(int numcourses, vector<int> prerequisites){
        unordered_map<int, vector<int>>adj;
        for(vector<int>&vec : adj){
            int v = vec[1];
            int u = vec[0];
            adj[u].push_back(v);
        }
        return solve(adj);
    }
}


int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        
    }
    
    return 0;
}
