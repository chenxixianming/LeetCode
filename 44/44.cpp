/* 
贪心算法，先将p根据‘*’分割，然后从左向右依次匹配
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution
{
    public:
    bool isMatch(string s, string p)
    {
        if(p.empty())
        {
            if(s.empty())
                return true;
            return false;
        }
        vector<string> to_match;
        string temp;
        for(auto i : s)
        {
            if(i == '*')
            {
                to_match.push_back(temp);
                temp = "";
                continue;
            }
            temp.push_back(i);
        }
        to_match.push_back(temp);
        int left = 0;
        while(left < s.size())
        {

        }
    }
};

int main()
{
    string s = "aa", p = "a";
    Solution solution;
    bool res = solution.isMatch(s, p);
    printf("%d", res);
    return 0;
}