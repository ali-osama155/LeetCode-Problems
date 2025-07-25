#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int count = 0;
        long sum = 0;
        const long maxsum = accumulate(nums.begin(), nums.end(), 0LL);
        for (int i = 0; i < nums.size()-1; i++)
        {
            sum += nums[i];
            if (sum >= (maxsum - sum))
            {
                count++;
            }
        }
        
    return count;
    }
};
/*
int main() {
    Solution s;
    vector<int> nums = {10,4,-8,7};
    cout << s.waysToSplitArray(nums) << endl;
    return 0;
}*/