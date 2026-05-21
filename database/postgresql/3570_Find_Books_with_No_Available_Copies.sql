SELECT
    lb.book_id,
    lb.title,
    lb.author,
    lb.genre,
    lb.publication_year,
    COALESCE(br.current_borrowers, 0) AS current_borrowers
FROM library_books lb
JOIN (
    SELECT
        book_id,
        COUNT(*) AS current_borrowers
    FROM borrowing_records
    WHERE return_date IS NULL
    GROUP BY book_id
) br
    ON lb.book_id = br.book_id
WHERE lb.total_copies - br.current_borrowers = 0
ORDER BY br.current_borrowers DESC, lb.title ASC;
