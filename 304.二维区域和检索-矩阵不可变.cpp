/*
 * @Author: PureDeep
 * @Date: 2020-11-01 22:56:26
 * @LastEditors: PureDeep
 * @LastEditTime: 2020-11-02 13:54:03
 * @FilePath: \LeetCode\304.二维区域和检索-矩阵不可变.cpp
 */
/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */
using namespace std;
#include <vector>
#include <iostream>

// @lc code=start
class NumMatrix
{
private:
    vector<vector<int>> tmp; //创建一个临时数组，里面存储（0，0）到（row2，col2）的子矩阵内部和

public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        if (matrix.size() == 0)
        {
            return;
        }
        int row = matrix.size(), col = matrix[0].size();
        for (int i = 0; i < row + 1; i++)
        {
            tmp.emplace_back(vector<int>(col + 1, 0));
        }
        for (int i = 1; i <= row; i++)
        {
            for (int j = 1; j <= col; j++)
            {
                tmp[i][j] = matrix[i - 1][j - 1] + tmp[i - 1][j] + tmp[i][j - 1] - tmp[i - 1][j - 1];
            }
        }
        for (int i = 0; i <= row; i++)
        {
            for (int j = 0; j <= col; j++)
            {
                cout << tmp[i][j] << " ";
            }
            cout << endl;
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int res = tmp[row2 + 1][col2 + 1] - tmp[row1][col2 + 1] - tmp[row2 + 1][col1] + tmp[row1][col1];
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
int main()
{
    vector<vector<int>> matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}};
    NumMatrix *ans = new NumMatrix(matrix);
    int res = ans->sumRegion(2, 1, 4, 3);
    cout << res << endl;
    res = ans->sumRegion(1, 1, 2, 2);
    cout << res << endl;
    res = ans->sumRegion(1, 2, 2, 4);
    cout << res << endl;
    return 0;
}