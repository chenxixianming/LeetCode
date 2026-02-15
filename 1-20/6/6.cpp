#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
    string convert(string s, int numRows)
    {
        if(numRows == 1)
            return s;
        string res;
        for(int i = 0; i < numRows; i++)
        {
            if(i == 0 || i == numRows - 1)
            {
                int j = i; 
                while(j < s.size())
                {
                    res.push_back(s[j]);
                    j += numRows * 2 - 2;
                }
                continue;
            }
            int j = i; 
            while(j < s.size())
            {
                res.push_back(s[j]);
                j += (numRows - i - 1) * 2;
                if(j >= s.size())
                    break;
                res.push_back(s[j]);
                j += 2 * i;
            }
        }
        return res;
    }
};

int main()
{
    string s = "ab";
    int numRows = 1;

    Solution engine;

    string res = engine.convert(s, numRows);

    cout<<res;
    return 0;
}