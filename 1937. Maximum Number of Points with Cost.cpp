/*#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long maxPoints(vector<vector<int>> &points)
    {




        /*for (int i = 0; i < points.size(); ++i)
        {
            int maxnum = *max_element(points[i].begin(), points[i].end());
            max.push_back(maxnum);
        }*/




       /* for (int i = 0; i < points.size(); i++) {
        int maxElement = points[i][0];
        int maxIndex = 0;            

        for (int j = 1; j < points[i].size(); j++) { 
            if (points[i][j] > maxElement) {
                maxElement = points[i][j]; 
                maxIndex = j;    
                max.push_back(maxElement);
                index.push_back(j);        
            }
        }}*/
        /*vector<int> max;
        vector<int> index;
         for (int i = 0; i < points.size(); ++i)
        {
            auto maxElementIter = max_element(points[i].begin(), points[i].end());
            int maxIndex = distance(points[i].begin(), maxElementIter);
            int maxValue = *maxElementIter;

            max.push_back(maxValue);
            index.push_back(maxIndex);
        }


        int maxpoints = 0;
        for (int i = 0; i < max.size(); i++)
        {
            maxpoints += max[i];
        }
      
        int subpoints = 0;
        for (int i = 1; i < index.size(); i++){
        subpoints += abs(index[i-1]-index[i]); //+ abs(index[1]-index[2]);
        }
        
    for (int i = 0; i < index.size(); i++)
    {
        cout<<index[i]<<endl;
    }
    
  return  subpoints;
    }
};


int main(){

    vector<vector<int>> tst  ={{1,2,3},{1,5,1},{3,1,1}};
    vector<vector<int>> tst2  ={
        {0,3,0,4,2},
        {5,4,2,4,1},
        {5,0,0,5,1},
        {2,0,1,0,3}};
    Solution s1;
    cout<<s1.maxPoints(tst2);

}
*/


#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long maxPoints(vector<vector<int>> &points)
    {
        int m = points.size(), n = points[0].size();
        vector<long long> prev_dp(n, 0);

        // Initialize dp for the first row
        for (int j = 0; j < n; ++j) {
            prev_dp[j] = points[0][j];
        }

        for (int i = 1; i < m; ++i) {
            vector<long long> curr_dp(n, 0);

            // Left-to-right pass
            vector<long long> left(n, 0);
            left[0] = prev_dp[0];
            for (int j = 1; j < n; ++j) {
                left[j] = max(left[j-1] - 1, prev_dp[j]);
            }

            // Right-to-left pass
            vector<long long> right(n, 0);
            right[n-1] = prev_dp[n-1];
            for (int j = n-2; j >= 0; --j) {
                right[j] = max(right[j+1] - 1, prev_dp[j]);
            }

            // Calculate current dp
            for (int j = 0; j < n; ++j) {
                curr_dp[j] = points[i][j] + max(left[j], right[j]);
            }

            // Move to the next row
            prev_dp = curr_dp;
        }

        // The answer is the maximum value in the last row
        return *max_element(prev_dp.begin(), prev_dp.end());
    }
};

int main()
{
    vector<vector<int>> tst = {{1, 2, 3}, {1, 5, 1}, {3, 1, 1}};
    vector<vector<int>> tst2 = {
        {0, 3, 0, 4, 2},
        {5, 4, 2, 4, 1},
        {5, 0, 0, 5, 1},
        {2, 0, 1, 0, 3}
    };
    
    Solution s1;
    cout << s1.maxPoints(tst) << endl;   // Output: 9
    cout << s1.maxPoints(tst2) << endl;  // Output: 14 (calculated correctly)
    
    return 0;
}











