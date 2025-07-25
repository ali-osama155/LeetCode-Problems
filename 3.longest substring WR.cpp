
/*//////////////////// version 1.0*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//class Solution {
//public:
    int lengthOfLongestSubstring(std::string s) {
        int count=0;
        std::vector<int> vec;

        for(int j=0 ; j<s.length()-1; j++){
            
            if(s[j+1] == s[j])continue;


            for(int i=0 ; i<j ; i++){
                if (s[i] == s[j]){
                    j=i;
                    
                    count =0;
                
                    
                    }
                


            }
           count++;
           vec.push_back(count);

        }
         std::sort(vec.begin(), vec.end());

        return vec[vec.size()-1];
    }
//};
/*
///////////version 1.1
#include <iostream>
#include <string>
#include <unordered_set>

int lengthOfLongestSubstring(std::string s) {
    int maxLength = 0;
    int count = 0;
    std::unordered_set<char> seenChars;

    for (int j = 0; j < s.length(); j++) {
        if (seenChars.find(s[j]) != seenChars.end()) {
            seenChars.clear();
            count = 0;
        }
        seenChars.insert(s[j]);
        count++;
        maxLength = std::max(maxLength, count);
    }

    return maxLength;
}

*/

int main()
{

std::string s ="pwwkew";

std::cout<<lengthOfLongestSubstring(s);
}