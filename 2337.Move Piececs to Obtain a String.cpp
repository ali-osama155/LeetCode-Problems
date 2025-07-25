#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int i = 0, j = 0;

        while (i < n || j < n) {
            while (i < n && start[i] == '_') i++;
            while (j < n && target[j] == '_') j++;

            if (i < n && j < n) {
                if (start[i] != target[j]) return false;

                if (start[i] == 'L' && i < j) return false; 
                if (start[i] == 'R' && i > j) return false; 

                i++;
                j++;
            } else if (i < n || j < n) {
                
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution sol;
    cout << boolalpha << sol.canChange("_L__R__R_", "L______RR") << endl; // true
    cout << boolalpha << sol.canChange("R_L_", "__LR") << endl;          // false
    cout << boolalpha << sol.canChange("_R", "R_") << endl;              // false
    return 0;
}
