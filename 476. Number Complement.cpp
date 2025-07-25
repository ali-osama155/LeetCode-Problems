#include <iostream>
#include <string>
#include<cmath>

class Solution {
public:
    std::string decimalToBinary(int decimal) {
        if (decimal == 0) return "0";

        std::string binary = "";
        while (decimal > 0) {
            int remainder = decimal % 2;
            binary = std::to_string(remainder) + binary;
            decimal /= 2;
        }
        return binary; 
    }

    int binaryToDecimal(const std::string &binary) {
        int decimal = 0;
        int length = binary.length();
        
        for (int i = 0; i < length; i++) {
            if (binary[length - i - 1] == '1') {
                decimal += (1 << i); 
            }
        }
        return decimal;
    }

    int findComplement(int num) {
        std::string s = decimalToBinary(num);
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '1') {
                s[i] = '0';
            } else {
                s[i] = '1';
            }
        }

        int ans = binaryToDecimal(s);
        return ans;
    }
};
int main(){

    Solution s1;
    std::cout <<s1.findComplement(5);
}