select c.name 
from Customer c
where c.referee_id is Null
or c.referee_id != 2;


