# kth largest element in array

---

### Approach 1

sort array
- Time complexity: o(nlog(n))
- Space complexity: O(1)

### Approach 2

- using heap, Idea is to use max heap and remove top k-1 
elements
- Time complexity: O(nlog(K) + (n-k))
- Space complexity: O(k)

### Approach 3

QuickSelect algorithm?