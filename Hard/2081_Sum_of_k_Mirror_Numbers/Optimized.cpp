#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

class Solution {
public:
    long long kMirror(int k, int n) {
        long long result = 0;
        int count = 0;
        int length = 1;

        while (count < n) {
            generatePalindromes(length, k, n, result, count);
            length++;
        }

        return result;
    }

private:
    void generatePalindromes(int length, int k, int n, long long& result, int& count) {
        int start = (length == 1) ? 1 : pow(10, (length - 1) / 2);
        int end = pow(10, (length + 1) / 2);

        for (int half = start; half < end && count < n; half++) {
            string halfStr = to_string(half);
            string revHalf = halfStr;
            reverse(revHalf.begin(), revHalf.end());

            string fullStr;
            if (length % 2 == 0) {
                fullStr = halfStr + revHalf;
            } else {
                fullStr = halfStr + revHalf.substr(1);
            }

            long long num = stoll(fullStr);

            if (isReverseSame(convertToBaseK(num, k))) {
                result += num;
                count++;
            }
        }
    }

    string convertToBaseK(long long num, int base) {
        string result;
        while (num > 0) {
            result.push_back('0' + num % base);
            num /= base;
        }
        reverse(result.begin(), result.end());
        return result;
    }

    bool isReverseSame(const string& s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        return s == rev;
    }
};
