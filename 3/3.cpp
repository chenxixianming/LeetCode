#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution
{
    public:
    int lengthOfLongestSubstring(string s)
    {
        if(s.empty())
            return 0;
        int i = 0;
        int res = 1;
        while(i + res < s.length())
        {
            int length = 0;
            vector<int> vocab(128);

            for(int j = i; j < s.length(); j++)
            {
                if(vocab[s[j]] == 1)
                {
                    length = j - i;
                    break;
                }
                vocab[s[j]] = 1;
                if(j == s.length() - 1)
                    length = j - i + 1;
            }
            if(length > res)
            {
                res = length;
            }
            i++;
        }
        return res;
    }
};

int main()
{
    string s = "au";

    Solution sol;
    int res = sol.lengthOfLongestSubstring(s);
    printf("%d", res);
    return 0;
}