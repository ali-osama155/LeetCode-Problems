#include <iostream>
#include <vector>
using namespace std;
/*class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int start,end =0;
        queries[0][0] = start;
        for (int i = start; i <= end; i+2)
        {
            if(nums[i]%2==0 && nums[i+1]%2 != 0) return true;
            if(nums[i+1]%2==0 && nums[i]%2 != 0) return true;
            
        }
        
        
    }
};*/

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> special_prefix(n, 0);

        // Step 1: Precompute the special prefix array
        for (int i = 1; i < n; ++i) {
            if ((nums[i - 1] % 2) != (nums[i] % 2)) {
                special_prefix[i] = 1;
            }
            special_prefix[i] += special_prefix[i - 1];
        }

        vector<bool> result;
        // Step 2: Answer each query in O(1)
        for (const auto& query : queries) {
            int start = query[0];
            int end = query[1];

            int special_pairs = special_prefix[end] - (start > 0 ? special_prefix[start] : 0);
            result.push_back(special_pairs == (end - start));
        }

        return result;
    }
};