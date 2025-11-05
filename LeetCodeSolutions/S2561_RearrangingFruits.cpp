#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{

public:
	// See https://leetcode.com/problems/rearranging-fruits/solutions/7030240/rearranging-fruits/
	long long minCost(vector<int>& basket1, vector<int>& basket2)
	{
		int m = INT_MAX;
		unordered_map<int, int> frequncyMap;
		for (int b1 : basket1)
		{
			frequncyMap[b1]++;
			m = min(m, b1);
		}
		for (int b2 : basket2)
		{
			frequncyMap[b2]--;
			m = min(m, b2);
		}

		vector<int> merge;

		for (auto& kv : frequncyMap)
		{
			if (kv.second % 2 != 0)
			{
				return -1;
			}
			for (int i = 0; i < abs(kv.second) / 2; ++i)
			{
				merge.push_back(kv.first);
			}
		}

		nth_element(merge.begin(), merge.begin() + merge.size() / 2, merge.end());

		long long sum = 0;
		for (size_t i = 0; i < merge.size() / 2; ++i)
		{
			sum += min(2 * m, merge[i]);
		}
		return sum;

	}
};



