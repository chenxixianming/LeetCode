#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
    int jump(vector<int> &nums)
    {
        int res = 0;
        int target = nums.size() - 1;
        while(target != 0)
        {
            for(int i = 0; i <= target; i++)
            {
                if(nums[i] + i >= target)
                {
                    target = i;
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {2, 3, 0, 1, 4};
    Solution sol;
    int res = sol.jump(nums);
    printf("%d", res);
    return 0;
}