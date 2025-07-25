class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> sol;
        set<int> neg;
        for(int i=0;i<nums.size();i++){
            if (nums[i]>0) sol.insert(nums[i]);
            else neg.insert(nums[i]); 

        } 
        int sum = 0;
        for(int i : sol){
            sum+=i;
        }
        if (sum == 0) return *max_element(neg.begin(), neg.end());
    return sum;}
};
