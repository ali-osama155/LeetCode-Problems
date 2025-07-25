#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:

    bool ckeck(const string& s) {
    if (s.empty()) return false;  // Handle empty string edge case

    char firstChar = s[0];  // Get the first character of the string
    bool anotherCharFound = false;

    // Iterate through the string starting from the second character
    for (size_t i = 1; i < s.size(); ++i) {
        if (s[i] == firstChar && anotherCharFound) {
            return true;  // Return true if the first character appears again after another character
        }
        if (s[i] != firstChar) {
            anotherCharFound = true;  // Mark that another character has been found
        }
    }

    return false;  // Return false if the first character does not appear again after another character
}

    int strangePrinter(string s) {
        unordered_set<char> myset;
        
        for (char i : s){
            myset.insert(i);
        }
        
        char* ptr1 = & s[0];
        int noname = s.length()-1;
        char* ptr2 = & s[noname];
        int counter = 0;
        //cout<< *ptr1 << *ptr2;
        while (counter<s.length())
        {
            if(*ptr1 != *ptr2){
            counter++;
             ptr2--;}
            else break;

        }
        //cout<< *ptr1 <<*ptr2;
        int finalres;
        bool ck = ckeck(s);
        if(ck == 1) finalres = &s[noname] - ptr2  ;
        else finalres = 0;
        //cout<< s[s.length()-1]<<endl << ptr2<<endl <<finalres;
        return finalres+ myset.size();
    }
};
int main(){
    Solution s1;
    cout<<s1.strangePrinter("aaabbbcccaaabbcc");
}

///////////////// cheated code

/* int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, n)); // Initialize DP table

        // Base case: Single character needs one turn
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }

        // Fill DP table
        for (int len = 2; len <= n; ++len) { // Length of the substring
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                // Try every possible split
                for (int k = i; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] - (s[j] == s[k] ? 1 : 0));
                }
            }
        }

        return dp[0][n - 1];
    }
};*/