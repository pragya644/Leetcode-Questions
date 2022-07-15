# Write your MySQL query statement below

SELECT sell_date,
COUNT(DISTINCT product) AS 'num_sold',
GROUP_CONCAT(DISTINCT product ORDER BY product ASC SEPARATOR ',') AS 'products'
FROM Activities
GROUP BY sell_date;  
# group by is actually grouping the items with same sell date otherwise they all would be in singel row. 
#group_concat is merging all the distinct product together in same row but we are using group by so same date product will concate together by sorted in asc order.