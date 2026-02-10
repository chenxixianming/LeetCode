#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution
{
    public:
    vector<vector<int>> threeSum(vector<int> &num)
    {
        sort(num.begin(), num.end());
        vector<vector<int>> res;
        vector<int> nums = {num[0], num[1], num[2]};
        int j = 3;
        while(j < num.size())
        {
            if(num[j] == num[j - 1] && num[j] == num[j - 2] && num[j] == num[j - 3])
            {
                j++;
                continue;
            }
            nums.push_back(num[j]);
            j++;
        }
        for(int i = 0; i < nums.size() - 2; i++)
        {
            unordered_map<int, int> visited;
            int target = -nums[i];
            if(target < 0)
                break;
            for(int j = i + 1; j < nums.size(); j++)
            {
                if(visited.count(target - nums[j]))
                {
                    vector<int> curr = {nums[i], target - nums[j], nums[j]};
                    // sort(curr.begin(), curr.end());
                    res.push_back(curr);
                }
                visited[nums[j]] = j;
            }
        }
        sort(res.begin(), res.end());
        int i = 1;
        while(i < res.size())
        {
            if(res[i] == res[i - 1])
            {
                res.erase(res.begin() + i);
                continue;
            }
            i++;
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {-1,0,1,2,-1,-4};
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