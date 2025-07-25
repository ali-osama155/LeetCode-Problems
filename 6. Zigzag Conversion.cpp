/*#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        vector<vector<char>> zig(numRows, vector<char>(s.length(), '\0'));
        int j = 0;
        int count = 0;

        while (j < 7)
        {
            for (int i = 0; i < numRows; i++)
            {
                zig[i][j] = s[count++];
            }
            j++;
        }
        string ans;
        
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j <s.length(); i++)
            {
                ans += zig[i][j];
            }
            
        }
    

    return ans;}
};

int main()
{
    Solution s1;
    string s = "PAYPALISHIRING";
    s1.convert(s, 3);
}*/

//////////////////----cheating code
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1) return s; // Special case for single row

        vector<string> zig(numRows); // Vector of strings for each row
        int row = 0;
        bool down = true; // Direction control

        for (char c : s)
        {
            zig[row] += c;

            // Change direction when the top or bottom row is reached
            if (row == 0)
                down = true;
            else if (row == numRows - 1)
                down = false;

            // Move to next row in zigzag
            row += (down ? 1 : -1);
        }

        // Combine all rows into one string
        string ans;
        for (string r : zig)
            ans += r;

        return ans;
    }
};

int main()
{
    Solution s1;
    string s = "PAYPALISHIRING";
    string result = s1.convert(s, 3);
    cout << result << endl;
}
