# concatenation of array

---

### Approach 1

we need to add elements in same order

- simply push back `num[i]` to array
- Time complexity: O(n)
- Space complexity: O(2n) -> O(n) extra space

### Approach 2

we know `result[i] = result[i + n] = nums[i]`

- create another vector `vector<int> result(2 * n)` of size twice as of nums
- loop over n times and `result[i] = result[i + n] = nums[i]`

