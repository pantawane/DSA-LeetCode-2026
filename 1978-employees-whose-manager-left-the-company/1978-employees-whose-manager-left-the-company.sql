SELECT employee_id
FROM Employees e1
WHERE salary < 30000
AND manager_id not in (
    SELECT employee_id from employees
)
order by employee_id;