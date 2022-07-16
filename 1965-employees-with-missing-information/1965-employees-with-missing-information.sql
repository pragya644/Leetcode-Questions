# Write your MySQL query statement below
SELECT employees.employee_id
FROM employees
LEFT JOIN salaries USING(employee_id)
WHERE salary IS NULL

UNION

# in this salaries table will take data which is common with employee table and as well as data which is left in salaries table. so in right join we are selecting only that common where name is null 
# eg common is 5,5 but name is not null so we were not going to select , that's how we are selecting only unique from tablee.

SELECT salaries.employee_id  # righ table is salaries
FROM employees 
RIGHT JOIN salaries ON salaries.employee_id = employees.employee_id
WHERE name IS NULL
ORDER BY employee_id;