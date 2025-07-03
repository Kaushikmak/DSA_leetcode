# Contains Duplicate

---

### Approach 1

nested loop

- compare each element with every other element
- Time complexity: O(n^2)
- Space complexity: O(1)

### Approach 2

sort the array and compare if adjacent element is repeated

- sort the array
- check if `num[i] == nums[i-1]` the `true` else `false`
- Time complexity: O(nlog(n))
- Space complexity: O(1)

### Approach 3

using hash set 

- insert elements in hash set if there is duplicate then return true
- insert operation in hash set takes O(1) but we need to do it for every element in array
- Time Complexity: O(n)
- Space complexity: O(n)

to define hash set in cpp `unordered_set<int> myHashSet`