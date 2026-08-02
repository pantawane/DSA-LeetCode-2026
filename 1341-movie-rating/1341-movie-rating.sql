# Write your MySQL query statement below
(SELECT u.name as results
from users u
LEFT JOIN MovieRating mr
on u.user_id = mr.user_id
group by u.user_id
order by count(mr.user_id) desc, u.name
limit 1)
UNION ALL
(SELECT m.title as results
from movies m
LEFT JOIN MovieRating mr
on m.movie_id = mr.movie_id
where extract(year_month from created_at) = 202002
group by m.movie_id
order by avg(mr.rating) desc, m.title
limit 1)
