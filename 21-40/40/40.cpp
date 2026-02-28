#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution
{
    public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        unordered_map<int, int> cand_num;
        vector<vector<int>> res = {{}};
        vector<int> maps;
        for(auto i : candidates)
        {
            cand_num[i]++;
            if(cand_num[i] == 1)
                maps.push_back(i);
        }
        this->combine(cand_num, maps, res, 0, target);
        res.pop_back();
        return res;
    }

    private:
    void combine(unordered_map<int, int> &cand_num, const vector<int> &maps, vector<vector<int>> &res, int idx, int target)
    {
        for(int i = idx; i < maps.size(); i++)
        {
            for(int j = 1; j <= cand_num[maps[i]]; j++)
            {
                int rest = target - j * maps[i];
                if(rest < 0)
                    break;
                if(rest == 0)
                {
                    auto temp = res.back();
                    res.back().insert(res.back().end(), j, maps[i]);
                    res.push_back(temp);
                    break;
                }
                res.back().insert(res.back().end(), j, maps[i]);
                this->combine(cand_num, maps, res, i + 1, rest);
                res.back().resize(res.back().size() - j);
            }
        }
        return;
    }
};

int main()
{
    vector<int> candidates = {2,5,2,1,2};
    int target = 5;
    Solution solution;
    vector<vector<int>> res = solution.combinationSum2(candidates, target);
    for(auto i : res)
    {
        for(auto j : i)
        {
            printf("%d ", j);
        }
        printf("\n");
    }
    return 0;
}