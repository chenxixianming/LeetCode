#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
    public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int i = 0, j = nums.size() - 1;
        if(j < 3)
            return res;
        for(; i < nums.size() - 3; i++)
        {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            for(j = nums.size() - 1; j > i + 2; j--)
            {
                if(j < nums.size() - 1 && nums[j] == nums[j + 1])
                    continue;
                int m = i + 1, n = j - 1;
                while(m < n)
                {
                    int x = 1;
                    if((long long)nums[i] + (long long)nums[j] + (long long)nums[m] + (long long)nums[n] == (long long)target)
                    {
                        res.push_back({nums[i], nums[m], nums[n], nums[j]});
                        while(nums[m] == nums[m + x])
                        {
                            x++;
                            if(m + x >= n)
                                break;
                        }
                        m += x;
                        x = 1;
                        while(nums[n] == nums[n - x])
                        {
                            x++;
                            if(m >= n - x)
                                break;
                        }
                        n -= x;
                        continue;
                    }
                    if((long long)nums[i] + (long long)nums[j] + (long long)nums[m] + (long long)nums[n] < (long long)target)
                    {
                        while(nums[m] == nums[m + x])
                        {
                            x++;
                            if(m + x >= n)
                                break;
                        }
                        m += x;
                        continue;
                    }
                    while(nums[n] == nums[n - x])
                    {
                        x++;
                        if(m >= n - x)
                            break;
                    }
                    n -= x;
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {0};
    int target = 0;

    Solution engine;
    vector<vector<int>> res = engine.fourSum(nums, target);
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