# Write your MySQL query statement below
SELECT * ,
if(x+y > z AND y+z > x AND x+z > y, 'Yes', 'No') as triangle
FROM Triangle;