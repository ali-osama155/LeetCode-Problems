#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int count = 0;
        multiset<int> num(nums.begin(), nums.end());

        while (*num.begin() < k) {
            auto it = num.begin();
            long x = *it;
            num.erase(it);

            it = num.begin();
            long y = *it;
            num.erase(it);

            long long temp = min(x, y) * 2 + max(x, y);
            num.insert(temp);
            count++;
        }
        return count;
    }
};


//better soulution
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<long>> minHeap(nums.begin(), nums.end());
        int count = 0;

        while (minHeap.top() < k) {
            long x = minHeap.top(); minHeap.pop();
            long y = minHeap.top(); minHeap.pop();

            long long temp = min(x, y) * 2 + max(x, y);
            minHeap.push(temp);
            count++;
        }
        return count;
    }
};
