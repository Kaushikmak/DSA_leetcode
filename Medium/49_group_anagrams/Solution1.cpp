#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string> &strs) {
        const unsigned int n = strs.size();
        vector<vector<string> > result;
        vector<bool> visited(n,false);
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                continue;
            }
            vector<string> temp;
            temp.push_back(strs[i]);
            visited[i] = true;
            for (int j = i+1; j < n; j++) {
                if (isAnagram(strs[i], strs[j]) && !visited[j]) {
                    temp.push_back(strs[j]);
                    visited[j] = true;
                }
            }
            result.push_back(temp);
        }
        return result;
    }

private:
    bool isAnagram(string str1, string str2) {
        if (str1.size() != str2.size()) {
            return false;
        }
        vector<int> isAnagram(26, 0);
        for (int i = 0; i < str1.size(); i++) {
            isAnagram[str1[i] - 'a']++;
            isAnagram[str2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (isAnagram[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
