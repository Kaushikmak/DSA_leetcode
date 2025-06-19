#include <vector>
#include <algorithm>

// refer 3 sum in medium to get idea

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        // Step 1: Store value + original index
        vector<pair<int, int>> numWithIndex;
        for (int i = 0; i < n; ++i) {
            numWithIndex.push_back({nums[i], i}); // {value,index}
        }

        // Step 2: Sort the array by value
        sort(numWithIndex.begin(), numWithIndex.end());

        // Step 3: Use two pointers
        int left = 0, right = n - 1;
        while (left < right) {
            int sum = numWithIndex[left].first + numWithIndex[right].first;
            if (sum == target) {
                return {numWithIndex[left].second, numWithIndex[right].second};
            } else if (sum < target) {
                ++left;
            } else {
                --right;
            }
        }

        return {}; // no valid pair
    }
};
