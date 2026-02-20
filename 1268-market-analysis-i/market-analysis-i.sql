# Write your MySQL query statement below
SELECT 
    u.user_id as buyer_id,
    u.join_date,
    (
        SELECT COUNT(*) 
        FROM orders o
        WHERE o.buyer_id = u.user_id
        AND YEAR(o.order_date) = 2019
    ) AS orders_in_2019
FROM users u;