#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution
{
    public:
    void solveSudoku(vector<vector<char>> &board)
    {
        vector<int> rows(9, 0), cols(9, 0), sqrs(9, 0);
        vector<vector<int>> to_fill;
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.')
                {
                    to_fill.push_back({i, j});
                    continue;
                }
                int num = board[i][j] - '0';
                rows[i] = rows[i] | (1 << num);
                cols[j] = cols[j] | (1 << num);
                sqrs[(i / 3) * 3 + (j / 3)] = sqrs[(i / 3) * 3 + (j / 3)] | (1 << num);
            }
        }
        bool is_full = false;
        this->solve(board, to_fill, rows, cols, sqrs, is_full, 0);
        return;
    }

    private:
    bool solve(vector<vector<char>> &board, vector<vector<int>> &to_fill, vector<int> &rows, vector<int> &cols, vector<int> &sqrs, bool &is_full, int idx)
    {
        if(idx == to_fill.size())
        {
            return true;
        }
        int row = to_fill[idx][0], col = to_fill[idx][1];
        int sqr = (row / 3) * 3 + (col / 3);
        idx++;
        int label = rows[row] | cols[col] | sqrs[sqr];
        for(int i = 1; i <= 9; i++)
        {
            if((label & (1 << i)) == 0)
            {
                board[row][col] = i + '0';
                rows[row] |= 1 << i;
                cols[col] |= 1 << i;
                sqrs[sqr] |= 1 << i;
                if(this->solve(board, to_fill, rows, cols, sqrs, is_full, idx))
                    return true;
                rows[row] ^= 1 << i;
                cols[col] ^= 1 << i;
                sqrs[sqr] ^= 1 << i;
            }
        }
        board[row][col] = '.';
        idx--;
        return false;
    }
};

int main()
{
    vector<vector<char>> board;
    board.push_back({'5','3','.','.','7','.','.','.','.'});
    board.push_back({'6','.','.','1','9','5','.','.','.'});
    board.push_back({'.','9','8','.','.','.','.','6','.'});
    board.push_back({'8','.','.','.','6','.','.','.','3'});
    board.push_back({'4','.','.','8','.','3','.','.','1'});
    board.push_back({'7','.','.','.','2','.','.','.','6'});
    board.push_back({'.','6','.','.','.','.','2','8','.'});
    board.push_back({'.','.','.','4','1','9','.','.','5'});
    board.push_back({'.','.','.','.','8','.','.','7','9'});

    Solution solution;
    solution.solveSudoku(board);
    for(auto i : board)
    {
        for(auto j : i)
        {
            printf("%c ", j);
        }
        printf("\n");
    }
    return 0;
}