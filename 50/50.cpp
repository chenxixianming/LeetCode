#include<iostream>
#include<climits>

class Solution
{
    public:
    double myPow(double x, int n)
    {
        if(x == 1.0 || n == 1 || x == -1 && n % 2 == 1)
            return x;
        if(n == 0 || x == -1.0 && n % 2 == 0)
            return 1.0;
        if(n == INT_MIN)
            return this->myPow(x, n + 1) / x;
        if(n < 0)
        {
            n = -n;
            x = 1 / x;
        }
        double res = this->myPow(x, n / 2);
        res *= res;
        if(n >> 1 << 1 != n)
        {
            res *= x;
        }
        return res;
    }
};

int main()
{
    double x = 2.0;
    int n = 10;
    Solution sol;
    double res = sol.myPow(x, n);
    printf("%lf\n", res);
    return 0;
}