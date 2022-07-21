# Write your MySQL query statement below

SELECT Users.user_id as buyer_id, Users.join_date, IFNULL(COUNT(buyer_id),0) as orders_in_2019 
FROM Users
LEFT JOIN Orders ON Orders.buyer_id = Users.user_id AND YEAR(Orders.order_date) = 2019
GROUP BY Users.user_id