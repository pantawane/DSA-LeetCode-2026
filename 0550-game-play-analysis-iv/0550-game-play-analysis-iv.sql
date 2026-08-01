# Write your MySQL query statement below
SELECT
ROUND(SUM(player_login ) / COUNT(DISTINCT player_id),2) as fraction
FROM
(SELECT player_id,
DATEDIFF(event_date, min(event_date) OVER(PARTITION BY player_id))= 1 as player_login
FROM Activity) as New_table;