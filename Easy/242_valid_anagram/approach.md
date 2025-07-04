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

store key value pairs in Hash Map of both the strings
if both Hash Map are same then we got the result

- store key value pair in Hash Map of both strings
- compare both Hash Maps `sMap == tMap`
- Time complexity: O( n + m )
- Space complexity: O( n + m ) or we can say O(1) because worst case is O( 26 + 26 )

### Approach 3

we take a vector of size 26 and initialize it with 0, `count++` if char exists in `s` strings and `count--` if that char is present in `t` string.
And finally we check if all our vector elements are `0`.
Because according to definition of anagram characters can't repeat, if say `x` is present in s `2` times then it must present `2` times in t also.

- initialize vector `vector<int> result(26,0)`
- `++` if present in `s` and `--` if present in `t` or vice versa
- finally check if all elements in vector is `0`
- Time complexity: O( n ) if  m == n
- space complexity: O(1) 
