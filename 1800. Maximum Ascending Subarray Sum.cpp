#include <bits/stdc++.h>
using namespace std;    

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0]; // Start with the first element
        int old_sum = sum; 
        
        for(int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                sum += nums[i];
            } else {
                old_sum = max(sum, old_sum);
                sum = nums[i]; // Start a new ascending sequence
            }
        }
        return max(sum, old_sum); // Ensure the last sequence is considered
    }
};
