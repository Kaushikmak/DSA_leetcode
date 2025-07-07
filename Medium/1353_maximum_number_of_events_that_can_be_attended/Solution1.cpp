#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int> > &events) {
        const unsigned int n = events.size();
        // sort by start date
        sort(begin(events), end(events));
        // current day
        int day = events[0][0];
        // variable to iterate over event
        int i = 0;
        // count result
        int count = 0;
        // initialize priority queue
        priority_queue<int, vector<int>, greater<> > pq;
        // check if priority queue is empty or not
        // and if index is out of bound
        while (!pq.empty() || i < n) {
            // if priority queue is empty , we skip those days in example of `[[5,8],[15,20]]`
            if (pq.empty()) {
                day = events[i][0];
            }
            // if starting day == current day
            while (i < n && events[i][0] == day) {
                // insert end day
                pq.push(events[i][1]);
                i++;
            }
            // check if priority queue is empty
            if (!pq.empty()) {
                // attended 1 event
                pq.pop();
                count++;
            }
            // day will increase
            day++;
            // skip those events whose endDay < day
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }
        }
        return count;
    }
};
