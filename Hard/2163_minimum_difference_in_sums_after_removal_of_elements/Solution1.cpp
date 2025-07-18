#include <vector>
#include <queue>
#include <climits>



using namespace std;
// Space: O(N)
class Solution {
public:
    long long minimumDifference(vector<int>& A) {
        priority_queue<int> L;
        priority_queue<int,vector<int>, greater<>> R;
        long N = A.size() / 3;
        long ans = LLONG_MAX;
        vector<long> right(A.size());
        for (long i = A.size() - 1, sum = 0; i >= N; --i) {
            R.push(A[i]);
            sum += A[i];
            if (R.size() > N) {
                sum -= R.top();
                R.pop();
            }
            if (R.size() == N) right[i] = sum;
        }
        for (long i = 0, left = 0; i < A.size() - N; ++i) {
            L.push(A[i]);
            left += A[i];
            if (L.size() > N) {
                left -= L.top();
                L.pop();
            }
            if (L.size() == N){
                ans = min(ans, left - right[i + 1]);
            }
        }
        return ans;
        // 3n! / n! * 2n!
    }
};