#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        // When you convert an unsigned integer to a signed integer,
        // and the unsigned value is too large to fit in the signed type,
        // or if the unsigned value represents a large positive number that would become
        // a negative number when interpreted as a signed type (due to two's complement representation),
        // the behavior is implementation-defined.
        const unsigned long long n = s.length();
        for (int i = 0; i < n; i += k) {
            string part = s.substr(i, k);
            if (part.length() < k) {
                part.append(k - part.length(), fill);
            }
            result.push_back(part);
        }
        return result;
    }
};
