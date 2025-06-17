#include <vector>

using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int minElement = nums[0]; //nums[i]
        int maxDifference = -1;
        for (int j=1;j<n;++j) {
            if (nums[j]>minElement) {
                maxDifference = max(maxDifference,nums[j]-minElement);
            }else {
                minElement = nums[j];
            }
        }
        return maxDifference;
    }
};