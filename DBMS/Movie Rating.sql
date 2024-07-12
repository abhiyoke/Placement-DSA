Table: Movies

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| movie_id      | int     |
| title         | varchar |
+---------------+---------+
movie_id is the primary key (column with unique values) for this table.
title is the name of the movie.
 

Table: Users

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| user_id       | int     |
| name          | varchar |
+---------------+---------+
user_id is the primary key (column with unique values) for this table.
 

Table: MovieRating

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| movie_id      | int     |
| user_id       | int     |
| rating        | int     |
| created_at    | date    |
+---------------+---------+
(movie_id, user_id) is the primary key (column with unique values) for this table.
This table contains the rating of a movie by a user in their review.
created_at is the users review date. 
 

Write a solution to:

Find the name of the user who has rated the greatest number of movies. In case of a tie, return the lexicographically smaller user name.
Find the movie name with the highest average rating in February 2020. In case of a tie, return the lexicographically smaller movie name.

(SELECT u.name AS results
FROM Users u
JOIN MovieRating m ON u.user_id = m.user_id
GROUP BY u.name
ORDER BY COUNT(m.movie_id) DESC, u.name ASC
LIMIT 1
)
UNION ALL
(
SELECT mo.title AS results
FROM Movies mo
JOIN MovieRating mr ON mo.movie_id = mr.movie_id
WHERE substr(mr.created_at,1,7) = '2020-02'
GROUP BY mo.title
ORDER BY AVG(mr.rating) DESC, mo.title ASC
LIMIT 1
)
