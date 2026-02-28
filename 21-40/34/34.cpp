#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if(nums.empty())
            return {-1, -1};
        int left = 0, right = nums.size() - 1;
        vector<int> res;
        while(left < right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] < target)
            {
                left = mid + 1;
                continue;
            }
            right = mid - 1;
        }
        if(right < 0)
            right = 0;
        if(nums[right] == target)
        {
            res.push_back(right);
        }
        else if(right < nums.size() - 1 && nums[right + 1] == target)
        {
            res.push_back(right + 1);
        }
        else
            return {-1, -1};
        
        left = 0; right = nums.size() - 1;
        while(left < right)
        {
            int mid = (left + right + 1) / 2;
            if(nums[mid] <= target)
            {
                left = mid + 1;
                continue;
            }
            right = mid - 1;
        }
        if(left >= nums.size())
            left = nums.size() - 1;
        if(nums[left] == target)
        {
            res.push_back(left);
        }
        else
            res.push_back(left - 1);
        return res;
    }
};

int main()
{
    vector<int> nums = {2, 2};
    int target = 2;
    Solution solution;
    vector<int> res = solution.searchRange(nums, target);
    printf("%d %d", res[0], res[1]);
    return 0;
}