#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    typedef pair<int,int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mymap;
        for(const int &x: nums){
            mymap[x]++;
        }
        priority_queue<P,vector<P>,greater<P>> pq;
        for(auto &it: mymap){
            int value = it.first;
            int freq = it.second;
            pq.push({freq,value});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> result;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};