# String Game II

---

### Approach 1

Brute force and just generate string as specified.
* but it gives TLE error
- if `operations[i] == 0` append concatenate same string
- if `operations[i] == 1` append the next char string
- - run loop for 2 * original_length_of_string
- return `string[k-1]`
- Time Complexity: O(2^n)
- Space complexity: O(2^n)

### Approach 2

Since constraint of `k` is large so we need another approach.

**Observations**

- On every operation string size doubles
- if `k` is present in first half of string then we do not need
to generate other half of string

&rarr; if `operation == 0` then we can say that for string length of `l` and value `k`
 has same answer as that of `l/2` and value `k-l/2`

i.e. suppose we have `abcd` and we performe the operation then our string becomes `abcdabcd`
if we need 5<sup>th</sup> character i.e. `k=5` then we know that this 5<sup>th</sup> 
char is same as that of first char in original string that is string before operation

so can find it in original string by looking for `k-l/2` that is `5-8/2 = 1` or wrap 
around by `5%4` this is recursion only

&rarr; now consider `operation = 1`
consider we have `aaaa` and we perform the operation then we got`aaaa bbbb`
here also we do the same things but our required char will be `+1` od that

i.e. if we need 5<sup>th</sup> char in above string we find 1<sup>st</sup> char in 
original string and return 1<sup>st</sup> + 1 = b
this can also be achieved by recursion

- hence for any k we can find value in first half of string
- first we find length, index, operation using for loop
- then call recursion
- Time complexity: O( log(k) )
- Space complexity: O( log(k) )

### Approach 3

using bit manipulation
