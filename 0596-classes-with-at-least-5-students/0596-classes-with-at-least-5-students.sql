-- # Write your MySQL query statement below
-- select class
-- from Courses
-- group by class;
-- HAVING COUNT(student) >= 5;

SELECT class
FROM Courses
GROUP BY class
HAVING COUNT(student) >= 5;