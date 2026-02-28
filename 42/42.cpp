/*
按从左到右的方向遍历：
寻找第一个**不比自身矮**的柱子，计算两个柱子间能盛的水的量，并加到总量里

按从右到左的方向遍历：
寻找第一个**比自身高**的柱子，计算两个柱子间能盛的水的量，并加到总量里
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
    int trap(vector<int> &height)
    {
        int res = 0;
        int left = 0, right = 1;
        int temp_area = 0;
        int highest_idx = 0;
        while(right < height.size())
        {
            if(height[right] < height[left])
            {
                temp_area += height[left] - height[right];
                right++;
                continue;
            }
            highest_idx = right;
            res += temp_area;
            temp_area = 0;
            left = right;
            right++;
        }
        right = height.size() - 1;
        left = right - 1;
        temp_area = 0;
        while(left >= highest_idx)
        {
            if(height[left] < height[right])
            {
                temp_area += height[right] - height[left];
                left--;
                continue;
            }
            res += temp_area;
            temp_area = 0;
            right = left;
            left--;
        }
        return res;
    }
};

int main()
{
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution solution;
    int res = solution.trap(height);
    printf("%d", res);
    return 0;
}