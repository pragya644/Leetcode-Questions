# Write your MySQL query statement below

SELECT id,'Root' as type
FROM Tree
WHERE p_id is NULL

UNION

SELECT id,'Leaf' as type
FROM Tree
WHERE id NOT IN
     (SELECT DISTINCT p_id 
      FROM Tree 
      WHERE p_id is NOT NULL) AND p_id is NOT NULL

UNION

SELECT id,'Inner' as type
FROM Tree
WHERE ID IN 
         (SELECT DISTINCT p_id 
          FROM Tree 
          WHERE p_id IS NOT NULL) AND p_id is NOT NULL;