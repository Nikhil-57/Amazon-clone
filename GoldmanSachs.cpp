#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

// Function to find the eldest ancestor in the family tree[^2^][2]
string findEldestAncestor(unordered_map<string, string>& parent_map) {
    unordered_set<string> children;
    for (auto& pair : parent_map) {
        children.insert(pair.second);
    }
    for (auto& pair : parent_map) {
        if (children.find(pair.first) == children.end()) {
            return pair.first;
        }
    }
    return "";
}

// Function to count the number of grandchildren and their descendants[^3^][3][^4^][4]
int countDescendants(const string& ancestor, unordered_map<string, vector<string>>& tree) {
    int count = 0;
    if (tree.find(ancestor) != tree.end()) {
        for (const string& child : tree[ancestor]) {
            if (tree.find(child) != tree.end()) {
                queue<string> q;
                for (const string& grandchild : tree[child]) {
                    q.push(grandchild);
                }
                while (!q.empty()) {
                    string current = q.front();
                    q.pop();
                    count++;
                    if (tree.find(current) != tree.end()) {
                        for (const string& descendant : tree[current]) {
                            q.push(descendant);
                        }
                    }
                }
            }
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    unordered_map<string, string> parent_map;
    unordered_map<string, vector<string>> tree;
    for (int i = 0; i < n; ++i) {
        string father, child;
        cin >> father >> child;
        parent_map[child] = father;
        tree[father].push_back(child);
    }
    string eldestAncestor = findEldestAncestor(parent_map);
    int descendantCount = countDescendants(eldestAncestor, tree);
    cout << eldestAncestor << endl;
    cout << descendantCount << endl;
    return 0;
}
