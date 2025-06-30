#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findLHS(vector<int> &nums) {
        // const unsigned int n = nums.size();
        unordered_map<int, int> freq;
        int count = 0;
        for (int &items: nums) {
            freq[items]++;
        }

        // for (int &num: nums) {
        //     int minNumber = num;
        //     int maxNumber = num+1;
        //     if (freq.count(maxNumber)) {
        //         count = max(count,freq[minNumber] + freq[maxNumber]);
        //     }
        // }

        for (auto& [num, f] : freq) {
            if (freq.count(num + 1)) {
                count = max(count, f + freq[num + 1]);
            }
        }
        return count;
    }
};
