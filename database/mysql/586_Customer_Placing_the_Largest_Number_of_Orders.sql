select customer_number
From Orders 
group by customer_number
order by count(*) desc 
limit 1;
