#include <iostream>
#include <vector>
#include <cmath>

class Solution
{
public:
    bool isPerfectSquare(int number)
    {
        int sqrtValue = static_cast<int>(std::sqrt(number));
        return (sqrtValue * sqrtValue == number);
    }

    bool isPrime(int n)
    {
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;

        if (n % 2 == 0 || n % 3 == 0)
            return false;

        for (int i = 5; i * i <= n; i += 6)
        {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }

    int leastTwoFactors(int n)
    {

        int num1 = 0;
        int num2 = 0;

        if (isPrime(n))
            return n;
        if (isPerfectSquare(n))
        {
            num1 = sqrt(n);
            if (num1>5){
            num1 = leastTwoFactors(num1);
            }
            return num1 *2;

        }

        for (int i = 2; i <= n; ++i)
        {
            if (n % i == 0)
            {
                if (num1 == 0)
                {
                    num1 = i; 
                }
                else
                {
                    num2 = i; 
                if(num1 * num2 != n){
                    num1 = num2;
                    num2 =0;
                    continue;
                }
                    break;    
                }
            }
        }
        if (num2>5){
            num2 = leastTwoFactors(num2);
        }
        if (num1>5){
            num1 = leastTwoFactors(num1);
        }
        //std::cout<<num1<<num2;
        return num1 + num2;
    }

    int minSteps(int n)
    {
        if (n == 1)
            return 0;
        int ans = leastTwoFactors(n);
        return ans;
    }
};

int main()
{
    Solution solution;
    int n = 110; 
    std::cout << "Sum of least two factors: " << solution.minSteps(n) << std::endl;
    return 0;
}
// AA AAAA AAAA AAAA AAAA
// AA AA