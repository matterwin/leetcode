SELECT 
    p.product_id,
    ROUND(
        COALESCE(SUM(p.price * u.units) * 1.0 / SUM(u.units), 0),
        2
    ) AS average_price
FROM Prices p
LEFT JOIN UnitsSold u
    ON p.product_id = u.product_id
GROUP BY p.product_id;
