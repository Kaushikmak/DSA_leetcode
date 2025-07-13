# Top k frequent elements

---

### Approach 1

- store frequencies in map
- store `pair(freq, value)` in min heap
- if heap grows beyond `k` then remove top element
- hence in the end we get top k largest, element by frequencies vise
- then pop back all elements in vector
- Time complexity: O( nlog(k) )
- Space complexity: O( k )