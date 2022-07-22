# Write your MySQL query statement below
SELECT u.name, SUM(t.amount) as balance
FROM Users u
JOIN Transactions t USING(account)
GROUP BY t.account
HAVING balance > 10000;