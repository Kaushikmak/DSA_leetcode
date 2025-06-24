#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int> &nums, int key, int k) {
        const unsigned int n = nums.size();
        vector<int> result;
        vector<int> keyIndex;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == key) {
                keyIndex.push_back(i);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int indexes: keyIndex) {
                if (abs(i - indexes) <= k) {
                    result.push_back(i);
                    break;
                }
            }
        }
        return result;
    }
};
