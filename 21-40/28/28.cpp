#include<iostream>
#include<string>

using namespace std;

class Solution
{
    public:
    int strStr(string haystack, string needle)
    {
        
        int sizen = needle.size();
        if(haystack.size() < sizen)
            return -1;
        for(int i = 0; i < haystack.size() - sizen + 1; i++)
        {
            string temp = haystack.substr(i, sizen);
            if(temp == needle)
                return i;
        }
        return -1;
    }
};

int main()
{
    string haystack = "hello", needle = "lo";
    Solution solution;
    int res = solution.strStr(haystack, needle);
    printf("%d", res);
    return 0;
}