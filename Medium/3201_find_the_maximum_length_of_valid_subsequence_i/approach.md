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