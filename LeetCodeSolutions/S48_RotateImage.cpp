#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Input:
// [ [1, 2, 3],
//   [4, 5, 6],
//   [7, 8, 9] ]

// Output:
// [ [7, 4, 1],
//   [8, 5, 2],
//   [9, 6, 3] ]

        /*
        思路:
		1. 先把矩阵沿着主对角线翻转（transpose），即matrix[i][j]和matrix[j][i]交换位置。
		2. 然后再把矩阵沿着垂直线翻转, 即
        */

        // 1. transpose
		int n = matrix.size();
        int n2 = matrix[0].size();
        for (int i = 0; i < n; ++i)
        {
			for (int j = 0; j < n2; ++j)
            {
                if (i < j) // 只交换上三角部分，避免重复交换
                {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n2/2; ++j)
            {
				swap(matrix[i][j], matrix[i][n2 - 1 - j]);
            }
        }


    }
};