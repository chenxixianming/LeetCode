#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
    int maxArea(vector<int> &height)
    {
        int max_area = 0;
        int i = 0, j = height.size() - 1;
        while(i != j)
        {
            int minih = min(height[i], height[j]);
            int area = (j - i) * minih;
            if(area > max_area)
                max_area = area;
            if(height[i] == minih)
            {
                i++;
                continue;
            }
            j--;
        }
        return max_area;
    }
};

int main()
{
    vector<int> height = {1, 1};
    Solution engine;
    int res = engine.maxArea(height);
    printf("%d", res);
    return 0;
}