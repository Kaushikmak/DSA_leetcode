#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        const int rows = matrix.size();
        for (int i = 0; i < rows; ++i) {
            if (binarySearch(matrix[i], target) != -1) {
                return true;
            }
        }
        return false;

    }

private:
    static int binarySearch(const vector<int> &nums, const int target) {
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;
        while (left <= right) {
            const int mid = left + ((right - left) >> 1);
            if (nums[mid] == target) {
                return target;
            }
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};
