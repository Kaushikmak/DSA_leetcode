#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        const unsigned int n = nums.size();
        for(const int a: nums){
            pq.push(a);
        }
        int flag = k-1;
        while(flag>0){
            pq.pop();
            flag--;
        }
        return pq.top();
    }
};