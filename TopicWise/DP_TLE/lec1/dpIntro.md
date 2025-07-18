suppose given an array, and we need to find sum of it, 
let's break it down into sub arrays and divided it 2 parts and continue doing 
it until only one element is there, 

So by dividing and concurring we can use all smallest subarray and add all those so get
solution of bigger problem.

- breaking a problem into smaller subproblems
- how to get answer of bigger problem from smaller subproblems
- what is the smallest subproblem for which solution is trivial (base case)
- what is the biggest subproblem that we want to solve

while dividing into subproblems there are some parts which repeat themselves, can
we use the repeating subproblems, so we do less calculation i.e. **memoization**

for memoization
- check if this subproblem has been calculated or not
- use some default value in array/map
- retrieve/update value

