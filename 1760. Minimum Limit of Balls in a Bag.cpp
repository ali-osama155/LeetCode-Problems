#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        sort(nums.begin(),nums.end());
        while(maxOperations>0){
            if((nums.size()-1) % 2 ==0){
                nums.push_back((nums.size()-1)/2);
                } 
            else {
                nums.push_back((nums.size()-1)/2);
                nums.push_back((nums.size()-1)/2 +1);
                }
            sort(nums.begin(),nums.end());
            nums.erase(nums.end() - 1);
            maxOperations--;
        }      
    return nums[nums.size()-1];}
};
int main(){
    Solution X;
    vector vec = {9};
    cout<<X.minimumSize(vec,2);
}


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        // Use binary search to minimize the largest bag size
        int left = 1, right = *max_element(nums.begin(), nums.end()), result = right;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canReduce(nums, maxOperations, mid)) {
                result = mid; // Update result
                right = mid - 1; // Try smaller values
            } else {
                left = mid + 1; // Try larger values
            }
        }
        return result;
    }

private:
    bool canReduce(const vector<int>& nums, int maxOperations, int maxSize) {
        int operations = 0;
        for (int num : nums) {
            if (num > maxSize) {
                operations += (num - 1) / maxSize; // Number of splits required
                if (operations > maxOperations) return false;
            }
        }
        return true;
    }
};

int main() {
    Solution X;
    vector<int> vec = {9};
    cout << X.minimumSize(vec, 2);
}
