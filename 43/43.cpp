#include<iostream>
#include<string>
#include<vector>
#include<cstdint>
#include<algorithm>

using namespace std;

class Solution
{
    public:
    string multiply(string num1, string num2)
    {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int size1 = num1.size(), size2 = num2.size();
        vector<int8_t> res(size1 + size2, 0);
        for(int i = 0; i < size1; i++)
        {
            for(int j = 0; j < size2; j++)
            {
                int8_t n1 = num1[i] - '0';
                int8_t n2 = num2[j] - '0';
                int idx = i + j;
                res[idx] += n1 * n2;
                res[idx + 1] += res[idx] / 10;
                res[idx] %= 10;
            }
        }
        string s;
        for(int i = size1 + size2 - 1; i >= 0; i--)
        {
            if(s.empty() && res[i] == 0)
                continue;
            s.push_back('0' + res[i]);
        }
        if(s.empty())
            s = "0";
        return s;
    }
};

int main()
{
    string num1 = "123", num2 = "456";
    Solution solution;
    string res = solution.multiply(num1, num2);
    cout<< res;
    return 0;
}