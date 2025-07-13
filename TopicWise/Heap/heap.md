# HEAP

---

Heap is basically a complete binary tree

Heap can be implemented by simple array

We always insert node from left

CBT: every level is completely filled except last

for `i`<sup>th</sup> node

for `1` based indexing for `0` based add `+1` to each
- it's left child lies on `2*i`
- it's right child lies on `2*i + 1`

to find parent of `i`<sup>th</sup> we do `i/2`

[video to learn](https://www.youtube.com/watch?v=NKJnHewiGdc&list=PLWlla5Y-1FqyOqTat11CmcQp1nl079d0W&index=1&t=2131s)

### Insertion in Heap

- we first insert the element at last
- Then we verify if heap property holds
- if not we swap accordingly
- it takes O( log(n) )

### Deletion in Heap

deleting root node in heap
- swap last node with first node
- delete last node
- now make sure if newly inserted root is following heap property
- - propagate root node to it's correct position
- Time complexity: o( log(n) )

### Heapify

suppose given an array and we need to heapify it
- from index `n/2 + 1` to `n` all nodes are leaf 
- - we do not need to process them as they are already in their correct position
- if we call `heapify(index)` then it will re-locate the index's value
to it's correct position

### Heap sort

- Time complexity: O( n log(n) )

**Algorithm**
- STEP 1
- - we know in max heap our root is maximum,
so we swap(arr.begin(),arr.end());
- - `size--` then we need to worry about left out array only
- STEP 2
- - now again `Heapify` the array
- - again swap first and last nodes
- - `size--`