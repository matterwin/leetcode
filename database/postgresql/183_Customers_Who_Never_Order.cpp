select c.name as Customers 
from Customers c
left join Orders o 
on o.customerId = c.id 
where o.customerId is NULL;
