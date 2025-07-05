#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

class Solution {
public:
    int findLucky(vector<int> &arr) {
        unordered_map<int, int> hashMap;
        for (int items: arr) {
            hashMap[items]++;
        }
        int result = -1;
        for (const auto &pair: hashMap) {
            if (pair.second == pair.first) {
                result = max(result, pair.first);
            }
        }
        return result;
    }
};
