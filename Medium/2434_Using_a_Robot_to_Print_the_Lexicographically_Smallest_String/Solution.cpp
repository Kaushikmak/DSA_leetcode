#include <string>
#include <vector>
#include <queue>

using namespace std;

// https://www.youtube.com/watch?v=NUMNPFel73Q


class Solution {
public:
    string robotWithString(string s) {
        vector<char> minCharVector = minCharToRight(s);
        string t = "";     // stack (as string)
        string paper = ""; // final result

        for (int i = 0; i < s.size(); ++i) {
            t.push_back(s[i]); // push current char to stack

            // while top of t is <= min char to the right, pop from t to paper
            while (!t.empty() && t.back() <= minCharVector[i]) {
                paper.push_back(t.back());
                t.pop_back();
            }
        }

        // any remaining characters in t can be appended to paper
        while (!t.empty()) {
            paper.push_back(t.back());
            t.pop_back();
        }

        return paper;
    }

private:
    vector<char> minCharToRight(string s) {
        const int stringSize = s.size();
        vector<char> result(stringSize);
        char currentMin = 'z';
        for (int i = stringSize - 1; i >= 0; --i) {
            result[i] = min(currentMin, s[i]);
            currentMin = result[i];
        }
        return result;
    }
};

