# Write your MySQL query statement below

SELECT employee_id,
   CASE
   WHEN mod(employee_id,2)<>0 && SUBSTRING(name,1,1) <> 'M' THEN salary
   ELSE 0
   END
AS 'bonus' FROM Employees
order by employee_id;

# ANOTHER WAY OF WRITING

# SELECT employee_id,
#    CASE
#    WHEN employee_id%2=1 AND name NOT LIKE 'M%' THEN salary
#    ELSE 0
#    END
#  AS 'bonus' FROM Employees
# order by employee_id;