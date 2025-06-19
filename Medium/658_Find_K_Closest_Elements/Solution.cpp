#include <vector>

using namespace std;


class Solution {
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        int low = 0;
        int high = arr.size() - k;

        while (low < high) {
            int mid = low + ((high - low) >> 1);

            // Compare which end is farther from x
            if (x - arr[mid] > arr[mid + k] - x)
                low = mid + 1;
            else
                high = mid;
        }

        return vector<int>(arr.begin() + low, arr.begin() + low + k);
    }
};
