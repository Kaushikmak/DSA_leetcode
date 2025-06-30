#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubseq(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        if (nums[0] > target) {
            return 0;
        }
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);

        }
    }
};
