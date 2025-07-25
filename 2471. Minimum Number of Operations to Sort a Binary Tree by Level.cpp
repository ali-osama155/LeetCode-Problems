#include <bits/stdc++.h>
using namespace std;
/*class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int count = 0;
        multiset<int> s;
        s = multiset<int>(favorite.begin(), favorite.end());
        auto it = s.begin();
        for(auto i:s){
            if(it == i && count < 2) count++;
            else{ 
                count = 0;
                s.erase(it);
            }
            it = i;   
        }
    return s.size();
    }
};
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> indegree(n, 0);
        vector<bool> visited(n, false);
        vector<int> longestChain(n, 0);
        
        // Calculate indegree for each node
        for (int i = 0; i < n; ++i) {
            indegree[favorite[i]]++;
        }
        
        // Find and process nodes with indegree 0 (start of chains)
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visited[node] = true;
            int fav = favorite[node];
            longestChain[fav] = max(longestChain[fav], longestChain[node] + 1);
            if (--indegree[fav] == 0) q.push(fav);
        }

        // Handle cycles and 2-node mutual favorites
        int maxCycle = 0, maxChains = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int cycleLength = 0, curr = i;
                // Detect cycle length
                while (!visited[curr]) {
                    visited[curr] = true;
                    curr = favorite[curr];
                    cycleLength++;
                }

                if (cycleLength == 2) {
                    // Handle 2-node cycles
                    int a = i, b = favorite[i];
                    maxChains += (2 + longestChain[a] + longestChain[b]);
                } else {
                    // Handle larger cycles
                    maxCycle = max(maxCycle, cycleLength);
                }
            }
        }

        return max(maxCycle, maxChains);
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> favorite1 = {2, 2, 1, 2};
    cout << sol.maximumInvitations(favorite1) << endl; // Output: 3

    // Example 2
    vector<int> favorite2 = {1, 2, 0};
    cout << sol.maximumInvitations(favorite2) << endl; // Output: 3

    // Example 3
    vector<int> favorite3 = {3, 0, 1, 4, 1};
    cout << sol.maximumInvitations(favorite3) << endl; // Output: 4

    return 0;
}
