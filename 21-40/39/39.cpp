#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
    public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res = {{}};
        sort(candidates.begin(), candidates.end());
        this->combine(candidates, target, 0, 0, res);
        res.pop_back();
        return res;
    }
    private:
    void combine(vector<int> &candidates, int &target, int curr, int idx, vector<vector<int>> &res)
    {
        for(int i = idx; i < candidates.size(); i++)
        {
            if(curr + candidates[i] > target)
            {
                return;
            }
            if(curr + candidates[i] == target)
            {
                auto temp = res.back();
                res.back().push_back(candidates[i]);
                res.push_back(temp);
                return;
            }
            res.back().push_back(candidates[i]);
            this->combine(candidates, target, curr + candidates[i], i, res);
            res.back().pop_back();
        }
        return;
    }
};

int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    Solution solution;
    vector<vector<int>> res = solution.combinationSum(candidates, target);
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