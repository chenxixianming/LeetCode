#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

class roman_type
{
    public:
    char five, ten;
    int num;
    roman_type(int x) : num(x), five('\0'), ten('\0') {}
    roman_type(int x, char a, char b) : num(x), five(a), ten(b) {}
};

class Solution
{
    public:
    int romanToInt(string s)
    {
        roman_type *I = new roman_type(1, 'V', 'X');
        roman_type *V = new roman_type(5);
        roman_type *X = new roman_type(10, 'L', 'C');
        roman_type *L = new roman_type(50);
        roman_type *C = new roman_type(100, 'D', 'M');
        roman_type *D = new roman_type(500);
        roman_type *M = new roman_type(1000);
        
        unordered_map<char, roman_type *> map;
        map['I'] = I; map['V'] = V;
        map['X'] = X; map['L'] = L;
        map['C'] = C; map['D'] = D;
        map['M'] = M;

        int res = 0;

        for(int i = 0; i < s.size(); i++)
        {
            res += map[s[i]]->num;
            if((i != s.size() - 1) && (map[s[i]]->five == s[i + 1] || map[s[i]]->ten == s[i + 1]))
                res -= 2 * map[s[i]]->num;
        }
        delete I; delete V; delete X; delete L;
        delete C; delete D; delete M;
        return res;
    }
};

int main()
{
    string s = "MCMXCIV";
    Solution engine;
    int res = engine.romanToInt(s);
    printf("%d", res);
    return 0;
}