#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int> &nums, int key, int k) {
        const unsigned int n = nums.size();
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == key) {
                for (int j = 0; j < n; ++j) {
                    if (abs(i-j)<=k) {
                        result.push_back(j);
                    }
                }
            }
        }
        sort(result.begin(),result.end());
        result.erase(unique(result.begin(),result.end()),result.end());
        return result;
    }
};
