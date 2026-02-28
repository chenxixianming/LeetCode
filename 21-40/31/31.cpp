#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
    public:
    void nextPermutation(vector<int> &nums)
    {
        int right = nums.size() - 1;
        if(right <= 0)
            return;
        int i = right - 1, j = right;
        while(i >= 0 && nums[i] >= nums[i + 1])
            i--;
        if(i == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        while(j >= i && nums[i] >= nums[j])
            j--;
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
        return;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};
    Solution solution;
    solution.nextPermutation(nums);
    for(auto &i : nums)
    {
        printf("%d ", i);
    }
    return 0;
}