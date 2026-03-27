#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        /*
          n n
        m
        m
        */
        int m = matrix.size();
        int n = matrix[0].size();

        bool firstRowZero = false;
        bool firstColZero = false;

        for (int i = 0; i < n; ++i)
        {
            int num = matrix[0][i];
            if (num == 0) {
                firstRowZero = true;
                break;
            }
        }

        for (int i = 0; i < m; ++i)
        {
            int num = matrix[i][0];
            if (num == 0) {
                firstColZero = true;
                break;
            }
        }

        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                int num = matrix[i][j];
                if (num == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // 开始修改
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                int row = matrix[0][j];
                int column = matrix[i][0];
                if (row == 0 || column == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // 设置第一行和第一列
        if (firstRowZero)
        {
            for (int i = 0; i < n; ++i)
            {
                matrix[0][i] = 0;
            }
        }

        if (firstColZero)
        {
            for (int i = 0; i < m; ++i)
            {
                matrix[i][0] = 0;
            }
        }

    }
};