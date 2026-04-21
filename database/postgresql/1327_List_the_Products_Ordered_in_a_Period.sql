select 
	p.product_name,
	count(*) as unit
from Products p
inner join Orders o
	on p.product_id = o.product_id
where o.order_date between '2020-02-01' to '2020-02-28'
group by p.product_id;
