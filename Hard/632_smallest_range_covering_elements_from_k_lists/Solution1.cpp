#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        int minEle = -1;
        int maxEle = INT_MIN;

        priority_queue<int, vector<int>, greater<>> minHeap;
        for (auto &it: nums) {
            minHeap.push(it[0]);

            minEle = minHeap.top();
            maxEle = max(maxEle,it[0]);
        }
        int start = minEle;
        int end = maxEle;

        while (!minHeap.empty()) {


        }




    }
};