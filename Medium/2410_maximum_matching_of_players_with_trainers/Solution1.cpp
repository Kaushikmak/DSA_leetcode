#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int count = 0;
        int p1 = players.size()-1;
        int p2 = trainers.size()-1;
        while(p1>=0 && p2>=0){
            if(trainers[p2]>=players[p1]){
                count++;
                p1--;
                p2--;
            }else{
                p1--;
            }

        }
        return count;
    }
};
// 1,1,2
// 2
// 2



