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
        int left = 0, right = 0;
        int idx = 0;

        if(!to_match[0].empty())
        {
            for(int i = 0; i < to_match[0].size(); i++)
            {
                if(to_match[0][i] == '?')
                    continue;
                if(to_match[0][i] == s[i])
                    continue;
                return false;
            }
            idx = 1;
        }
        if(!to_match.back().empty())
        {
            auto start = s.size() - to_match[0].size();
            for(int i = 0; i < to_match[0].size(); i++)
            {
                if(to_match[0][i] == '?')
                    continue;
                if(to_match[0][i] == s[i + start])
                    continue;
                return false;
            }
            to_match.pop_back();
            s.resize(s.size() - to_match.back().size());
        }
        while(right < s.size()  && idx < to_match.size())
        {
            if(to_match[idx].empty())
            {
                if(idx = 0)
                {
                    idx++;
                }
                else 
                {
                    idx++;
                    break;
                }
            }
            if(left + to_match[idx].size() >= s.size())
                break;
            int i = 0;
            for(i = 0; i < to_match[idx].size(); i++)
            {
                if(s[left + i] != to_match[idx][i])
                {
                    i--;
                    break;
                }
            }
            if(i < to_match[idx].size() - 1)
            {
                left++;
                continue;
            }
            idx++;
            left += i + 1;
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