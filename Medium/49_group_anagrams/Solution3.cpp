#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string> > res;
        // loop over all strings
        for (const string &s: strs) {
            // we need to create vector to keep track
            vector<int> tempFreq(26,0);
            // count char freq. in string
            for (const char c: s) {
                tempFreq[c-'a']++;
            }
            string key;
            for (int i=0;i<26;i++) {
                if (tempFreq[i]!=0) {
                    key += static_cast<char>('a' + i);
                    key += to_string(tempFreq[i]);
                }
            }
            res[key].push_back(s);
        }
        // result
        vector<vector<string>> result;
        for (const auto& [first,second]: res) {
            result.push_back(second);
        }
        return result;

    }
};
