// #include <bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     bool isArraySpecial(vector<int>& nums) {
//         if(nums.size()==1) return true;
//         if(nums[0]%2==0){ 
//         for(int i=0;i<=nums.size();i+2){
//             if(nums[i]%2 != 0) return false;
            
//             }
//         }
//        else{
//             for(int i=1;i<=nums.size();i+2){
//             if(nums[i]%2 == 0) return false;
            
//             }
//         }
//         return true;
//     }
// };
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if ((nums[i] % 2) == (nums[i - 1] % 2)) {  // Adjacent elements must alternate
                return false;
            }
        }
        return true;
    }
};
