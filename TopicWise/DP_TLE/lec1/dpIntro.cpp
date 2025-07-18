// fibonaci number
// 1 1 2 3 5 8 13 21 ...
// f(n) = f(n-1) + f(n-2)
// suppose we want f(5) = f(4) + f(3)
// f(4) = f(3) + f(2)
// f(3) = f(2) + f(1)
// f(2) = 1
// f(1) = 1
// see here there are repeated calculations

#include <stdint.h>
#include <vector>

using namespace std;

// divide and concur
int fibdnc(int n) {
    if (n <= 0) return 0;
    if (n == 1 || n == 2) return 1;
    return fibdnc(n - 1) + fibdnc(n - 2);
}

// dp
vector<int> dp(100,-1);
int fibdp(int n) {
    if (n<=0) return 0;
    if (n==1 || n==2) return 1;
    if (dp[n]!=-1) return dp[n];
    dp[n] = fibdp(n-1) + fibdp(n-2);
    return dp[n];
}

int main() {
}
