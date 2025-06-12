#include <vector>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int> &nums) {
        int result = INT_MIN;
        const int numsSize = nums.size();
        for (int i = 1; i < numsSize; ++i) {
            result = max(result, abs(nums[i] - nums[i - 1]));
        }
        result = max(result, abs(nums[0] - nums[numsSize - 1]));
        return result;
    }
};
