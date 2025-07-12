# Reschedule Meetings for Maximum Free Time I

---

### Approach 1

[Solution video](https://www.youtube.com/watch?v=JPWBTUyGCnM)

* there are n meetings
* i<sup>th</sup> meeting at `[StartTime[i] , EndTime[i]]`
* can reschedule atmost `k` meetings
* **maximize the longest continuous period of free time during the event**
* meetings can not be rescheduled to a time outside the event.
* have same relative order

eventTime = `5`, k = `1`, startTime = `[1,3]`, endTime = `[2,5]`

+ for k shift we get (k+1) free time

suppose free time is `{f1,f2,f3,f4,f5}`
+ for 1 shift we get `f1+f2`
+ for 2 shift we get `f1+f2+f3`
+ for k shift we get `f1+f2+f3+...+fk+1`

simply we need to find maximum sum of all free times depending on size

&rarr; this is sliding window technique only, we have `k+1` sized window and need to
find maximum sum that too continuous which our sliding window will take care itself

