#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
};

int main()
{
    vector<int> nums = {1, 3, 5, 6};
    int target = 0;
    Solution solution;
    int res = solution.searchInsert(nums, target);
    printf("%d", res);
    return 0;
}