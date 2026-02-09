# Write your MySQL query statement below
SELECT ROUND(SUM(it.tiv_2016), 2) AS tiv_2016
FROM insurance it
WHERE it.tiv_2015 IN (
    SELECT tiv_2015
    FROM insurance
    GROUP BY tiv_2015
    HAVING COUNT(*) > 1
)
AND (it.lat, it.lon) IN (
    SELECT lat, lon
    FROM insurance
    GROUP BY lat, lon
    HAVING COUNT(*) = 1
);
