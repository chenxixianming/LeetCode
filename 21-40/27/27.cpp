#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
    int removeElement(vector<int> &nums, int val)
    {
        int i = 0, j = nums.size() - 1;
        while(i <= j)
        {
            if(nums[i] == val && nums[j] != val)
            {
                swap(nums[i], nums[j]);
                i++; j--;
                continue;
            }
            if(nums[i] == val)
            {
                j--;
                continue;
            }
            i++;
            continue;
        }
        return i;
    }
};

int main()
{
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    Solution solution;
    int res = solution.removeElement(nums, val);
    printf("%d\n", res);
    for(auto i : nums)
    {
        printf("%d ", i);
    }
    return 0;
}