# Remove Element

---

### Approach 1

* we need to modify nums such that starting `k` elements should be not `value`
* we don't care about other elements
* Also, we can return other numbers in any order

brute force approach
+ we make an array and insert all elements from `nums` except value
+ then we make first `k` elements of nums equal to that array's value
+ then return that array's size
+ Time complexity: O(n)
+ Space complexity: O(n)

### Approach 2

two pointer?

[0,1,2,2,3,0,4,2], val = 2 
i = 2 j = 6

[0,1,4,2,3,0,2,2], val = 2
i = 3 j = 5

[0,1,4,0,3,2,2,2], val = 2
i = 4 j = 5

