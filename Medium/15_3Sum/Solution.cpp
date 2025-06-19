#include <algorithm>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &nums) {
        set<vector<int> > result;
        const int numsSize = nums.size();
        for (int i = 0; i < numsSize; ++i) {
            for (int j = 0; j < numsSize; ++j) {
                for (int k = 0; k < numsSize; ++k) {
                    if (nums[i] + nums[j] + nums[k] == 0 && i!=j && j!=k && k!=i) {
                        vector<int> triplet = {nums[i],nums[j],nums[k]};
                        sort(triplet.begin(),triplet.end());
                        result.insert(triplet);

                    }
                }
            }
        }
        vector<vector<int>> returnArray(result.begin(),result.end());
        return returnArray;

    }
};
