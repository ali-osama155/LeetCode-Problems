#include<vector>

using namespace std;

class Solution {
public:
    int stoneGameII(vector<int>& piles) {

        /*int m = 1;
        int x;*/
/*               stolen solve              */
         int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));
        vector<int> suffixSum(n, 0);
        
        // Calculate suffix sums
        suffixSum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }
        
        // Fill dp table
        for (int i = n - 1; i >= 0; --i) {
            for (int m = 1; m <= n; ++m) {
                // If Alice can take all remaining piles
                if (i + 2 * m >= n) {
                    dp[i][m] = suffixSum[i];
                } else {
                    for (int x = 1; x <= 2 * m; ++x) {
                        dp[i][m] = max(dp[i][m], suffixSum[i] - dp[i + x][max(m, x)]);
                    }
                }
            }
        }
        
        return dp[0][1];
    }
};

