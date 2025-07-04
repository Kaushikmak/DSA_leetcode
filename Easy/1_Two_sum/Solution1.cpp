#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        const unsigned int n = nums.size();
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                if (i != j && nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
};
