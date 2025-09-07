# Write your MySQL query statement below
-- select e1.name as Employee from Employee e1 where e1.salary > (select e2.salary from Employee e2 where e2.managerId=e1.id);
SELECT e1.name AS Employee
FROM Employee e1
JOIN Employee e2 
  ON e1.managerId = e2.id
WHERE e1.salary > e2.salary;
