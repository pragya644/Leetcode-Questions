Foyd cycle detection:
we know our value will range btw 1-n of size arrya n+1
means every number would be the index and 0 would not be here means we can never come back to the 0 index array
eg: 0  1  2  3  4  -index
1  3  4  2  2  -value
|
we can always start from 0 index element because we can never return to this positon
first move slow pointer by one and fast by two as soon as they collide take the slow pointer again at starting and now move slow and fast by one only and whenver they collide they that particular value going to be the ans