# Write your MySQL query statement below
select C.name as Customers from Customers C where C.id NOT IN (select O.customerId from Orders O); 