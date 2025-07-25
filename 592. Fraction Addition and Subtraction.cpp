#include<string>
#include<iostream>

using namespace std;


class Solution {
public:
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Function to reduce a rational number to its simplest form
void reduce(int &numerator, int &denominator) {
    int common = gcd(numerator, denominator);
    numerator /= common;
    denominator /= common;
}

// Function to perform addition of rational numbers
void add(int num1, int den1, int num2, int den2) {
    int result_num = num1 * den2 + num2 * den1;
    int result_den = den1 * den2;
    reduce(result_num, result_den);
}

// Function to perform subtraction of rational numbers
void subtract(int num1, int den1, int num2, int den2) {
    int result_num = num1 * den2 - num2 * den1;
    int result_den = den1 * den2;
    reduce(result_num, result_den);
}


   string fractionAddition(string expression) {
    int numerator = 0, denominator = 1; // Start with 0/1
    int num = 0, den = 0;
    char sign = '+'; // Initial sign

    for (int i = 0; i < expression.size();) {
        // Check for sign
        if (expression[i] == '+' || expression[i] == '-') {
            sign = expression[i];
            i++;
        }

        // Extract the numerator
        num = 0;
        while (i < expression.size() && isdigit(expression[i])) {
            num = num * 10 + (expression[i] - '0');
            i++;
        }

        // Skip the '/'
        i++;

        // Extract the denominator
        den = 0;
        while (i < expression.size() && isdigit(expression[i])) {
            den = den * 10 + (expression[i] - '0');
            i++;
        }

        // Add or subtract the fraction based on the sign
        if (sign == '+') {
            add(numerator, denominator, num, den);
        } else {
            subtract(numerator, denominator, num, den);
        }
    }

    // Simplify the final result
    reduce(numerator, denominator);

    // Convert to string and return
    return to_string(numerator) + "/" + to_string(denominator);
}

};

int main(){

    Solution s1;
   cout<< s1.fractionAddition("-1/2+1/2+1/3");
}