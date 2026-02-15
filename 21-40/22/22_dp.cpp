#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<vector<string>> dp;
        dp.push_back({""});
        dp.push_back({"()"});
        for(int i = 2; i <= n; i++)
        {
            vector<string> temp;
            for(int j = 0; j < i; j++)
            {
                vector<string> left = dp[j];
                vector<string> right = dp[i - j - 1];
                for(auto m : left)
                    for(auto n : right)
                    {
                        temp.push_back("(" + m + ")" + n);
                    }
            }
            dp.push_back(temp);
        }
        return dp.back();
    }
};

int main()
{
    int n = 4;
    Solution solution;
    vector<string> res = solution.generateParenthesis(n);
    for(auto i : res)
    {
        cout<< i << '\n';
    }
    return 0;
}