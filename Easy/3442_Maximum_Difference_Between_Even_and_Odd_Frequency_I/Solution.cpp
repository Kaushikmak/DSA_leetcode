#include <string>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxDifference(const string &s, int k_unused = 0) {
        vector<int> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        int maxOdd = 0;
        int minEven = INT_MAX;

        for (int i = 0; i < 26; ++i) {
            if (freq[i] == 0) continue;

            if (freq[i] % 2 == 0) {
                minEven = min(minEven, freq[i]);
            } else {
                maxOdd = max(maxOdd, freq[i]);
            }
        }

        if (minEven == INT_MAX) return -1;

        return maxOdd - minEven;
    }
};
