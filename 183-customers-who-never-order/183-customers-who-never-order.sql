# Write your MySQL query statement below

SELECT name AS 'Customers'
FROM customers
WHERE Customers.id NOT IN
(
    SELECT customerID FROM Orders
);