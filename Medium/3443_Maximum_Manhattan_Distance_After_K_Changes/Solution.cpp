#include <string>

using namespace std;

// https://www.youtube.com/watch?v=LjgDv-WeXfM
// jitna distance chale utna hi manhatten distnace hoa chaiye
// wasted steps me k modifications karo
// wasted steps = total distance - manhatten distance

class Solution {
public:
    int maxDistance(string s, int k) {
        int maxDistance =  0;
        int east = 0;
        int west = 0;
        int north = 0;
        int south = 0;
        const int n = s.length();
        for (int i=0;i<n;++i) {
             if (s[i]=='E') east++;
             else if (s[i]=='W') west++;
             else if (s[i]=='N') north++;
             else south++;
            int currentDistance = abs(east-west) + abs(north-south);
            int steps = i+1;
            int wasted = steps - currentDistance;
            int extra = 0;
            // best case wasted == 0
            if (wasted!=0) {
                extra = min(2*k,wasted);
            }
            int finalCurrentMaximumDistance = currentDistance + extra;
            maxDistance = max(maxDistance,finalCurrentMaximumDistance);

        }
        return maxDistance;

    }
};