#include <iostream>
#include <vector>

using namespace std;

// problem 54
/*
1  2  3  4
5  6  7  8
9  10 11 12
*/
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> result;
        int m = matrix.size();
        int n = matrix[0].size();

        int ar = 0, ac = 0;
        int direc = 1;
        int rcDirec = 1;
        int rCount = m;
        int cCount = n;

        while (result.size() < m*n)
        {
            //cout << "==================" << endl;
            // column move
            for (int c = 0; c < cCount; ++c)
            {
                int num = matrix[ar][ac];
                //cout << "r: " << ar << " c: " << ac << " num: " << num << endl;
                result.push_back(num);
                ac += direc;
            }
            ac -= direc;
            ar += rcDirec;
            rCount--;
            rcDirec *= -1;
            // row move
            for (int r = 0; r < rCount; ++r)
            {
                int num = matrix[ar][ac];
                //cout << "r: " << ar << " c: " << ac << " num: " << num << endl;
                result.push_back(num);
                ar += direc;
            }
            ar -= direc;
            ac += rcDirec;
            cCount--;
            direc *= -1;
        }

        return result;
       
    }
};