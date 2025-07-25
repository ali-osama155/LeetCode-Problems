#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0; 
        while (i < str1.size() && j < str2.size()) {
            char current = str1[i];
            char incremented = (current == 'z') ? 'a' : current + 1;
            
            if (current == str2[j] || incremented == str2[j]) {
                j++;
            }
            i++; 
        }
        return j == str2.size(); 
    }
};

int main(){
    Solution s1;
    cout<<s1.canMakeSubsequence("zc","ad");
}