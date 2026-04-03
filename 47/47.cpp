#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
    public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        if(nums.empty())
            return {};
        if(nums.size() == 1)
            return {nums};
        sort(nums.begin(), nums.end());
        bool label = true;
        vector<vector<int>> res = {nums};

        while(label)
        {
            label = false;
            for(int i = nums.size() - 1; i > 0; i--)
            {
                if(nums[i] > nums[i - 1])
                {
                    label = true;
                    for(int j = nums.size() - 1; j >= i; j--)
                    {
                        if(nums[j] > nums[i - 1])
                        {
                            swap(nums[j], nums[i - 1]);
                            sort(nums.begin() + i, nums.end());
                            res.push_back(nums);
                            goto next_it;
                        }
                    }
                }
            }
            next_it:
                ;
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {1, 1, 2, 2};
    Solution sol;
    auto res = sol.permuteUnique(nums);
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