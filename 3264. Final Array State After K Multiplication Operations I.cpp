#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
    while (k>0)
    {
        
        int min = min_element(nums.begin(),nums.end()) - nums.begin();
        nums[min] *= multiplier;      
        k--; 
    }
    return nums;}
};
int main(){
    vector<int> vec = {2,1,3,5,6};
    Solution sol;
    sol.getFinalState(vec, 5 , 2);
    for (int i = 0; i < 5; i++)
    {
        cout << vec[i]<< " ";
    }
    
}