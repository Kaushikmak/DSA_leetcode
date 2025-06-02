#include <vector>

using namespace std;

/*
Example 1:
Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

Example 2:
Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.
 */
// approach first from left to right and then from right to left
// check if rating is greater than previous then increase
class Solution {
public:
    int candy(vector<int> &ratings) {
        const int ratingSize = static_cast<int>(ratings.size());
        vector<int> candies(ratingSize, 1);
        for (int i = 1; i < ratingSize; ++i) {
            if (ratings[i - 1] < ratings[i]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        for (int i = ratingSize - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }
        return sum(candies);
    }

private:
    int sum(const vector<int> &nums) {
        const int numsSize = nums.size();
        int sum = 0;
        for (int i = 0; i < numsSize; ++i) {
            sum += nums[i];
        }

        return sum;
    }
};
