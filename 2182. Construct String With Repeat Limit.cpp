#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);
        for(char c : s) {
            freq[c - 'a']++;
        }
        
        priority_queue<pair<char, int>> maxHeap;
        for(int i = 25; i >=0; --i){
            if(freq[i] > 0){
                maxHeap.emplace('a' + i, freq[i]);
            }
        }
        
        string result = "";
        
        while(!maxHeap.empty()){
            auto [c, cnt] = maxHeap.top();
            maxHeap.pop();
            
            int use = min(repeatLimit, cnt);
            result += string(use, c);
            cnt -= use;
            
            if(cnt > 0){
                if(maxHeap.empty()){
                    break;
                }
                auto [c2, cnt2] = maxHeap.top();
                maxHeap.pop();
                
                result += c2;
                cnt2 -= 1;
                
                maxHeap.emplace(c, cnt);
                
                if(cnt2 > 0){
                    maxHeap.emplace(c2, cnt2);
                }
            }
        }
        
        return result;
    }
};