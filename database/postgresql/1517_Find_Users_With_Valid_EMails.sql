SELECT *
FROM Users
WHERE mail SIMILAR TO '[A-Za-z][A-Za-z0-9._-]*@leetcode\.com';

-- or can do ~ not version of it
SELECT user_id, name, mail
FROM Users
WHERE mail ~ '^[A-Za-z][A-Za-z0-9_.-]*@leetcode\.com$';
