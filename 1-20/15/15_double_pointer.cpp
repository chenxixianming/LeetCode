#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
    public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int sizen = nums.size();
        for(int i = 0; i < sizen - 2; i++)
        {
            if((i > 0) && (nums[i] == nums[i - 1]))
                continue;
            int m = i + 1, n = sizen - 1;
            while(m < n)
            {
                int j = 1;
                if(nums[i] + nums[m] + nums[n] == 0)
                {
                    res.push_back({nums[i], nums[m], nums[n]});
                    while(nums[m + j] == nums[m])
                    {
                        j++;
                        if(m + j >= n)
                            break;
                    }
                    m += j;
                    j = 1;
                    while(nums[n - j] == nums[n])
                    {
                        j++;
                        if(n - j <= m)
                            break;
                    }
                    n -= j;
                    continue;
                }
                if(nums[i] + nums[m] + nums[n] < 0)
                {
                    while(nums[m + j] == nums[m])
                    {
                        j++;
                        if(m + j >= n)
                            break;
                    }
                    m += j;
                    continue;
                }
                while(nums[n - j] == nums[n])
                {
                    j++;
                    if(n - j <= m)
                        break;
                }
                n -= j;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {0, 0, 0};
    Solution engine;
    vector<vector<int>> res = engine.threeSum(nums);
    for(auto i : res)
    {
        for(auto j : i)
        {
            printf("%d ", j);
        }
        printf("\n");
    }
    return 0;
}