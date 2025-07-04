#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        const unsigned int n = s.size();
        const unsigned int m = t.size();
        if (m != n) {
            return false;
        }
        vector<int> result(26, 0);
        for (int i = 0; i < n; ++i) {
            result[s[i] - 'a']++;
            result[t[i] - 'a']--;
        }
        for (const int item: result) {
            if (item != 0) {
                return false;
            }
        }
        return true;
    }
};
