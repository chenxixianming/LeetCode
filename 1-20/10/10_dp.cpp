#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
    bool isMatch(string s, string p)
    {
        vector<vector<bool>> map(s.size() + 1, vector<bool>(p.size() + 1, false));
        map[0][0] = true;
        for(int i = 0; i <= s.size(); i++)
        {
            for(int j = 1; j <= p.size(); j++)
            {
                if(p[j - 1] == '*')
                {
                    if(i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.'))
                        map[i][j] = map[i - 1][j];
                    map[i][j] = map[i][j] || map[i][j - 2];
                }
                if(i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.'))
                {
                    map[i][j] = map[i - 1][j - 1];
                }
            }
        }
        return map[s.size()][p.size()];
    }
};

int main()
{
    string s = "";
    string p = "a*a*a*a*a*a*a*a*a*a*";

    Solution engine;
    bool res = engine.isMatch(s, p);
    cout<<res;
    return 0;
}