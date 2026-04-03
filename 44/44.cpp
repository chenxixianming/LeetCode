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
        for(auto i : p)
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

        if(temp != "")
        {
            if(s.size() < temp.size())
                return false;
            temp = s.substr(s.size() - to_match.back().size());
            for(int i = 0; i < temp.size(); i++)
            {
                if(to_match.back()[i] != '?' && temp[i] != to_match.back()[i])
                    return false;
            }
            to_match.pop_back();
            // if(to_match.empty() && s != temp)
            //     return false;
            s.resize(s.size() - temp.size());
        }
        if(to_match.empty() && s.empty())
            return true;

        int start_label = -1;
        int left = 0;
        
        for(auto i : to_match)
        {
            bool label = false;
            if(i == "")
            {
                continue;
            }
            for(int j = left; j + i.size() <= s.size(); j++)
            {
                label = true;
                for(int k = 0; k < i.size(); k++)
                {
                    if(i[k] == '?')
                        continue;
                    if(i[k] == s[j + k])
                        continue;
                    label = false;
                    break;
                }
                if(label)
                {
                    if(start_label == -1)
                        start_label = j;
                    left = j + i.size();
                    break;
                }
            }
            if(!label)
                return false;
        }

        if(to_match[0] != "")
        {
            if(start_label != 0)
                return false;
        }

        return true;
    }
};

int main()
{
    string s = "aaab", p = "b**";
    Solution solution;
    bool res = solution.isMatch(s, p);
    printf("%d", res);
    return 0;
}