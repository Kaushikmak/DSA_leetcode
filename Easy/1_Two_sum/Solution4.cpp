#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> myMap;
        for (int i = 0; i < nums.size(); ++i) {
            int difference = target - nums[i];
            if (myMap.count(difference)) {
                return {myMap[difference], i};
            }
            myMap.insert({nums[i], i});
        }
        return {};
    }
};
