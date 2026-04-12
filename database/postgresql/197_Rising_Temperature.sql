SELECT w_today.id
FROM Weather w_today
LEFT JOIN Weather w_yes 
    ON w_yes.recordDate+1 = w_today.recordDate
WHERE w_today.temperature > w_yes.temperature


