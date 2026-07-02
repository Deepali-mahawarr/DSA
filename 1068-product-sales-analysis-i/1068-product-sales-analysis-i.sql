# Write your MySQL query statement below
select e1.product_name ,e2.year,e2.price
from Sales as e2
left join Product as e1
on e2.product_id=e1.product_id;

