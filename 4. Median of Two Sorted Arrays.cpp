#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> all(nums1);
        all.insert(all.end(), nums2.begin(), nums2.end());
        sort(all.begin(), all.end());

        int n = all.size();
        if (n % 2 != 0) {
            return all[n / 2];
        } else {
            return (all[n / 2 - 1] + all[n / 2]) / 2.0; // Average of the two middle elements for even size
        }
    }
};

int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    Solution s1;
    double median = s1.findMedianSortedArrays(nums1, nums2);
    cout << "The median is: " << median << endl;

    return 0;
}
