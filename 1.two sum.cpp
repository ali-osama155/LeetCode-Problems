#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target) {
                    
                return  { i , j };
                
                }
            }
        }    
   return{}; }
   
};


int main() {
    Solution s;
    int t;
    cin >> t; 
    
    int n;
    cin >> n;
    vector<int> x(n);
    for(int i = 0; i < n; i++){
        cin >> x[i]; 
    }
    
    
    vector<int> result = s.twoSum(x, t);

        cout <<"["<< result[0] << "," << result[1]<<"]"<< endl;
    return 0;
}
