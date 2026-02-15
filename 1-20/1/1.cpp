#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target);

private:

};

vector<int> Solution::twoSum(vector<int>& nums, int target)
{
	for (int i = 0; i < nums.size(); i++)
	{
		int other = target - nums[i];

		for (int j = 0; j < nums.size(); j++)
		{
			if (nums[j] == other && j != i)
			{
				vector<int> res;
				res.push_back(i);
				res.push_back(j);
				return res;
			}
		}
	}
    return {};
}

int main()
{
	int target_num = 9;
	vector<int> nums = { 2,7,11,15 };

	Solution t;
	vector<int> res = t.twoSum(nums, target_num);

	cout << res[0] << ' ' << res[1];
}