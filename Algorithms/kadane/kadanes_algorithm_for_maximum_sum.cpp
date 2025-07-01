#include <limits.h>
#include <vector>

using namespace std;

// https://www.youtube.com/watch?v=AHZpyENo7k4

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

    vector<int> maxSubArrayVector(vector<int> &nums) {
        long long sum = 0;
        long long maximum = LONG_LONG_MIN;
        const unsigned int n = nums.size();
        int start = -1;
        int end = -1;
        int tempStart = 0;

        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (sum > maximum) {
                maximum = sum;
                start = tempStart;
                end = i;
            }

            if (sum < 0) {
                sum = 0;
                tempStart = i + 1;
            }
        }
        vector<int> result;
        if (start != -1 && end != -1) {
            for (int i = 0; i <= end; ++i) {
                result.push_back(nums[i]);
            }
        }
        return result;
    }
};
