# Write your MySQL query statement below
select p.product_id ,
ROUND(IFNULL(sum(p.price*u.units)/sum(u.units),0),2) as average_price
from Prices p
left join UnitsSold u
ON p.product_id=u.product_id
AND u.purchase_date between start_date AND end_date
group by product_id


