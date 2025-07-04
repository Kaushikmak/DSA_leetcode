#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        const unsigned int n = s.size();
        const unsigned int m = t.size();
        if (m != n) {
            return false;
        }
        unordered_map<char,int> sMap;
        unordered_map<char,int> tMap;
        for (char items: s) {
            sMap[items]++;
        }
        for (char items: t) {
            tMap[items]++;
        }
        return sMap == tMap;
    }
};
