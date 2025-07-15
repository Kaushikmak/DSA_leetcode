# top K frequent words

---

### Approach 1

* [How to write custom comparator](https://www.youtube.com/watch?v=D4LTcz6OhmY)

- store frequencies in hash map
- put them in min heap, but use custom comparator to maintain
lexicographical order
- remove elements from min heap as size grows beyond k
- then store in result vector
- Time complexity: O( nlog(k) )
- Space complexity: O( k )