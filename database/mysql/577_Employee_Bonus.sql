ELECT e.name, b.bonus
FROM Employee e
LEFT JOIN Bonus b
    ON e.empId = b.empID
    where b.bonus < 1000 OR b.bonus IS NULL



