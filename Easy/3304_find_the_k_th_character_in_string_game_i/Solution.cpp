#include <string>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";

        while (s.length() < k) {
            string temp = s;
            for (const char c : temp) {
                s += nextChar(c);
            }
        }

        return s[k - 1];
    }
private:
    char nextChar(const char c) {
        if (c == 'z') return 'a';
        return c + 1;
    }
};