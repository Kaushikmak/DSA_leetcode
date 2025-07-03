#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        const unsigned int n = s.size();
        const unsigned int m = t.size();
        if (m != n) {
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        for (int i = 0; i < n; ++i) {
            if (s[i] != t[i]) {
                return false;
            }
        }
        return true;
    }
};
