# Write your MySQL query statement below

SELECT customer_id, COUNT(Visits.visit_id) as count_no_trans
FROM Visits
LEFT JOIN Transactions t ON Visits.visit_id = t.visit_id
WHERE t.visit_id is NULL
GROUP BY customer_id
ORDER BY count_no_trans;