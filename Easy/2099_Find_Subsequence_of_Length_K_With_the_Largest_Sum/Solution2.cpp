#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int> &nums, int k) {
        vector<pair<int, int> > numWithIndex;
        for (int i = 0; i < nums.size(); i++) {
            numWithIndex.push_back({nums[i], i});
        }

        // Sort by value descending
        sort(numWithIndex.rbegin(), numWithIndex.rend());

        // Pick top k elements
        vector<pair<int, int> > topK(numWithIndex.begin(), numWithIndex.begin() + k);

        // Sort top k by original index to preserve order
        sort(topK.begin(), topK.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

        // Build result
        vector<int> result;
        for (auto &p: topK) {
            result.push_back(p.first);
        }

        return result;
    }
};
