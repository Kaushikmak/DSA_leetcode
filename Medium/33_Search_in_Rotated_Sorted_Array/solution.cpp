#include <vector>
using namespace std;

class Solution {
public:
    int search(const vector<int> &nums, int target) {
        return binarySearch(nums, target);
    }

private:
    int binarySearch(vector<int> &nums, int target) {
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] == target) {
                return mid;
            }
            // check if left half is sorted
            if (nums[mid] >= nums[left]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            // if right half is sorted
            } else {
                // is num is between mid and right
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    // if not then it is in left half
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
