# Write your MySQL query statement below
SELECT max(num) as num FROM
(SELECT num 
FROM MyNumbers
GROUP BY num
HAVING COUNT(num) = 1) as max_Nums;