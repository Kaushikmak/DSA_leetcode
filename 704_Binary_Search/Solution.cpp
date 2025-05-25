#include <vector>

using namespace std;

class Solution {
public:
    int search(const vector<int> &nums, int target) {
        int left_pointer = 0;
        int right_pointer = nums.size() - 1;
        while (left_pointer <= right_pointer) {
            int mid_pointer = left_pointer + ((right_pointer - left_pointer) >> 1);
            if (nums[mid_pointer] == target) {
                return mid_pointer;
            }
            if (nums[mid_pointer] < target) {
                left_pointer = mid_pointer + 1;
            } else {
                right_pointer = mid_pointer - 1;
            }
        }
        return -1;
    }
};
