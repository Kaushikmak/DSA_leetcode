#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    long long kMirror(int k, int n) {
        long long result = 0;
        int count = 0;
        int number = 1;

        while (count < n) {
            string base10Str = to_string(number);
            if (isReverseSame(base10Str) && isReverseSame(convertToBaseK(number, k))) {
                result += number;
                count++;
            }
            number++;
        }

        return result;
    }

private:
    string convertToBaseK(int baseTenNumber, int base) {
        string result;
        while (baseTenNumber > 0) {
            int remainder = baseTenNumber % base;
            result.push_back('0' + remainder);
            baseTenNumber /= base;
        }
        reverse(result.begin(), result.end());
        return result;
    }

    bool isReverseSame(const string& number) {
        string reversed = number;
        reverse(reversed.begin(), reversed.end());
        return reversed == number;
    }
};
