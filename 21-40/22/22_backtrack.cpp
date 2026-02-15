#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution
{
    public:
    vector<string> generateParenthesis(int n)
    {
        int left = 0, right = 0;
        vector<string> res;
        string s;
        this->single(res, left, right, s, n);
        return res;
    }
    private:
    void single(vector<string> &res, int left, int right, string &s, int n)
    {
        if(left + right == 2 * n)
        {
            res.push_back(s);
            return;
        }
        if(left == n)
        {
            s.push_back(')');
            this->single(res, left, right + 1, s, n);
            s.pop_back();
            return;
        }
        s.push_back('(');
        this->single(res, left + 1, right, s, n);
        s.pop_back();
        if(left > right)
        {
            s.push_back(')');
            this->single(res, left, right + 1, s, n);
            s.pop_back();
        }
        return;
    }
};

int main()
{
    int n = 4;
    Solution solution;
    vector<string> res = solution.generateParenthesis(n);
    for(auto i : res)
    {
        cout<< i << '\n';
    }
    return 0;
}