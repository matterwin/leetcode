SELECT name
FROM Employee e
where e.salary > (
        select salary
        from Employee m 
        where m.id = e.mangerId
);

SELECT name as Employee
FROM Employee e
WHERE e.salary > (
    SELECT salary
    FROM Employee m
    WHERE m.id = e.managerId
);
