#include<string>
#include<iostream>
#include<vector>
    
using namespace std;

class Solution {
public:
 /*   string intToRoman(int num) {
        unordered_map<int, char> RomanValue;
        RomanValue[1000] = 'M';
        RomanValue[500]  = 'D';
        RomanValue[100]  = 'C';
        RomanValue[50]   = 'L';
        RomanValue[10]   = 'X';
        RomanValue[5]    = 'V';
        RomanValue[1]    = 'I';
        int CM = 0;
        int CD = 0;
        int CC = 0;
        int CL = 0;
        int CX = 0;
        int CV = 0;
        int CI = 0;

        while(num>1000){
            num-=1000;
            CM++;
        }
        while(num>500){
            num-=500;
            CD++;
        }
        while(num>100){
            num-=100;
            CC++;
        }
        while(num>50){
            num-=50;
            CL++;
        }
        while(num>10){
            num-=10;
            CX++;
        }
        while(num>5){
            num-=5;
            CV++;
        }
        while(num>1){
            num-=1;
            CI++;
        }
    string sol =      std::string(CM, 'M') + std::string(CD, 'D') + std::string(CC, 'C') +
                      std::string(CL, 'L') + std::string(CX, 'X') + std::string(CV, 'V') +
                      std::string(CI, 'I');

   return sol; }
*/
///////////////////////////gpt code///////////

  string intToRoman(int num) {
        vector<pair<int, string>> values = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"},
            {1, "I"}
        };

        string result = "";

        for (const auto& [value, symbol] : values) {
            while (num >= value) {
                result += symbol;
                num -= value;
            }
        }

        return result;
    }
};

int main(){

    Solution s1;
    cout<<s1.intToRoman(3748);
}