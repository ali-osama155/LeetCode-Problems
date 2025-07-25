#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        
        // Initialize each node as its own parent
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
        
        // Iterate through each edge
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            // Find the root parent of u and v
            int rootU = find(parent, u);
            int rootV = find(parent, v);
            
            // If they have the same root, this edge is redundant
            if (rootU == rootV) {
                return edge;
            }
            
            // Otherwise, union the two sets
            parent[rootV] = rootU;
        }
        
        // If no redundant edge is found (though the problem guarantees one)
        return {};
    }
    
private:
    int find(vector<int>& parent, int node) {
        // Path compression: make every node point directly to the root
        if (parent[node] != node) {
            parent[node] = find(parent, parent[node]);
        }
        return parent[node];
    }
};