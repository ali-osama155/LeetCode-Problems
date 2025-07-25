#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;
        for (int i = 0; i < words1.size(); i++)
        {
            for (int j = 0; j < words2.size(); j++)
            {
                if ((words1[i], words2[j]))
                {
                    res.push_back(words1[i]);
                    break;
                }
            }
            
        }
        
    }
};


#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        // Compute the maximum frequency for each letter across all words in words2
        vector<int> maxFreq(26, 0);
        for (const string& word : words2) {
            vector<int> freq(26, 0);
            for (char c : word) {
                freq[c - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }

        // Find all universal strings in words1
        vector<string> result;
        for (const string& word : words1) {
            vector<int> freq(26, 0);
            for (char c : word) {
                freq[c - 'a']++;
            }
            bool isUniversal = true;
            for (int i = 0; i < 26; ++i) {
                if (freq[i] < maxFreq[i]) {
                    isUniversal = false;
                    break;
                }
            }
            if (isUniversal) {
                result.push_back(word);
            }
        }

        return result;
    }
};
