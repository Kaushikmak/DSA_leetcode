#include <vector>

using namespace std;
// works for contiguous sub-sequence
class Solution {
public:
    vector<int> maxSubsequence(vector<int> &nums, int k) {
        const int n = nums.size();
        int currentSum = 0;
        int maxSum = 0;
        int startIndex = 0;
        vector<int> result;
        for (int i = 0; i < k; i++) {
            currentSum += nums[i];
        }
        maxSum = currentSum;
        for (int i = k; i < n; i++) {
            currentSum += nums[i] - nums[i - k];
            if (currentSum > maxSum) {
                maxSum = currentSum;
                startIndex = i - k + 1;
            }
        }
        for (int i = startIndex; i < startIndex + k; i++) {
            result.push_back(nums[i]);
        }
        return result;
    }
};
