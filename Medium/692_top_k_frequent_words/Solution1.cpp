#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // pair of words and their respective frequencies
    typedef pair<string, int> P;
    // custom comparator
    // according to question first priority is frequency
    // and if frequencies are same then,
    struct lambda {
        bool operator()(P &a, P &b) {
            if (a.second == b.second) {
                return a.first < b.first; // min heap: keep larger word
            }
            return a.second > b.second; // min heap: keep smaller frequency
        }
    };

    vector<string> topKFrequent(vector<string> &words, int k) {
        // hash map to store frequencies
        unordered_map<string, int> myMap;
        for (const string &word: words) {
            myMap[word]++;
        }
        // min heap
        priority_queue<P, vector<P>, lambda> minHeap;
        for (auto &it: myMap) {
            string word = it.first;
            int freq = it.second;
            minHeap.push({word, freq});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        int i = k - 1;
        vector<string> result(k);
        while (!minHeap.empty()) {
            result[i] = minHeap.top().first;
            minHeap.pop();
            i--;
        }
        return result;
    }
};
