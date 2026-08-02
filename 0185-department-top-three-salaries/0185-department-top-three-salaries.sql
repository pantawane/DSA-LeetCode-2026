# Write your MySQL query statement below
select Department, Employee, Salary from
(SELECT d.name as department, e.name as employee, e.salary as salary,
dense_rank()over(partition by d.name order by e.salary desc) as ranks
from Employee e
LEFT JOIN Department d
on e.departmentId = d.id) temp
where ranks <=3;
