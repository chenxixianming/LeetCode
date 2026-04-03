#include<iostream>
#include<vector>

class Solution
{
    public:
    int maxSubArray(std::vector<int> &nums)
    {
        int sum = 0;
        std::vector<int> left, right;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if(sum < 0)
            {
                left.push_back(i);
                sum = 0;
            }
        }
        sum = 0;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            sum += nums[i];
            if(sum < 0)
            {
                right.push_back(i);
                sum = 0;
            }
        }
    }
};

int main()
{
    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution sol;
    int res = sol.maxSubArray(nums);
    printf("%d", res);
    return 0;
}