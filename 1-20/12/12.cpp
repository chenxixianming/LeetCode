#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution
{
    public:
    string intToRoman(int num)
    {
        string s;
        vector<char> ten = {'I', 'X', 'C', 'M'};
        vector<char> five = {'V', 'L', 'D'};
        int base = 1000, i = 3;
        while(i >= 0)
        {
            int temp = num / base;
            if(i == 3)
            {
                for(int j = 0; j < temp; j++)
                    s.push_back(ten[i]);
                num %= base;
                i--;
                base /= 10;
                continue;
            }
            if(temp == 9)
            {
                s.push_back(ten[i]);
                s.push_back(ten[i + 1]);
                num %= base;
                i--;
                base /= 10;
                continue;
            }
            if(temp >= 5)
            {
                s.push_back(five[i]);
                num -= 5 * base;
                if(temp == 5)
                {
                    num %= base;
                    i--;
                    base /= 10;
                }
                continue;
            }
            if(temp == 4)
            {
                s.push_back(ten[i]);
                s.push_back(five[i]);
                num %= base;
                i--;
                base /= 10;
                continue;
            }
            for(int j = 0; j < temp; j++)
                s.push_back(ten[i]);
            num %= base;
            i--;
            base /= 10;
        }
        return s;
    }
};

int main()
{
    int num = 3749;
    Solution engine;
    string res = engine.intToRoman(num);
    cout<<res;
    return 0;
}