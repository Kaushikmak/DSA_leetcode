#include <vector>
#include <string>

using namespace std;
// TLE
class Solution {
public:
    char kthCharacter(long long k, vector<int> &operations) {
        string initialWord = "a";
        const unsigned int n = operations.size();
        for (int i = 0; i < n; ++i) {
            const string tempWord = initialWord;
            if (operations[i] == 0) {
                initialWord += tempWord;
            } else {
                const unsigned int count = initialWord.size();
                while (initialWord.length() < 2*count) {
                    string temp = initialWord;
                    for (const char c: temp) {
                        initialWord += nextChar(c);
                    }
                }
            }
        }
        return initialWord[k - 1];
    }

private:
    char nextChar(char alphabet) {
        return (alphabet == 'z' ) ? 'a' : static_cast<char>(alphabet+1);
    }
};
