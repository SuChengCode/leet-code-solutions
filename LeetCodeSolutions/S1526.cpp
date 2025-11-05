#include <iostream>
#include <vector>

using namespace std;

/*
You are given an integer array target. You have an integer array initial of the same size as target with all elements initially zeros.

In one operation you can choose any subarray from initial and increment each value by one.

Return the minimum number of operations to form a target array from initial.

The test cases are generated so that the answer fits in a 32-bit integer.
*/

class Solution
{
public:
    int minNumberOperations(vector<int>& target)
    {
        int n = target.size();
        int result = 0;

        int highest = target[0];
        int highestIndex = 0;
        int lastHeight = target[0];
        for (int i = 1; i < n; ++i)
        {
            int height = target[i]; 

            if (height >= highest && highestIndex == i - 1)  // 正在上升. (高于最高，且上个也是最高点)
            {
                highest = height;
                highestIndex = i;
            }
            else
            {
                if (height > lastHeight)    // 开始走高，上次已经到达底部
                {                    // 结算山峰值
                    int diff = highest - lastHeight;    // 最高点到最低点(上个点)差值
                    result += diff;

                    //cout << "结算:" << i << " value+:" << diff << endl;

                    highest = height;
                    highestIndex = i;
                }
            }
            lastHeight = height;
        }

        // 结算最后一个
        result += highest;

        return result;
    }
};
