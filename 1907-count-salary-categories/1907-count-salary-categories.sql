# Write your MySQL query statement below
SELECT "Low Salary" as category,
SUM(if(income < 20000, 1, 0)) as accounts_count
FROM Accounts
UNION
SELECT "Average Salary" as category,
SUM(if(income >= 20000 AND income <= 50000, 1, 0)) as accounts_count
FROM Accounts
UNION
SELECT "High Salary" as category,
SUM(if(income > 50000, 1, 0)) as accounts_count
FROM Accounts
