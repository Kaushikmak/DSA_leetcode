#include <vector>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even = 0;
        int odd = 0;
        int alternating = 1;
        for(const int &x: nums){
            if(x % 2 == 0){
                even++;
            }else{
                odd++;
            }
        }
        int n = nums.size();
        int parity = nums[0]%2;
        for(int i=0; i<n; i++){
            int currentParity = nums[i]%2;
            if(currentParity != parity){
                alternating++;
                parity = currentParity;
            }
        }

        return max(even, max(odd, alternating));

    }
};