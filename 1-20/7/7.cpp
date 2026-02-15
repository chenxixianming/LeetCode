#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution
{
    public:
    int reverse(int x)
    {
        if(x == INT_MIN || x == 0)
            return 0;
        vector<int> reversed;
        int sign = (x < 0) ? -1 : 1;
        vector<int> maxi = (x < 0) ? vector<int> {2, 1, 4, 7, 4, 8, 3, 6, 4, 9} : vector<int> {2, 1, 4, 7, 4, 8, 3, 6, 4, 8};

        x *= sign;
        while(x > 0)
        {
            if(!reversed.empty() || x % 10 != 0)
                reversed.push_back(x % 10);
            x /= 10;
        }
        if(reversed.size() < 10)
        {
            return this->generate(reversed, sign);
        }
        for(int i = 0; i < 10; i++)
        {
            if(reversed[i] < maxi[i])
                return this->generate(reversed, sign);
            if(reversed[i] > maxi[i])
                return 0;
        }
        return 0;
    }

    int generate(vector<int> reversed, int sign)
    {
        sign *= reversed[0];
        for(int i = 1; i < reversed.size(); i++)
        {
            sign *= 10;
            if(sign > 0)
                sign += reversed[i];
            else
                sign -= reversed[i];
        }
        return sign;
    }
};

int main()
{
    int x = -120;
    Solution engine;
    int res = engine.reverse(x);
    printf("%d", res);
    return 0;
}