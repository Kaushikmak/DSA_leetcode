#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> frequencies(26, 0);
        const int n = word.length();
        for (char &ch: word) {
            frequencies[ch - 'a']++;
        }
        int result = n;
        for (int i = 0; i < 26; i++) {
            int del = 0;
            for (int j = 0; j < 26; j++) {
                if (i == j) continue;
                if (frequencies[j] < frequencies[i]) {
                    del += frequencies[j];
                } else if (abs(frequencies[j] - frequencies[i]) > k) {
                    del += abs(frequencies[j] - frequencies[i] - k);
                }
            }
            result = min(result,del);

        }
        return result;
    }
};
