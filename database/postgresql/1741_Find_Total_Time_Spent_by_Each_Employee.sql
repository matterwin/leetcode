select
	event_day as day,
    emp_id,
    sum(out_time - in_time) as total_time
from Employees e
group by day, emp_id;

