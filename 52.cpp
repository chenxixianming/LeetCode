#include<iostream>
#include<vector>
#include<string>
#include<utility>

class Solution
{
    public:
    int totalNQueens(int n)
    {
        std::vector<std::string> board(n, std::string(n, '*'));
        std::vector<std::vector<std::string>> res;
        this->next_queen(board, res, 0, n);
        return res.size();
    }

    private:
    void next_queen(std::vector<std::string> &board, std::vector<std::vector<std::string>> &res, const int &curr, const int n)
    {
        for(int i = 0; i < n; i++)
        {
            if(board[curr][i] == '*')
            {
                board[curr][i] = 'Q';
                if(curr == n - 1)
                {
                    res.push_back(board);
                    board[curr][i] = '*';
                    return;
                }

                std::vector<std::pair<int, int>> to_recover = {{curr, i}};

                for(int j = 0; j < n; j++)
                {
                    if(board[curr][j] == '*')
                    {
                        to_recover.push_back({curr, j});
                        board[curr][j] = '.';
                    }
                }
                for(int j = curr + 1; j < n; j++)
                {
                    if(board[j][i] == '*')
                    {
                        to_recover.push_back({j, i});
                        board[j][i] = '.';
                    }
                }
                int row = curr + 1, col = i + 1;
                while(row < n && col < n)
                {
                    if(board[row][col] == '*')
                    {
                        to_recover.push_back({row, col});
                        board[row][col] = '.';
                    }
                    row++; col++;
                }
                row = curr + 1; col = i - 1;
                while(row < n && col >= 0)
                {
                    if(board[row][col] == '*')
                    {
                        to_recover.push_back({row, col});
                        board[row][col] = '.';
                    }
                    row++; col--;
                }
                this->next_queen(board, res, curr + 1, n);
                for(auto i : to_recover)
                {
                    board[i.first][i.second] = '*';
                }
            }
        }
        return;
    }
};

int main()
{
    int n = 4;
    Solution sol;
    auto res = sol.totalNQueens(n);
    printf("%d", res);
    return 0;
}