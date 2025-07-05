#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

class Solution {
public:
    int findLucky(vector<int> &arr) {
        vector<int> freqArray(501, 0);
        const unsigned int n = arr.size();
        for (int item: arr) {
            freqArray[item]++
        }
        int result = -1;
        for (int i = 500; i >= 1; i--) {
            if (i == freqArray[i]) {
                result = i;
                break;
            }
        }
        return result;
    }
};
