# Write your MySQL query statement below
SELECT
date_format(trans_date, '%Y-%m') as month,
country,
COUNT(id) as trans_count,
sum(if(state = 'approved', 1,0)) as approved_count,
sum(amount) as trans_total_amount,
sum(if(state = 'approved', amount, 0)) as approved_total_amount
FROM Transactions
GROUP BY month, country;
