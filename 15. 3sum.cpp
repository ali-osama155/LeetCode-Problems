#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> sol;
        int count = nums.size();
        for (int k = 0; k < count; k++)
        {
        for (int j = 0; j < count; j++)
        {
            for (int i = 0; i < count; i++)
            {
                if(nums[i]==nums[j] || nums[i]==nums[k] || nums[j]==nums[k])continue;

                if(nums[i]+nums[j]+nums[k] ==0){
                vector<int> elm ={k,i,j};
                 sol.push_back(elm);
            }
            
            }
            
        }
        }
  //      print(sol);
return sol;    }

void print(        vector<vector<int>> sol){
    for (int i = 0; i < 5; i++)
    {
for (int j = 0; j < 5; j++)
{
    cout<<sol[i][j]<<endl;
}

    }
    
}
};


int main(){
Solution s1;
vector<int> noname = {-1, 0, 1, 2,-1,-4};
s1.threeSum(noname);

}