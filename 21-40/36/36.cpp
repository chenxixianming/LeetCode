#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution
{
    public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<unordered_map<char, bool>> rows(9), cols(9), sqrs(9);
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.')
                    continue;
                if(rows[i].count(board[i][j]))
                    return false;
                rows[i][board[i][j]] = true;
                if(cols[j].count(board[i][j]))
                    return false;
                cols[j][board[i][j]] = true;
                if(sqrs[(i / 3) * 3 + (j / 3)].count(board[i][j]))
                    return false;
                sqrs[(i / 3) * 3 + (j / 3)][board[i][j]] = true;
            }
        }
        return true;
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
    bool res = solution.isValidSudoku(board);
    printf("%d", res);
    return 0;
}