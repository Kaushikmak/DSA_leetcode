

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        double answer = 1.0;

        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        while (N > 0) {
            if (N % 2 == 1) {
                answer *= x;
            }
            x *= x;
            N /= 2;
        }

        return answer;
    }
};