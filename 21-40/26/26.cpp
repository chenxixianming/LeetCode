#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
    int removeDuplicates(vector<int> &nums)
    {
        if(nums.size() == 1)
            return 1;
        int i = 1;
        int temp = nums[0];
        for(int j = 1; j < nums.size(); j++)
        {
            if(nums[j] == temp)
                continue;
            swap(nums[i], nums[j]);
            temp = nums[i];
            i++;
        }
        return i;
    }
};

int main()
{
    vector<int> nums = {1, 1, 2};
    Solution solution;
    int res = solution.removeDuplicate(nums);
    for(int i = 0; i < res; i++)
    {
        printf("%d ", nums[i]);
    }
    return 0;
}