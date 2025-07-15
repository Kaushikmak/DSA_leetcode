#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string word) {
        if(word.length()<3) return false;
        bool vowel = false;
        bool consonent = false;
        auto checkVowel = [](char ch){
            return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
        };
        for(const char &ch: word){
            if(!isalnum(ch)) return false;

            if(isdigit(ch)) continue;

            if(checkVowel(tolower(ch))) vowel=true;
            else consonent=true;

        }
        return vowel && consonent;
    }
};