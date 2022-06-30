insted of swaping value we are swaping the whole node, first we reach the end then start swaping.
eg.       4
/   \
2      7
/       /   \
1       6     9
first 1 will swap with NULL      2
\
1
then 9 swap with 6           7
/     \
9         6
then 2 and 7 swap               4
/   \
7     2
/   \      \
9      6      1                final ans;