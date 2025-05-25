#include <vector>

using namespace std;

/*
    Start at the top-right element:

        If the element is greater than target, move left.

        If the element is less than target, move down.

        If equal, return true.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        const int rows = static_cast<int>(matrix.size());
        const int cols = static_cast<int>(matrix[0].size());
        int row = 0;
        int col = cols - 1;
        while (row < rows && col >= 0) {
            const int current = matrix[row][col];
            if (current==target) {
                return true;
            }
            if (target>current) {
                ++row;
            }else {
                --col;
            }
        }
        return false;
    }
};
