#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls)
    {
        // 0 for empty, 1=guard ,2 = wall, 3 = guarded
        vector<vector<int>> grids(m,vector<int>(n,0));

        int guardCount = guards.size();
        int wallCount = walls.size();
        for (int i = 0; i < guards.size(); i++)
        {
            vector<int> pos = guards[i];
            grids[pos[0]][pos[1]] = 1;
        }

        for (int i = 0; i < walls.size(); i++)
        {
            vector<int> pos = walls[i];
            grids[pos[0]][pos[1]] = 2;
        }

        int guardedCount = 0;
        for (int i = 0; i < guards.size(); i++)
        {
            int r = guards[i][0];
            int c = guards[i][1];
            int girdValue = grids[r][c];

            // left
            for (int j = r - 1; j >= 0; --j)
            {
                girdValue = grids[j][c];
                if (girdValue == 0)
                {
                    guardedCount++;
                    grids[j][c] = 3;
                }
                else if (girdValue == 3)
                {
                    continue;
                }
                else
                {
                    break;
                }
            }

            // up
            for (int j = c + 1; j < n; ++j)
            {
                girdValue = grids[r][j];
                if (girdValue == 0)
                {
                    guardedCount++;
                    grids[r][j] = 3;
                }
                else if (girdValue == 3)
                {
                    continue;
                }
                else
                {
                    break;
                }
            }

            // right
            for (int j = r + 1; j < m; ++j)
            {
                girdValue = grids[j][c];
                if (girdValue == 0)
                {
                    guardedCount++;
                    grids[j][c] = 3;
                }
                else if (girdValue == 3)
                {
                    continue;
                }
                else
                {
                    break;
                }
            }

            // down
            for (int j = c - 1; j >= 0; --j)
            {
                girdValue = grids[r][j];
                if (girdValue == 0)
                {
                    guardedCount++;
                    grids[r][j] = 3;
                }
                else if (girdValue == 3)
                {
                    continue;
                }
                else
                {
                    break;
                }
            }
        }

        return m * n - guardedCount - guardCount - wallCount;
    }
};
