In this we are making 0 idx value as root after that we are pushing into stack.
and start traversing array from 1 to n-1, if array value is less than s.top() than we can directly make it left but if it is greater we will take the maximum value from the stack which is smaller than array value.
​
current array value is 7
eg         1        7 is greater than 1 but we can not make 7 as right of 1 bcoz we are not sure
5        now we will see 5 is also smaller than 7 so may be 7 can right of 5
8        now 8 is greater than 7 means ,
7 will be the right node of 5