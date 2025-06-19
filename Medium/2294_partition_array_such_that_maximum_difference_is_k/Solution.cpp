#include <vector>
#include <algorithm>

using namespace std;

/*
https://www.youtube.com/watch?v=4Tptf8TvYag

 */


class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        int count = 1; // first sub-seq
        int minValue = nums[0];
        for (int i = 0; i < n; ++i) {
            if (nums[i] - minValue > k) {
                count++;
                minValue = nums[i];
            }
        }
        return count;
    }
};
