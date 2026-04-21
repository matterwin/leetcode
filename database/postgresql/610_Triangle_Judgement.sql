select x, y, z,
case 
    when x + y > z and x + z > y and y + z > x then 'Yes'
    Else 'No'
end as triangle
from Triangle;

