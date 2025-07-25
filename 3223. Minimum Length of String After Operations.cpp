#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumLength(string s) {
        if (s.size() < 3) return s.size();
        multiset<char> st(s.begin(), s.end()); 
        for (char c : set<char>(s.begin(), s.end())) { 
            int count = st.count(c);
            while (count >= 3){
                st.erase(c);
                int n = count - 2; 
                for(int i = 0; i < n; i++){
                    st.insert(c);
                    }
                count = st.count(c);    }
            }
    return st.size(); }
};

int main() {
    Solution s;
    string str = "ucvbutgkohgbcobqeyqwppbxqoynxeuuzouyvmydfhrprdbuzwqebwuiejoxsxdhbmuaiscalnteocghnlisxxawxgcjloevrdcj";
    cout << s.minimumLength(str) << endl; // Expected output: 38
    return 0;
}


/**/

class Solution {
public:
    int minimumLength(string s) {
        if (s.size() < 3) return s.size();

        // Count the frequencies of each character in the string
        unordered_map<char, int> counts;
        for (char c : s) {
            counts[c]++;
        }

        // Process each character's count
        for (auto& kv : counts) {
            int& count = kv.second;
            if (count >= 3) {
                // If count is greater than or equal to 3, reduce it
                // until it is less than 3 by subtracting multiples of 2
                if (count % 2 == 1) { // If count is odd
                    count = 1;
                } else {              // If count is even
                    count = 2;
                }
            }
            // If count is less than 3, keep it as is
        }

        // Sum up the counts to get the minimum length
        int totalLength = 0;
        for (const auto& kv : counts) {
            totalLength += kv.second;
        }

        return totalLength;
    }
};