#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>

using namespace std;

class Solution
{
    public:
    vector<string> letterCombinations(string digits)
    {
        unordered_map<char, string> map;
        map['2'] = "abc"; map['3'] = "def";
        map['4'] = "ghi"; map['5'] = "jkl";
        map['6'] = "mno"; map['7'] = "pqrs";
        map['8'] = "tuv"; map['9'] = "wxyz";

        vector<string> res;

        for(auto i : map[digits[0]])
        {
            string res1;
            res1.push_back(i);
            if(digits.size() == 1)
            {
                res.push_back(res1);
                continue;
            }
            for(auto j : map[digits[1]])
            {
                string res2 = res1;
                res2.push_back(j);
                if(digits.size() == 2)
                {
                    res.push_back(res2);
                    continue;
                }
                for(auto k : map[digits[2]])
                {
                    string res3 = res2;
                    res3.push_back(k);
                    if(digits.size() == 3)
                    {
                        res.push_back(res3);
                        continue;
                    }
                    for(auto l : map[digits[3]])
                    {
                        string res4 = res3;
                        res4.push_back(l);
                        res.push_back(res4);
                    }
                }
            }
        }
        return res;        
    }
};

int main()
{
    string digits = "23";
    Solution engine;
    vector<string> res = engine.letterCombinations(digits);
    for(auto i : res)
    {
        cout<<i<<'\n';
    }
    return 0;
}