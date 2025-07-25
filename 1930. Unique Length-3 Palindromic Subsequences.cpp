#include <bits/stdc++.h>
using namespace std;
/*
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        char* start = &s[0];
        char* end = &s[s.size()-1];
        int count = 0;
        while(start != end){
            if(&start == &end){
                for (char* c = &start; c < &end+1; c++)
                {
                    char dub = c;
                    
                }
                
                start++;
                end = &s[s.size()-1];
                break;
            }
            end--;
        }

        return count;
    }
};
int main() {
    Solution s;
    string str = "aabca";
    cout << s.countPalindromicSubsequence(str) << endl;
    return 0;
}*/
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> firstOccurrence(26, -1);
        vector<int> lastOccurrence(26, -1);
        unordered_set<string> uniquePalindromes;

        for (int i = 0; i < n; ++i) {
            if (firstOccurrence[s[i] - 'a'] == -1) {
                firstOccurrence[s[i] - 'a'] = i;
            }
            lastOccurrence[s[i] - 'a'] = i;
        }

        for (char c = 'a'; c <= 'z'; ++c) {
            int start = firstOccurrence[c - 'a'];
            int end = lastOccurrence[c - 'a'];
            if (start < end) {
                unordered_set<char> middleChars;
                for (int i = start + 1; i < end; ++i) {
                    middleChars.insert(s[i]);
                }
                for (char mid : middleChars) {
                    uniquePalindromes.insert(string(1, c) + mid + c);
                }
            }
        }

        return uniquePalindromes.size();
    }
};
