#include <bits/stdc++.h>
using namespace std;
/*
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> res;
        for (int i = 0; i < queries.size(); i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            int count = 0;
            for (int j = start; j <= end; j++) {
                string str = words[j];
                char c = str[0];
                char d = str[str.size() - 1]; 
                if ((c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')&&(d == 'a' || d == 'e' || d == 'i' || d == 'o' || d == 'u')) {   
                        count++;
                    }
            }
            res.push_back(count);
        }
        return res;   
    }
};*/
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix(n + 1, 0);

        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        for (int i = 0; i < n; ++i) {
            string str = words[i];
            char c = str[0];
            
            char d = str.back(); 
            prefix[i + 1] = prefix[i] + (isVowel(c) && isVowel(d));
        }

        vector<int> res;
        for (const auto& query : queries) {
            int start = query[0], end = query[1];
            res.push_back(prefix[end + 1] - prefix[start]);
        }

        return res;
    }
};
