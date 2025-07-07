#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // ["flower","flow","flight"]
        const unsigned int n = strs.size();
        string resultantString;
        // first loop run until length of first string
        for (int i = 0; i < strs[0].size(); ++i) {
            // take ith character of first string
            const char comparatorString = strs[0][i];
            for (int j = 1; j < n; ++j) {
                // think of negation case
                // if index `i` goes above length of current string
                // char do not match
                // return immediately because prefix is continuous
                if (i >= strs[j].size() || strs[j][i] != comparatorString) {
                    return resultantString;
                }
            }
            resultantString += comparatorString;
        }
        return resultantString;
    }
};
