///////// version a7a ///////////

/*#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> nums ={1} ;
        int x = 2;
        while (nums.size()<n)
        {
        int i = x;
        while (i>1)
        {
        if(i%2==0)i/=2;
        else if(i%3==0)i/=3;
        else if(i%5==0)i/=5;
        else continue;  
        }
        nums.push_back(x);
        x++;
            
        }
   return  nums.back();}
};
*/


//i % 2 == 0 || i % 3 == 0 || i % 5 == 0
#include <iostream>
#include <vector>
using namespace std;
/************** version 1.1 time limit -_-
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> nums = {1}; // Start with the first ugly number
        int x = 2;
        while (nums.size() < n)
        {
            int i = x;
            while (i % 2 == 0) i /= 2;
            while (i % 3 == 0) i /= 3;
            while (i % 5 == 0) i /= 5;

            // If after dividing, i is 1, then x is an ugly number
            if (i == 1) {
                nums.push_back(x);
            }
            x++;
        }
        return nums.back();
    }
};
*/
////////////////////////////////     version 2
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNumbers(n);
        uglyNumbers[0] = 1;  

        int i2 = 0, i3 = 0, i5 = 0;  // Indices for multiples of 2, 3, and 5
        int next_multiple_of_2 = 2;
        int next_multiple_of_3 = 3;
        int next_multiple_of_5 = 5;

        for (int i = 1; i < n; ++i) {
            // Choose the smallest next multiple
            int next_ugly = min(next_multiple_of_2, min(next_multiple_of_3, next_multiple_of_5));
            uglyNumbers[i] = next_ugly;

            // Increment the index for which the multiple was used
            if (next_ugly == next_multiple_of_2) {
                i2++;
                next_multiple_of_2 = uglyNumbers[i2] * 2;
            }
            if (next_ugly == next_multiple_of_3) {
                i3++;
                next_multiple_of_3 = uglyNumbers[i3] * 3;
            }
            if (next_ugly == next_multiple_of_5) {
                i5++;
                next_multiple_of_5 = uglyNumbers[i5] * 5;
            }
        }

        return uglyNumbers[n-1];
    }
};

int main()
{
    Solution s1;
    cout << s1.nthUglyNumber(10);
    return 0;
}


///////////////////////stolen solution
/*class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> primes = {2, 3, 5};
        priority_queue<long, vector<long>, greater<long>> uglyHeap;
        unordered_set<long> visited;
        
        uglyHeap.push(1);
        visited.insert(1);
        
        long curr;
        for (int i = 0; i < n; ++i) {
            curr = uglyHeap.top();
            uglyHeap.pop();
            for (int prime : primes) {
                long new_ugly = curr * prime;
                if (visited.find(new_ugly) == visited.end()) {
                    uglyHeap.push(new_ugly);
                    visited.insert(new_ugly);
                }
            }
        }
        return (int)curr;
    }
};*/