#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) return 0;
        int sign = (x < 0) ? -1 : 1; 
        x = abs(x); 
        
        long reversed = 0; 
        while (x != 0) {
            int digit = x % 10; 
            reversed = reversed * 10 + digit;             
            if (reversed > INT_MAX) return 0;
            
            x /= 10; 
        }
        
        return static_cast<int>(reversed) * sign; 
    }
};
int main(){
    Solution s1;
    cout<<s1.reverse(-2313131);
}