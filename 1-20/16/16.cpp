#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
    public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int res = 100000;
        int sizen = nums.size();
        for(int i = 0; i < sizen - 2; i++)
        {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = sizen - 1;
            while(j < k)
            {
                int sum3 = nums[i] + nums[j] + nums[k];
                if(sum3 == target)
                {
                    return target;
                }
                if(abs(sum3 - target) < abs(res - target))
                    res = sum3;
                int x = 1;
                if(sum3 < target)
                {
                    while(nums[j] == nums[j + x])
                    {
                        x++;
                        if(j + x >= k)
                            break;
                    }
                    j += x;
                    continue;
                }
                x = 1;
                while(nums[k] == nums[k - x])
                {
                    x++;
                    if(k - x <= j)
                        break;
                }
                k -= x;
            }
        }
        return res;
    }
};

int main()
{
    int target = 1;
    vector<int> nums = {0, 0, 0};
    Solution engine;
    int res = engine.threeSumClosest(nums, target);
    printf("%d", res);
    return 0;
}