#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        long long sum = 0;
        long long maximum = LONG_LONG_MIN;
        const unsigned int n = nums.size();

        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            maximum = max(maximum, sum);

            if (sum < 0) {
                sum = 0;
            }
        }
        return static_cast<int>(maximum);
    }
};
