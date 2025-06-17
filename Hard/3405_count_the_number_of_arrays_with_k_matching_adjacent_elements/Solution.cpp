#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

class Solution {
public:
    // Binary exponentiation: O(log b)
    long long power(long long a, long long b) {
        long long res = 1;
        a %= MOD;

        while (b > 0) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }

        return res;
    }

    // Compute nCr % MOD using precomputed factorial and inverse factorial
    long long nCr(int n, int r, const vector<long long>& fact, const vector<long long>& invFact) {
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }

    int countGoodArrays(int n, int m, int k) {
        // Precompute factorials and inverse factorials
        vector<long long> fact(n + 1);
        vector<long long> invFact(n + 1);
        fact[0] = 1;

        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }

        invFact[n] = power(fact[n], MOD - 2); // inverse of n! using Fermat
        for (int i = n - 1; i >= 0; i--) {
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;
        }

        long long res = nCr(n - 1, k, fact, invFact); // (n-1 choose k)
        res = res * m % MOD;
        res = res * power(m - 1, n - 1 - k) % MOD;

        return res;
    }
};
