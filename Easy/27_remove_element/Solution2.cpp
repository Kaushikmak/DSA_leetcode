#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        // we are using 2 pointers here
        int low = 0;
        int high = nums.size();
        while (low < high) {
            // if nums[i] == val then send it to last of vector
            // NOTE: in case like [1 2 2 2 2 2] my low remains at 1th index
            // while my high goes left
            if (nums[low] == val) {
                nums[low] = nums[--high];
            } else {
                low++;
            }
        }
        return high;
    }
};
