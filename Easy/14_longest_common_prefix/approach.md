# Longest Common Prefix

---

### Approach 1

Take first character of first string in vector, and compare it with first char of 
every other string

- take first char of first string in array
- compare it with first char of every other string in array
- repeat for second, third ... characters
- for i<sup>th</sup> char make sure it does not exceed length of other string
- try to think of negation case to return
- Time complexity: O( n * m ) number of strings * length of shortest string
- Space complexity: O( m ) length of shortest string

