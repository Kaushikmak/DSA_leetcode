#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        const int rows = matrix.size();
        const int cols = matrix[0].size();
        return binarySearch(matrix, target, rows, cols) != -1;
    }

private:
    static int binarySearch(const vector<vector<int>> &matrix, const int target, const int rows, const int cols) {
        int left = 0;
        int right = rows * cols - 1;
        while (left <= right) {
            const int mid = left + ((right - left) >> 1);
            const int midValue = matrix[mid / cols][mid % cols];
            if (midValue == target) {
                return mid;
            }
            if (midValue < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};
