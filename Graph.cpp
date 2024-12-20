#include<iostream>
using namespace std;
// using matrices to store the edges
// int main(){
//     int n, m;
//     cin>>n >> m;

//     int adj[n+1][m+1];
//     for(int i = 0; i < m; i++){
//         int u, v;
//         cin>>u>>v;
//         adj[u][v] = 1
//         adj[v][u] = 1
//     }
//     return 0;
// }

//Using array of list to store the edges
int main(){
    int n, m;
    cin>>n >> m;

    vector<int>adj[n+1];
    for(int i = 0; i < m; i++){  // T.C = O(E)
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);//for undirected graph
    }
    return 0;
}