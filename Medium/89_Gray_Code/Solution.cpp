#include <bitset>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        int total = 1 << n;

        for (int i = 0; i < total; ++i) {
            bitset<16> bits(i);
            convert_binary_to_gray<16>(bits);
            result.push_back(convert_binary_to_int<16>(bits));
        }
        return result;
    }

private:
    template<int N>
    void convert_binary_to_gray(bitset<N> &nums) {
        for (int i = 0; i < N; ++i) {
            // core gray code logic
            nums[i] = nums[i] ^ nums[i + 1];
        }
    }

    template<int N>
    int convert_binary_to_int(bitset<N> &nums) {
        return nums.to_ulong();
    }
};
