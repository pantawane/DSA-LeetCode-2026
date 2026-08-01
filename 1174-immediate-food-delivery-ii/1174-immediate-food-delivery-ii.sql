# Write your MySQL query statement below
SELECT 
ROUND(SUM(if(min_Order = min_pref, 1, 0) * 100) / COUNT(customer_id),2) as immediate_percentage
FROM
(SELECT delivery_id,
customer_id,
min(order_date) as min_Order ,
min(customer_pref_delivery_date) as min_Pref
FROM Delivery
GROUP BY customer_id) as New_table;