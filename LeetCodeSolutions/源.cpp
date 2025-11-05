#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    int maxIncreasingSubarrays(vector<int>& nums)
    {
        int n = nums.size();

        int maxK = 1;
        int maxSingleK = 2;

        for (int i = 0; i < n - 1; ++i)
        {
            cout << "=======---次数：" << i << endl;
            for (int x = i + 1; x < n; ++x)
            {
                int num = nums[x];
                int lastNum = nums[x - 1];
                int curK = x - i;
                if (num <= lastNum)
                { // 不符合

                    maxSingleK = max(maxSingleK, curK);
                    cout << curK << endl;
                    for (int y = x + 1; y < n; y++)
                    {
                        int num2 = nums[y];
                        int lastNum2 = nums[y - 1];

                        cout << "----- " << y - x << "last:" << lastNum2 << "num:" << num2 << endl;
                        if (num2 > lastNum2) // 符合
                        {
                            if (curK == y - x) // 前面的长度和第二轮k相等，找到了一个符合的数组对
                            {
                                maxK = max(maxK, curK);
                                break;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                    break;
                }
                else
                {
                    maxSingleK = max(maxSingleK, curK - 1);
                }
            }
        }

        if (maxK == 1)
        {
            return maxSingleK / 2;
        }
        return maxK;
    }
};