#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int test(int n){
            int sum=0;
            while(n>0){
                sum+=n%10;
                n/=10;
            }
            return sum; 
        }
        int punishmentNumber(int n) {
            int fsum=0;
         for(int i=1;i<=n;i++){
            if(i%2==0||i%3==0||i%5==0){
                if(i*i==test(i)){
                  fsum+=i;  
                }

            }
        }
    return fsum;
}
};

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(int num, int square) {
        string s = to_string(square);
        return canPartitionHelper(s, num, 0, 0);
    }

    bool canPartitionHelper(const string& s, int num, int start, int currentSum) {
        if (start == s.size()) {
            return currentSum == num;
        }
        for (int i = start; i < s.size(); ++i) {
            int part = stoi(s.substr(start, i - start + 1));
            if (canPartitionHelper(s, num, i + 1, currentSum + part)) {
                return true;
            }
        }
        return false;
    }

    int punishmentNumber(int n) {
        int fsum = 0;
        for (int i = 1; i <= n; ++i) {
            int square = i * i;
            if (canPartition(i, square)) {
                fsum += square;
            }
        }
        return fsum;
    }
};