select
	*
from products p
where description ~ '\mSN[0-9]{4}-[0-9]{4}\M'
order by p.product_id asc;
    
