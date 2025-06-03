/*
Example 1:

Input: n = 5, limit = 2
Output: 3
Explanation: There are 3 ways to distribute 5 candies such that no child gets more than 2 candies: (1, 2, 2), (2, 1, 2) and (2, 2, 1).
Example 2:

Input: n = 3, limit = 3
Output: 10
Explanation: There are 10 ways to distribute 3 candies such that no child gets more than 3 candies: (0, 0, 3), (0, 1, 2), (0, 2, 1), (0, 3, 0), (1, 0, 2), (1, 1, 1), (1, 2, 0), (2, 0, 1), (2, 1, 0) and (3, 0, 0).
 */


#include <algorithm>
// star and pipe example
/*
    suppose we have 5 stars and need to distribute over 3 kids
    x1 + x2 + x3 = 5, xi >= 0
    * * | * * | *
    pipe separates them
    pipes = kids -1
    stars = 5
    total things we have 5 + kids - 1, and we need to arrange pipes
    n+r-1 C r-1 -> we are choosing positions of pipes
    we can also do
    n+r-1 C n -> we are choosing positions of star

    hence to distribute 5 stars among 3 kids are 5+3-1 C 3-1 or 5+3-1 C 5
 */
// https://www.youtube.com/watch?v=eL_3cDp0zjE
/*
 * child 1 min = n - 2*limit assigned limit candies to both child 2 & 3
 * child 2 max = min( n , limit )
 * now child 2 and 3 have say N = n-i
 *
 */

using namespace std;

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        const long long child1min = max(0LL, n - 2LL * limit);
        const long long child1max = min(n, limit);
        long long ways = 0;
        for (int i = child1min; i <= child1max; ++i) {
            int N = n - i;
            const long long child2min = max(0, N - limit);
            const long long child2max = min(N, limit);
            ways += child2max - child2min + 1;
        }
        return ways;
    }
};
