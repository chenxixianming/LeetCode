#include<iostream>
#include<vector>
#include<algorithm>

class Solution
{
    public:
    void rotate(std::vector<std::vector<int>> &matrix)
    {
        for(int i = 1; i < matrix.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j <= (matrix.size() - 1) / 2; j++)
            {
                std::swap(matrix[i][j], matrix[i][matrix.size() - 1 - j]);
            }
        }
        return;
    }
};

int main()
{
    std::vector<std::vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    Solution sol;
    sol.rotate(matrix);
    for(auto i : matrix)
    {
        for(auto j : i)
        {
            printf("%d ", j);
        }
        printf("\n");
    }
    return 0;
}