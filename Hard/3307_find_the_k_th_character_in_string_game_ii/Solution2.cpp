#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    char kthCharacter(long long k, vector<int> &operations) {
        if (k==1) {
            return 'a';
        }
        const unsigned int n = operations.size();
        long long length = 1; //initially length is 1 i.e. starting string is "a"
        long long index = -1, op = -1;
        for (int i = 0; i < n; ++i) {
            length *= 2; // every time length doubles
            if (length >= k) { // we need just the case where length exceeds k
                index = k - length / 2; // required index
                op = operations[i]; // required operation
                break;
            }
        }
        const char ch = kthCharacter(index,operations);
        if (op==0) {
            return ch;
        }
        return (ch=='z') ? 'a' : static_cast<char>(ch+1);
    }

};
