#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> findXSum(vector<int>& nums, int k, int x)
    {
        int lastP = nums.size() - k + 1;

        vector<int> answer(lastP);
        unordered_map<int,int> uoMap;
        for (int i = 0; i < lastP; i++)
        {
            // 收集
            uoMap.clear();
            for (int j = 0; j < k; j++)
            {
                int mapI = i + j;
                int num = nums[mapI];
                uoMap[num]++;
            }

            // 排序
            vector<pair<int, int>> pv;
            for (const auto& p : uoMap)
            {
                pv.emplace_back(p.second, p.first);
            }
            sort(pv.begin(), pv.end(), greater<pair<int, int>>());

            // 取和
            int sum = 0;
            for (int j = 0; j < pv.size() && j < x; j++)
            {
                sum += pv[j].first * pv[j].second;
            }

            answer[i] = sum;
        }

        return answer;

    }
};