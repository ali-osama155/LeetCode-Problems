/*#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int> S;
        vector<int> C;
        int count = 0;
        if(A[0]!=B[0])C.push_back(0);
        for (int i = 0; i < A.size(); i++)
        {
        if ((S.find(A[i]) != S.end()) && (S.find(B[i]) != S.end()))
            {
                S.insert(A[i]);
                S.insert(B[i]);
                C.push_back(count+2);
            }
            else if (S.find(A[i]) != S.end() && S.find(B[i]) == S.end())
            {
                S.insert(A[i]);
                C.push_back(++count);
            }
            else if (S.find(A[i]) == S.end() && S.find(B[i]) != S.end())
            {
                S.insert(B[i]);
                C.push_back(++count);
            }
            else
            {
            S.insert(A[i]);
            S.insert(B[i]);
            }
        }     
       
    return C;       
    }
};
*/






#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int> setA, setB;
        vector<int> C(A.size(), 0);
        int count = 0;

        for (int i = 0; i < A.size(); i++) {
            setA.insert(A[i]);
            setB.insert(B[i]);

            if (setB.find(A[i]) != setB.end()) {
                count++;
            }
            if (setA.find(B[i]) != setA.end() && A[i] != B[i]) {
                count++;
            }

            C[i] = count;
        }

        return C;
    }
};

int main() {
    Solution s;
    vector<int> A = {1, 3, 2, 4};
    vector<int> B = {3, 1, 2, 4};
    // vector<int> result = s.findThePrefixCommonArray(A, B);
    // for (int num : result) {
    //     cout << num << " ";
    // }
    // cout << endl;
    int x = 2 ^ 2 ;
    cout<<x << endl;
    return 0;
}