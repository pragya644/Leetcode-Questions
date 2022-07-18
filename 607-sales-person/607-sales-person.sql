# Write your MySQL query statement below

SELECT s.name 
FROM SalesPerson s
WHERE 
   s.sales_id NOT IN (SELECT
                      o.sales_id
                    FROM 
                       Orders o
                    JOIN 
                      Company USING(com_id)
                    WHERE 
                      Company.name = 'RED')
    ;
    
