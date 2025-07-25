#include <vector>
#include <iostream>
/*class Solution
{
public:
    std::vector<std::vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {
        std::vector<std::vector<int>> vec(rows, std::vector<int>(cols, 0));
        std::vector<std::vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int direction = 0;
        int r = rStart, c = cStart;
        int steps =0;

        int count = 0;
        while (count < rows * cols)
        {
            for (int i = 0; i < 2; ++i)
            {
                for (int j = 0; j < steps; ++j)
                {

                    r += directions[direction][0];
                    c += directions[direction][1];

                    if (r >= 0 && r < rows && c >= 0 && c < cols)
                    {
                        return {r, c};
                    }
                }
              direction = (direction + 1) % 4; // Change direction
        }
        steps++;
    }
  return{};   }
};*/


class Solution
{
public:
    std::vector<std::vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {
        // Initialize the result vector to store all visited positions
        std::vector<std::vector<int>> result;
        
        // Directions: East, South, West, North
        std::vector<std::vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int direction = 0;
        
        // Start from the initial position
        int r = rStart, c = cStart;
        result.push_back({r, c});  // Add the starting position to the result
        
        int steps = 1;  // Initial steps count

        // Continue until all cells in the grid are visited
        while (result.size() < rows * cols)
        {
            for (int i = 0; i < 2; ++i)
            {
                for (int j = 0; j < steps; ++j)
                {
                    r += directions[direction][0];
                    c += directions[direction][1];

                    if (r >= 0 && r < rows && c >= 0 && c < cols)
                    {
                        result.push_back({r, c});
                    }
                }
                direction = (direction + 1) % 4; // Change direction
            }
            steps++;
        }

        return result;
    }
};