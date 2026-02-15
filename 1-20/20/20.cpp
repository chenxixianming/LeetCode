#include<iostream>
#include<stack>
#include<string>
#include<unordered_map>

using namespace std;

class Solution
{
    public:
    bool isValid(string s)
    {
        stack<char> left;
        unordered_map<char, char> parenthese;
        parenthese['('] = ')'; parenthese['['] = ']'; parenthese['{'] = '}';
        for(auto i: s)
        {
            if(i == '(' || i == '[' || i == '{')
            {
                left.push(i);
                continue;
            }
            if(left.empty())
                return false;
            if(parenthese[left.top()] != i)
                return false;
            left.pop();
        }
        if(left.empty())
            return true;
        return false;
    }
};

int main()
{
    string s = ")";
    Solution solution;
    bool res = solution.isValid(s);
    printf("%d", res);
    return 0;
}