#include<iostream>
#include<climits>

using namespace std;

class Solution
{
    public:
    int myAtoi(string s)
    {
        int i = 0;
        int sign = 0;
        long long integer = 0;
        for(; i < s.size(); i++)
        {
            if(s[i] == ' ')
                continue;
            if(s[i] == '+')
            {
                sign = 1;
                i++;
                break;
            }
            if(s[i] == '-')
            {
                sign = -1;
                i++;
                break;
            }
            if('0' <= s[i] <= 9)
            {
                sign = 1;
                break;
            }
            return 0;
        }

        for(; i < s.size(); i++)
        {
            if(s[i] < '0' || s[i] > '9')
                break;
            integer *= 10;
            integer += s[i] - '0';
            if(integer * sign < INT_MIN)
                return INT_MIN;
            if(integer > INT_MAX && sign == 1)
                return INT_MAX;
        }
        return (int)(integer * sign);
    }
};

int main()
{
    string s = "-2147483648";
    Solution engine;

    int res = engine.myAtoi(s);
    printf("%d", res);

    return 0;
}