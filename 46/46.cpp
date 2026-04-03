#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
    public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> curr;
        this->per(nums, res, curr);
        return res;
    }

    private:
    void per(vector<int> &nums, vector<vector<int>> &res, vector<int> &curr)
    {
        for(int i = 0; i < nums.size(); i++)
        {
            int temp = nums[i];
            curr.push_back(nums[i]);
            swap(nums[i], nums.back());
            nums.pop_back();
            if(nums.empty())
            {
                res.push_back(curr);
            }
            else
            {
                this->per(nums, res, curr);
            }
            nums.push_back(temp);
            swap(nums[i], nums.back());
            curr.pop_back();
        }
        return;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    Solution sol;
    vector<vector<int>> res = sol.permute(nums);
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