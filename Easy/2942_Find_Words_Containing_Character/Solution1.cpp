#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        auto lambda = [&x](char ch) {
            if (ch==x) return true;
        };
        vector<int> result;
        for (int i=0;i<words.size();i++) {
            if (any_of(words[i].begin(),words[i].end(),lambda)==true) {
                result.push_back(i);
            }
        }
        return result;
    }
};