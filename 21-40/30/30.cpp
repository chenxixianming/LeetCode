#include<string>
#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        int num_words = words.size();
        if(num_words == 0 || s.size() < num_words * words[0].size())
        {
            return {};
        }
        int word_length = words[0].size();
        vector<int> res;
        for(int i = 0; i <= s.size() - num_words * words[0].size(); i++)
        {
            if(findstring(s, words, num_words, word_length, i))
            {
                res.push_back(i);
            }
        }
        return res;
    }

    private:
    bool findstring(const string s, vector<string> &words, int num_words, const int &word_length, int start)
    {
        if(num_words == 0)
        {
            return true;
        }
        string sub = s.substr(start, words[0].size());
        for(int i = 0; i < num_words; i++)
        {
            if(sub == words[i])
            {
                swap(words[i], words[num_words - 1]);
                return findstring(s, words, num_words - 1, word_length, start + word_length);
            }
        }
        return false;
    }
};

int main()
{
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};

    Solution solution;
    vector<int> res = solution.findSubstring(s, words);
    for(auto &i : res)
    {
        printf("%d ", i);
    }
    return 0;
}