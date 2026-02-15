#include<iostream>

using namespace std;

class Solution
{
    public:
    bool isMatch(string s, string p)
    {
        for(auto i : s)
        {
            bool temp1 = false;
            for(int j = 0; j < p.size(); j++)
            {
                if(p[j] == i || p[j] == '.')
                {
                    temp1 = true;
                    break;
                }
            }
            if(temp1 == false)
            {
                return false;
            }
        }
        int num_stars = 0;
        for(auto i : p)
        {
            if(i == '*')
            {
                num_stars++;
            }
        }
        if(s.size() < p.size() - num_stars * 2)
            return false;

        if(num_stars == 0 && s.size() > p.size())
            return false;
        
        for(int i = 0; i < p.size(); i++)
        {
            if((i == p.size() - 1) ? (true) : (p[i + 1] != '*'))
            {
                if(p[i] == '.')
                    continue;
                if(p[i] != s[i])
                    return false;
                continue;
            }
            string s1 = s.substr(i);
            for(int j = 0; j <= s.size() - p.size() + 2 * num_stars + 1; j++)
            {
                string p1;
                p1.append(j, p[i]);
                p1.append(p.substr(i + 2));
                if(this->isMatch(s1, p1) == true)
                {
                    return true;
                }
            } 
            return false;
        }
        return true;
    }
};

int main()
{
    string s = "aaaaaaaaaaaaaaaaaaab";
    string p = "a*a*a*a*a*a*a*a*a*a*";

    Solution engine;
    bool res = engine.isMatch(s, p);
    cout<<res;
    return 0;
}