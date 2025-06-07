#include <queue>
#include <string>

using namespace std;

// https://www.youtube.com/watch?v=-0xkQYTP1I0


class Solution {
public:
    typedef pair<char, int> p;

    struct comp {
        bool operator()(const p &p1, const p &p2) const {
            if (p1.first == p2.first) {
                return p1.second < p2.second;
            }
            return p1.first > p2.first;
        }
    };

    string clearStars(string s) {
        priority_queue<p, vector<p>, comp> q;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '*') {
                q.push({s[i], i});
            } else {
                if (!q.empty()) {
                    int index = q.top().second;
                    q.pop();
                    s[index] = '*';
                }
            }
        }

        string retval = "";
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '*') {
                retval.push_back(s[i]);
            }
        }
        return retval;
    }
};
