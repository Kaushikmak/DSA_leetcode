# Maximum Number of Events to Attend

---

### Approach 1

* Interval &rarr; sorting related

`[[3,7],[5,8],[1,2]]` 

based on the starting day sort the array, WHY? because we have to attend events 
inorder if we attend event of `day 3` we can't go back to attend `day 1` event

`[[1,2],[3,7],[5,8]]`

- attend event on day 1
- can't attend any event on day 2
- now attend day 3 event
- can't attend any event on day 4
- attend day 5 event

e.g. sorted array `[[1,1],[1,4],[2,2],[3,4],[4,4]]`

- day1: `[1,1]` & `[1,4]`
we have option to attend either of event so we compulsorily need to attend the shortest event
- **if any day we have option to select event, select event that ends earlier**
- day2: `[2,2]` & `[1,4]` we choose `[2,2]`
- day3: `[3,4]` & `[1,4]` here both ends on same day suppose we choose `[1,4]`
- day4: `[3,4]` & `[4,4]` here also both events ends on same day we choose `[3,4]`
- now `current_day > last_event` so we break, skip the event whose end day is < current day
- Till now, we have attended total of 4 events
- starting `current_day` smallest starting day in array if sorted then `arr[0][0]`
- `[[5,8],[15,20]]` here we can start from `5` and jump  then we can jump to `15` 
so we can save some computation. **skip events whose end_day < current_day**
- Time complexity: O( nlog(n) )
- - push, pop takes O( nlog(n) ) where n is number f elements in heap
- Space complexity: O(n)