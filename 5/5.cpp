#include<iostream>
#include<string>

using namespace std;

class Solution
{
    public:
    string longestPalindrome(string s)
    {
        int idx_last = s.size() - 1;
        int max_pali = 0;
        string res;
        for(int i = 0; i <= idx_last; i++)
        {
            int pali_odd = 1;
            int pali_even = (s[i + 1] == s[i]) ? 1 : 0;
            bool odd_label = true;
            bool even_label = (s[i + 1] == s[i]) ? true : false;

            string odd, even;
            odd.push_back(s[i]);
            even.push_back(s[i]);

            while(odd_label || even_label)
            {
                if(odd_label)
                {
                    if((i - pali_odd >= 0) && (i + pali_odd <= idx_last) && s[i - pali_odd] == s[i + pali_odd])
                    {
                        odd.push_back(s[i - pali_odd]);
                        pali_odd++;
                    }
                    else
                    {
                        odd_label = false;
                    }
                }

                if(even_label)
                {
                    if((i - pali_even >= 0) && (i + pali_even + 1) <= idx_last && s[i - pali_even] == s[i + pali_even + 1])
                    {
                        even.push_back(s[i - pali_even]);
                        pali_even++;
                    }
                    else
                    {
                        even_label = false;
                    }
                }
            }
            if(pali_odd * 2 - 1 > max_pali)
            {
                res = "";
                for(int j = odd.size() - 1; j > 0; j--)
                {
                    res.push_back(odd[j]);
                }
                res.append(odd);
                max_pali = pali_odd * 2 - 1;
            }
            if(pali_even * 2 > max_pali)
            {
                res = "";
                for(int j = even.size() - 1; j >= 0; j--)
                {
                    res.push_back(even[j]);
                }
                res.append(even);
                max_pali = pali_even * 2;
            }
        }
        return res;
    }
};

int main()
{
    string s = "abbcccba"; 

    Solution engine;

    string res = engine.longestPalindrome(s);
    cout<<res;
    return 0;
}