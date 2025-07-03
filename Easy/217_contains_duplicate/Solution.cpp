#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> set;
        for (int item: nums) {
            if (set.count(item)) {
                return true;
            }
            set.insert(item);
        }
        return false;
    }
};
