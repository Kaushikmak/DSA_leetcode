#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> myHashmap;
        for (int i = 0; i < nums.size(); ++i) {
            myHashmap.insert({nums[i], i});
        }
        for (int i = 0; i < nums.size(); ++i) {
            int difference = target - nums[i];
            if (myHashmap.count(difference) && myHashmap[difference] != i) {
                return {i,myHashmap[difference]};
            }
        }
        return {};
    }
};
