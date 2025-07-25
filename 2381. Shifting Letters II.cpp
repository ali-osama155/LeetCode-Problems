#include <bits/stdc++.h>
using namespace std;/*
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
     for (int i = 0; i < shifts.size(); i++)
     {
        string temp = "";
        if(shifts[i][2]){
            temp = s.substr(shifts[i][0], shifts[i][1]+1);
            for(int j = 0; j < temp.size(); j++){
                temp[j] == 'z'? temp[j] = 'a': temp[j] = char(temp[j] + 1);     
            }
            s.replace(shifts[i][0], shifts[i][1]+1, temp);
        }
        else{
         temp = s.substr(shifts[i][0], shifts[i][1]+1);
            for(int j = 0; j < temp.size(); j++){
                temp[j] == 'a'? temp[j] = 'z': temp[j] = char(temp[j] - 1);     
            }
            s.replace(shifts[i][0], shifts[i][1]+1, temp);    
        }
    //cout << s << endl;
    }
        
    return s;
    }
};
int main() {
    Solution s;
    string str = "dztz";
    //cout<< str.substr(2,2) << endl;
    //char c = 'a';
    //cout << char(c + 1) << endl;
    vector<vector<int>> shifts = {{0,0,0},{1,1,1}};
    cout << s.shiftingLetters(str, shifts) << endl;
    return 0;
}*/
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        for (const auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            bool direction = shift[2]; 
            for (int i = start; i <= end; ++i) {
                if (direction) {
                    s[i] = (s[i] == 'z') ? 'a' : s[i] + 1;
                } else {
                    s[i] = (s[i] == 'a') ? 'z' : s[i] - 1;
                }
            }
        }
        return s;
    }
};

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> delta(n + 1, 0); // Difference array
        
        // Step 1: Build the difference array
        for (const auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2]; // 1 for right shift, 0 for left shift
            
            delta[start] += (direction == 1) ? 1 : -1;
            delta[end + 1] -= (direction == 1) ? 1 : -1;
        }
        
        // Step 2: Compute the cumulative shift
        int cumulativeShift = 0;
        for (int i = 0; i < n; ++i) {
            cumulativeShift += delta[i];
            // Normalize the cumulative shift to stay within 26 characters
            int effectiveShift = (cumulativeShift % 26 + 26) % 26;
            s[i] = 'a' + (s[i] - 'a' + effectiveShift) % 26;
        }
        
        return s;
    }
};
