#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
    public:
    int firstMissingPositive(vector<int> &nums)
    {
        nums.push_back(0);
        swap(nums[0], nums.back());
        int right = nums.size() - 1;
        int i = 0;
        while(i < right)
        {
            if(nums[i] > right || nums[i] < 0)
            {
                swap(nums[i], nums[right]);
                right--;
                continue;
            }
            if(nums[i] == i)
            {
                i++;
                continue;
            }
            if(nums[nums[i]] == nums[i])
            {
                swap(nums[i], nums[right]);
                right--;
                continue;
            }
            swap(nums[nums[i]], nums[i]);
        }
        for(i = 0; i < nums.size(); i++)
        {
            if(i != nums[i])
            {
                // i++;
                break;
            }
        }
        return i;
    }
};

int main()
{
    vector<int> nums = {1};
    Solution solution;
    int res = solution.firstMissingPositive(nums);
    printf("%d", res);
    return 0;
}