#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Solution
{
    public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size(), n = nums2.size();
        int left = 0, right = m;
        
        while(left <= right)
        {
            int i = (left + right + 1) / 2;
            int j = (m + n + 1) / 2 - i;

            int l1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int r1 = (i == m) ? INT_MAX : nums1[i];
            int l2 = (j == 0) ? INT_MIN : nums2[j - 1]; 
            int r2 = (j == n) ? INT_MAX : nums2[j];
            
            if(l1 > r2)
            {
                right = i - 1; 
                continue;
            }

            if(l2 > r1)
            {
                left = i;
                continue;
            }

            if((m + n) % 2 == 1)
            {
                return (double)max(l1, l2);
            }

            return (double)(max(l1, l2) + min(r1, r2)) / 2;

        }

        return 0.0;
    }
};

int main()
{
    vector<int> nums1 = {-10, -9, -8};
    vector<int> nums2 = {1, 2};

    Solution engine;
    double res = engine.findMedianSortedArrays(nums1, nums2);
    printf("%lf", res);
    return 0;
}