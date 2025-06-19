#include <vector>
#include <algorithm>
#include <variant>

/*
Optimized Strategy Overview
Sort the array → so that duplicates are adjacent and easier to skip, and we can use the two-pointer technique.

Loop through each index i and:

Use two pointers: left (i+1) and right (end of array).

Check if nums[i] + nums[left] + nums[right] == 0.

Move pointers inward to find valid triplets.

Skip duplicates to avoid repeated triplets.
*/

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &nums) {
        vector<vector<int> > result;
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; ++i) {
            // remove duplicates
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            // converted to 2 pointers
            // i.e. nums[i] + nums[j] = -k
            // from O(n^3) to O(n^2)
            // nums[left] + nums[right] = - nums[i]
            int left = i+1;
            int right = n-1;
            int target = -nums[i];
            while (left<right) {
                int sum = nums[left] + nums[right];
                if (sum==target) {
                    result.push_back({nums[i],nums[left],nums[right]});

                    while (left<right && nums[left]==nums[left+1]) {
                        left++;
                    }
                    while (right>left && nums[right]==nums[right-1]) {
                        right--;
                    }
                    left++;
                    right--;

                }else if (target>sum) {
                    left++;
                }else {
                    right--;
                }
            }

        }
        return result;
    }
};
