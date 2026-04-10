select id, move, description, rating
from Cinema
where mod(id, 2) = 1 and description <> 'boring'
order by rating desc;

