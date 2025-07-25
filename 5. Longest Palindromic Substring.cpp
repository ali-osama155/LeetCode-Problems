#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
bool isPalindrome(const char *start, const char *end) {
    while (start < end) {
        if (*start != *end) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

    string longestPalindrome(string s) {
        string ans;
        char *ptr1 = &s[0];
        char *ptr2 = &s[s.length()-1];
        int maxLength = 1;
        std::string longest = s.substr(0, 1);
       for (size_t i = 0; i < s.length(); ++i) {
        for (size_t j = i + 1; j < s.length(); ++j) {
            ptr1 = &s[i];
            ptr2 = &s[j];

            if (isPalindrome(ptr1, ptr2) && (j - i + 1) > maxLength) {
                maxLength = j - i + 1;
                longest = s.substr(i, maxLength);
            }
        }
    }         // int count =0;

        // while (ptr1<ptr2-1)
        // {
        //     if(*ptr1 == *ptr2){
        //         ptr1++;
        //         ptr2--;
        //     ans += *ptr1;
        //     }
        //     else{
        //         if(count%2==0)ptr1++;
        //         else{ptr2--;}
        //         count ++;
        //     }            
    //    cout<< *ptr1 << *ptr2 <<endl;
        
    return longest ;}
};      
// axcgghhggi
int main(){
Solution s1;
string z = "cbbd";
cout<<s1.longestPalindrome(z);


}