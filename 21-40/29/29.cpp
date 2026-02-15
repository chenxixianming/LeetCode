#include<iostream>
#include<climits>

using namespace std;

class Solution
{
    public:
    int divide(int dividend, int divisor)
    {
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        bool sign = (dividend < 0) ^ (divisor < 0);
        int res = 0;
        if(dividend > 0)
            dividend = ~dividend + 1;
        if(divisor > 0)
            divisor = ~divisor + 1;
        while(dividend <= divisor)
        {
            if(dividend > (divisor << 1))
            {
                res += -1;
                dividend -= divisor;
                break;
            }
            int temp = 1;
            while((divisor << (temp - 1)) >= (INT_MIN >> 1) && dividend < (divisor << temp))
            {
                temp++;
            }
            temp--;
            res += -1 << temp;
            dividend -= divisor << temp;
        }
        if(! sign)
            res = ~res + 1;
        return res;
    }
};

int main()
{
    int dividend = INT_MIN, divisor = 1;
    Solution solution;
    int res = solution.divide(dividend, divisor);
    printf("%d", res);
    return 0;
}