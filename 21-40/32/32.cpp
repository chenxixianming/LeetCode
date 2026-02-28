#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution
{
    public:
    int longestValidParentheses(string s)
    {
        vector<int> dp(2, 0);
        int res = 0;
        s = " " + s;
        for(int i = 2; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                dp.push_back(0);
                continue;
            }
            int temp;
            if(s[i - 1] == '(')
            {
                temp = 2 + dp[i - 2];
                dp.push_back(temp);
                if(temp > res)
                    res = temp;
                continue;
            }
            if(i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
            {
                temp = 2 + dp[i - 1] + dp[i - dp[i - 1] - 2];
                dp.push_back(temp);
                if(temp > res)
                    res = temp;
                continue;
            }
            dp.push_back(0);
        }
        return res;
    }
};

int main()
{
    string s = "(()";
    Solution solution;
    int res = solution.longestValidParentheses(s);
    printf("%d", res);
    return 0;
}