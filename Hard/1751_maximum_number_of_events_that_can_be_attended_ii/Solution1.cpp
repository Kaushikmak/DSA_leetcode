#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int> > &events, int k) {
        // events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
        // O/P = 7
        sort(events.begin(),events.end());
        const unsigned int n = events.size();
        return solve(0,k,n,events);
    }

private:
    int solve(int index, int k, int vectorSize, vector<vector<int> > &nums) {
        // if index does out of bound, or we can't attend any events i.e. k=0
        if (index >= vectorSize || k == 0) {
            return 0;
        }
        // start and end day of current and value
        int start = nums[index][0];
        int end = nums[index][1];
        int value = nums[index][2];
        // to skip
        int skip = solve(index + 1, k, vectorSize, nums);
        // take
        int j = index + 1;
        // first search for desired event
        for (; j < vectorSize; j++) {
            // if jth events starting day > end day
            if (nums[j][0] > end) {
                break;
            }
        }
        int take = value + solve(j, k - 1, vectorSize, nums);

        return max(take, skip);
    }
};
