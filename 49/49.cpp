#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>

class Solution
{
    public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs)
    {
        std::unordered_map<std::string, int> exist_str;
        std::vector<std::vector<std::string>> res;
        int idx = 0;

        for(auto i : strs)
        {
            std::string temp = i;
            std::sort(i.begin(), i.end());
            if(exist_str.count(i))
            {
                res[exist_str[i]].push_back(temp);
            }
            else
            {
                res.push_back({temp});
                exist_str[i] = idx;
                idx++;
            }
        }

        return res;
    } 
};

int main()
{
    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution sol;
    auto res = sol.groupAnagrams(strs);
    for(auto i : res)
    {
        for(auto j : i)
        {
            std::cout<<j<<' ';
        }
        printf("\n");
    }
}