#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int end = pref.size();
        int count = 0;
        for(int i = 0; i < words.size(); i++){
            if(words[i].substr(0, end) == pref){
                count++;
            }
        }
    return count;
    }
};