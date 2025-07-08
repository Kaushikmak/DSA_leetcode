# Maximum Events that can be attended II

---

### Approach 1

* interval &rarr; sort by starting day

- sort the array by starting day
- **END DAY IS INCLUSIVE**
- if `i`<sup>th</sup> event's start day is equal to `i-1`<sup>th</sup> day's start day
then we have to skip that

i.e. `[[1,2,4],[3,4,3],[2,3,1]]`

then we sort given array &rarr; `[[1,2,4],[2,3,1],[3,4,3]]`

suppose we attended `event 0`, that ends on event `day 2` so naturally we can't 
attend `event 1` cuz  it starts on `day 2`

Similarly, if we attend `event 1` then we can't attend `event 2` by same logic

Although we should attend `event 0` and `event 2` to get maximum value

- this is `take/skip` problem, i.e. we take `event 0` and we take next value whose
`start_day > event 0's start_day` else skip 
- we can use linear search to find next desired event
- in the end we take `max(take,skip)`
- Time complexity: O( n * 2^k )
- - O(n) &rarr; for linear search
- - O(2^k) &rarr; for recursion
- Space complexity: O(n) 
- - recursion call stack

### Approach 2

Memoization of above recursion

### Approach 3

Instead of linear search use binary search