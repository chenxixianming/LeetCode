#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if(strs.size() == 1)
            return strs[0];
        string res;
        int i = 0;
        while(true)
        {
            for(int j = 1; j < strs.size(); j++)
            {
                if(strs[j][i] == '\0' || strs[j][i] != strs[j - 1][i])
                {
                    return res;
                }
            }
            res.push_back(strs[0][i]);
            i++;
        }
        return res;
    }
};

int main()
{
    vector<string> strs;
    strs.push_back("flower");
    strs.push_back("flow");
    strs.push_back("flight");

    Solution engine;
    string res = engine.longestCommonPrefix(strs);
    cout<<res;

    return 0;
}