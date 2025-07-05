# Find Lucky Integer

---

### Approach 1

**Mistakes**

- array is not sorted
- not always highest element with the highest freq. is our answer
- if no element is lucky then `-1`
- avoid sorting
- to keep track can use `max`

### Approach 1

- store freq. of values in Hash Map
- check is `key = value` in Hash Map
- if true then keep track of max value using `max`
- Time complexity: O(n)
- Space complexity: O(n)

### Approach 2

**Observe the constraints**: `1<=arr.size()<=500` `1<=arr[i]<=500`

- using constant space vector instead of map
which will effectively convert Space Complexity O(n) &rarr; O(1)
- we define vector for freq. of size 501 as 0 is not in array.
thus freq. array indices represent arr[i] and freq. is represented by freq[i]
- since we assigned freq. array's every value to be 0, and array is kinda sorted as
freq. indices are from 1 to 500, so last most element with non-zero value is our solution
- Time complexity: O(n)
- Space complexity: O(501) ~ O(1)

### Approach 3

can we do inplace? i.e. without extra space complexity

* maximum freq. in worst case is `n`
* that too when same element is present in whole array
* so freq. is bounded by 1 $\leq$ frequency $\leq$ n

This means if array is `{1,2,2,3,7}` thus `size  = 5`. Which means `7` has no chance 
of being lucky number

* largest possible lucky number is `500`
