#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution
{
    public:
    string countAndSay(int n)
    {
        vector<pair<int, int>> start = {{1, 1}};
        for(int i = 1; i < n; i++)
        {
            vector<pair<int, int>> curr;
            int curr_num = -1;
            int count = 1;
            for(auto j : start)
            {
                if(j.first == curr_num)
                {
                    count += 1;
                }
                else
                {
                    if(curr_num != -1)
                        curr.push_back({count, curr_num});
                    count = 1;
                    curr_num = j.first;
                }
                if(j.second == curr_num)
                {
                    count += 1;
                }
                else
                {
                    curr.push_back({count, curr_num});
                    count = 1;
                    curr_num = j.second;
                }
            }
            curr.push_back({count, curr_num});
            start = curr;
        }
        string res;
        for(auto i : start)
        {
            for(int j = 0; j < i.first; j++)
            {
                res.push_back(i.second + '0');
            }
        }
        return res;
    }
};

int main()
{
    int n = 5;
    Solution solution;
    string res = solution.countAndSay(n);
    cout << res;
    return 0;
}