#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
    int jump(vector<int> &nums)
    {
        int left = 0, max_pos = 0;
        int target = nums.size() - 1;
        int res = 0;
        
        while(max_pos < target)
        {
            res++;
            int temp = max_pos;
            for(int i = left; i <= temp; i++)
            {
                if(i + nums[i] > max_pos)
                    max_pos = i + nums[i];
            }
            left = temp + 1;
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};
    Solution sol;
    int res = sol.jump(nums);
    printf("%d\n", res);
    return 0;
}