#include <vector>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int> &nums) {
        int maxSubLength = 0;
        maxSubLength = max(maxSubLength, dp(nums, 0, -1, 0));
        maxSubLength = max(maxSubLength, dp(nums, 0, -1, 1));

        return maxSubLength;
    }

private:
    int dp(vector<int> &array, int currenIndex, int previousIndex, int modulo) {
        // base case
        if (currenIndex >= array.size()) {
            return 0;
        }
        int take = 0;
        int skip = 0;
        // take
        if (previousIndex == -1 || ((array[previousIndex] + array[currenIndex]) % 2 == modulo)) {
            take = 1 + dp(array, currenIndex + 1, currenIndex, modulo);
        }
        // skip
        skip = dp(array, currenIndex + 1, previousIndex, modulo);
        return max(take, skip);
    }
};
