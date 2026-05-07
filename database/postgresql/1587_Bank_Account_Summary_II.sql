SELECT 
    u.name, 
    sum(amount) as balance
FROM transactions t
JOIN users u 
    on u.account = t.account
group by 1
having sum(amount) > 10000
