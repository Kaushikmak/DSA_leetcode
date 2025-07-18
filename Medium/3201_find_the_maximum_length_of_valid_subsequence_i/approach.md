# Max. length of valid subsequence

---

### Approach 1

```c++
(sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2

even + even = even
odd + odd = even
even + odd = odd
```

+ if first sum is even then both have to be even or odd, and since one num
is also present in other sum them it should have same parity 
+ **conclusion** either nums should contain all even or all odd
+ if suppose sum is odd, and by same property in second sum parity should be
different, i.e. nums should have all elements which have alternating parity

- find total even
- total odd
- total alternating 
- return max of them
- Time complexity: O(n)
- Space complexity: O(1)

### Approach 2

Dp &rarr; subsequence related problems can be solved using dp

Like very popular qns of Longest common subsequence where certain property follows
`nums[i] > nums[j]`, so it's similar qns but there property is `%2`

- like take and skip problem we have 2 pointers `previous` and `currentindex`
- we can have `%2 == 0` and `%2 == 1` so we do take/skip for both modulo 2
- But this solution will give `TLE` we have to use memoization
- Since `2 <= nums.length <= 2 * 10^5` using memoization also gives `MLE`
- Time complexity: (2^n)
- Space complexity: O(n)
- - due to recursion call stack