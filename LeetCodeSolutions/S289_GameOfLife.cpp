#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        /*
        使用不同的数字代表不同的含义,
        0  死亡
        1 存活
        2 更新死亡, 之前存活
        3 更新存活, 之前死亡
        */

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int value = board[i][j];

                int neighborCount = 0;
                for (int k = -1; k <= 1; ++k)
                {
                    int ik1 = i + k;
                    if (ik1 >= m) continue;
                    if (ik1 < 0) continue;
                    for (int k2 = -1; k2 <= 1; ++k2)
                    {
                        int ik2 = j + k2;
                        if (ik2 >= n) continue;
                        if (ik2 < 0) continue;
                        int neighborValue = board[ik1][ik2];
                        if (neighborValue == 1 || neighborValue == 2) ++neighborCount;
                    }
                }

                if (value == 1) {
                    --neighborCount;
                    
                    // rule 1.
                    if (neighborCount < 2)
                    {
                        board[i][j] = 2;    // 死亡
                    }
                    else if(neighborCount >3)
                    {
                        board[i][j] = 2;    // 死亡
                    }
                }
                else
                {
                    if (neighborCount == 3)
                    {
                        board[i][j] = 3;  // 复活
                    }
                }

                //std::cout << i << "-" << j << "  " << neighborCount << endl;
               
            }
        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int value = board[i][j];
                if (value == 2) board[i][j] = 0;
                if(value == 3) board[i][j] = 1;
            }
        }
    }
};