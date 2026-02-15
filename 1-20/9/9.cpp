#include<iostream>
#include<climits>

using namespace std;

class Solution
{
    public:
    bool isPalindrome(int x)
    {
        if(x < 0)
            return false;
        int reversed = 0, temp = x;
        while(temp != 0)
        {
            if(reversed > (INT_MAX / 10 + 1))
                return false;
            reversed *= 10;
            if(reversed > (INT_MAX - (temp % 10)))
                return false;
            reversed += temp % 10;
            temp /= 10;
        }
        if(reversed == x)
            return true;
        return false;
    }
};

int main()
{
    int x = 12241;
    Solution engine;
    bool res = engine.isPalindrome(x);
    printf("%d", res);
    return 0;
}