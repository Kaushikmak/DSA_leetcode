#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// total possibilities  = product of freq. of each char
class Solution {
public:
    const long long MODULO = 10e9 + 7;

    int possibleStringCount(string word, int k) {
        unordered_map<char, int> uniqueChars;
        // map to store unique chars and their occurrence in word
        for (char items: word) {
            uniqueChars[items]++;
        }
        // total possible words
        long long totalPossibleWords = 1;
        int numberOfWords = 0;
        vector<int> freqArray;
        for (const auto &[fst, snd]: uniqueChars) {
            totalPossibleWords *= snd;
            numberOfWords++;
            freqArray.push_back(snd);
        }
        if (numberOfWords >= k) {
            return static_cast<int>(totalPossibleWords % MODULO);
        } else {
            // count < k i.e. we are finding word possibilities
            // which are invalid
            int invalidCount = solve()
        }
    }

private:
    int solve(int i, int count, vector<int> freq, int k) {
        if (i >= freq.size()) {
            if (count<k) {
                // got an invalid string/word
                return 1;
            }
            return 0;
        }
        int result = 0;
        for (int take = 1; take <= freq[i]; ++take) {
            // current + already taken < k
            // for word to be invalid
            if (take + count < k) {
                result += solve(i + 1, count + take, freq, k);
            } else {
                break;
            }
        }
        return result;
    }
};
