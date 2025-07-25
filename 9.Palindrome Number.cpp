//***** version 1.0 23ms ******//
/*#include <iostream>
#include <vector>
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        std::vector<int> digits;
        while (x > 0)
        {
            int digit = x % 10;
            digits.push_back(digit);
            x /= 10;
        }
    
    int left = 0;                    
    int right = digits.size() - 1;  

    while (left < right) {
        if (digits[left] != digits[right]) {
            return false; 
        }
        left++;   
        right--;  
    }
    return true;    }
    };

    int main(){

        Solution s1;
        std::cout<<s1.isPalindrome(551155)<<std::endl;


    }

    */
   /***********version 2.0 chatgpt 4ms *************/
   class Solution
{
public:
    bool isPalindrome(int x)
    {
        // A negative number is not a palindrome
        if (x < 0)
            return false;
        
        // Create a reversed number
        int original = x;
        int reversed = 0;

        while (x > 0)
        {
            int digit = x % 10;
            reversed = reversed * 10 + digit;
            x /= 10;
        }

        return original == reversed;
    }
};
