#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(target == nums[mid])
                return mid;
            if(target < nums[mid])
            {
                if(nums[mid] < nums[left])
                {
                    right = mid - 1;
                    continue;
                }
                if(target < nums[left])
                    left = mid + 1;
                else
                    right = mid - 1;
                continue;
            }
            if(nums[mid] > nums[right])
            {
                left = mid + 1;
                continue;
            }
            if(target > nums[right])
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
};

int main()
{
    vector<int> nums = {5,1,2,3,4};
    int target = 1;
    Solution solution;
    int res = solution.search(nums, target);
    printf("%d", res);
    return 0;
}