/*
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxMoves(vector<vector<int>> grid) {
        int moves = 0;
        int cols = -1;
        for (int i = 0; i < grid.size()-1; i++ ){

            if(grid[i][cols]<grid[i][1]){ moves++; cols++;}

            
            if(grid[i][cols]<grid[i-1][cols+1]){ moves++; cols++;}
            if(grid[i][cols]<grid[i+1][cols+1]){ moves++; cols++;}

            else maxMoves(grid);
          
        }
        
    return moves;}
};

int main() {
    Solution obj;
    std::vector<std::vector<int>> matrix = {
        {2,4,3,5},
        {5,4,9,3},
        {3,4,2,11},
        {10,9,13,15}
        
    };

    int x = obj.maxMoves(matrix);
    cout << x << endl;

    return 0;
}*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // To store max moves from each cell
        vector<vector<int>> dp(m, vector<int>(n, -1));

        // Direction vectors for moving right, top-right, bottom-right
        vector<pair<int, int>> directions = {{0, 1}, {-1, 1}, {1, 1}};
        
        // Helper function to perform DFS and store the maximum moves in dp
        function<int(int, int)> dfs = [&](int i, int j) {
            if (dp[i][j] != -1) return dp[i][j];
            int maxMoves = 0;
            
            for (auto [di, dj] : directions) {
                int ni = i + di, nj = j + dj;
                if (ni >= 0 && ni < m && nj < n && grid[ni][nj] > grid[i][j]) {
                    maxMoves = max(maxMoves, 1 + dfs(ni, nj));
                }
            }
            
            dp[i][j] = maxMoves;
            return dp[i][j];
        };

        // Explore all possible starting cells in the first column and find max moves
        int result = 0;
        for (int i = 0; i < m; ++i) {
            result = max(result, dfs(i, 0));
        }

        return result;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> grid1 = {
        {2, 4, 3, 5},
        {5, 4, 9, 3},
        {3, 4, 2, 11},
        {10, 9, 13, 15}
    };
    cout << "Maximum moves for grid1: " << obj.maxMoves(grid1) << endl;

    vector<vector<int>> grid2 = {
        {3, 2, 4},
        {2, 1, 9},
        {1, 1, 7}
    };
    cout << "Maximum moves for grid2: " << obj.maxMoves(grid2) << endl;

    return 0;
}
