# 2 Sum

---

* we may not use the same element twice which result in constraint `i != j`

### Approach 1

we can use nested loop, and check if sum meets the required target

- loop over `nums` and check `nums[i] + nums[j] == target`
- if true then push_back indices `i` and `j` in vector and return
- else return empty vector
- Time complexity: O( n^2 )
- Space complexity: O(1) 

### Approach 2

sort the array and use two pointers technique

- sort the array
- **But we need to keep in mind by sorting, it changes the original indices order**
- we need something to store original value and their index vector of pairs `vector<pair<int,int>> myPair`
- use two pointers low and high
- if `myPair[low].first + myPair[high].first == target` return `myPair[low].second + myPair[high].second`  
- if `myPair[low] + myPair[high] > target` then `high--`
- if `myPair[low] + myPair[high] < target` then `low++`
- Time Complexity: `O(n log n)`

| Step               | Time Complexity | Space Complexity |
|--------------------|-----------------|------------------|
| Build vector pair  | `O(n)`          | `O(n)`           |
| Sorting            | `O(n log n)`    | `O(n)`           |
| Two-pointer search | `O(n)`          | `O(1)`           |
- Overall Space Complexity: `O(n)`

### Approach 3

`num[i] + num[j] == target`

`difference = target - nums[i]`

if we store value and indices in hash map, and then find if `difference` exists in map or not

- store value and their index in Hash Map
- in loop, we find if difference exists in Hash map or not
- but suppose if number target is `4` and `2` exists in our nums array
then our difference is also `2` so if we check that `2` exists in map it returns `true`
but this is **edge case** we do not want our numbers to repeat.
- we check that `myHashMap[difference] != current_index`
- Time complexity: O(n)
- Space complexity: O(n)

### Approach 4

In above approach what if we do all in one loop
optimizing it to O(2n) &rarr; O(n)

check if `difference` exists in map if not we insert `nums[i]`

- check in map is difference exists
- if true, then return `{map[difference],current_index}`
- if not insert `{nums[i],i}`