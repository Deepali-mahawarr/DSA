# Write your MySQL query statement below
select ROUND(SUM(tiv_2016),2) as tiv_2016 
from Insurance 
where tiv_2015 in (
    select tiv_2015
    from Insurance
    Group by tiv_2015
    Having count(tiv_2015)>1

)
AND (lat,lon) IN(
     SELECT lat, lon
    FROM Insurance
    GROUP BY lat, lon
    HAVING COUNT(*) = 1
);