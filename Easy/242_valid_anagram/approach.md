# Valid Anagram

---

* An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, using all the original letters exactly once.

### Approach 1

we know strings contains only lowercase english letters.
So we can sort them and then compare each element 
Also edge case is that if both strings are of different size then it must not be anagram

- check is both strings are of same size
- sort both strings
- compare them in single loop
- Time complexity: O( nlog(n) + mlog(m) )
- Space complexity: O(1)

### Approach 2

