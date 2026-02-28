#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

class Solution
{
    public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        const int num_words = words.size();
        if(num_words == 0 || s.size() < num_words * words[0].size())
        {
            return {};
        }
        vector<int> res;
        unordered_map<string, int> word_count;
        for(auto &i : words)
        {
            word_count[i] ++;
        }
        const int word_length = words[0].size();
        for(int i = 0; i < word_length; i++)
        {
            int left = i, right = i;
            int word_nums = 0;
            unordered_map<string, int> window_count;
            while(right + word_length <= s.size())
            {
                string temp = s.substr(right, word_length);
                right += word_length;
                if(word_count.count(temp))
                {
                    word_nums++;
                    window_count[temp]++;
                    while(window_count[temp] > word_count[temp])
                    {
                        string temp1 = s.substr(left, word_length);
                        window_count[temp1]--;
                        word_nums--;
                        left += word_length;
                    }
                    if(word_nums == num_words)
                    {
                        res.push_back(left);
                        string temp1 = s.substr(left, word_length);
                        window_count[temp1]--;
                        word_nums--;
                        left += word_length;
                    }
                    continue;
                }
                word_nums = 0;
                left = right;
                window_count.clear();
                continue;
            }
        }
        return res;
    }
};

int main()
{
    string s = "wordgoodgoodgoodbestword";
    vector<string> words = {"word","good","best","good"};

    Solution solution;
    vector<int> res = solution.findSubstring(s, words);
    for(auto &i : res)
    {
        printf("%d ", i);
    }
    return 0;
}