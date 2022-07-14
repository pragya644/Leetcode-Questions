# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below

DELETE p1
FROM Person p1, Person p2
WHERE p1.email = p2.email AND p1.id>p2.id;  

# we have selected 3  john@example.com and now we are deleting this
# it means where p1.email = p2.email and p1.id>p2.id , we have to delete that row