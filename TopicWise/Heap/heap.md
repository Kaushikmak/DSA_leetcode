# HEAP

---

Heap is basically a complete binary tree

Heap can be implemented by simple array

We always insert node from left

for `i`<sup>th</sup> node
- it's left child lies on `2*i`
- it's right child lies on `2*i + 1`

to find parent of `i`<sup>th</sup> we do `i/2`

### Insertion in Heap

- we first insert the element at last
- Then we verify if heap property holds
- if not we swap accordingly
- it takes O( log(n) )