# Group Anagram

---

### Approach 1

+ TLE 125/126

we know how to find if two strings are anagram of not in 
`TC: O(n)` and `SC: O(1)`

Idea is to iterate over loop and check is two strings are anagram or not, then add 
them in vector, 

But we may use some letters more than one time, so we need to keep track of letters
that we have used i.e. we need a visited array to keep track of them

- write function for
`bool isAnagram(string str1, string str2)`
- loop over all elements and insert `i`<sup>th</sup> element to temp vector 
and mark is as visited then in second loop starting from `j=i+1` check is `isAngram`
and is not visited, then insert it into temp vector and mark it as visited
- outside of second loop insert temp vector in result vector
- Time complexity: O(n^2 * k)
- - n: number of strings
- - k: maximum length of string
- Space complexity: O(n)

### Approach 2

we can use hashMap and sorting

- if we sort every string in our array and use hashMap
- is we sort every string, then we can find every anagram, and use hashMap to store
`hashMap[sortedString].push_back(unsortedString)`
- hence we got hashMap which contains the strings as vector
- and then finally push that vector into result
- Time complexity: O(m*nlog(n))
- - m: total number os strings
- - n: length of longest string
- Space complexity: O(m*n)

### Approach 3

since all string contains lower case english characters? can we use it

https://www.youtube.com/watch?v=--k5-3EOObs

`["eat","tea","tan","ate","nat","bat"]`

- we have `eat` take a vector so size 26, and do `e:1 , a:1 , t:1` &rarr; aet
- now `tea` &rarr; `t:1 , e:1 , a:1` &rarr; aet
- if we have `map<string,vector<string>>` `aet : {eat,tea}` and so on
- similarly other, we have built a map with required vectors
- and finally we join all vectors to get desired result
- Time complexity: O(n*k)
- Space complexity: O(m)