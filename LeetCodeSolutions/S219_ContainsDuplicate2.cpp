#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> windowSet;
        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            int num = nums[i];
            // first, we check the window
            if (i > k)
            {
                int oldIndex = i - k - 1;
                windowSet.erase(nums[oldIndex]);
            }
            // then, we check if we got result.
            if (windowSet.find(num) != windowSet.end())
            {
                return true;
            }

            windowSet.insert(num);
        }

        return false;
    }
};