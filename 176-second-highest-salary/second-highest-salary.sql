# Write your MySQL query statement below
-- select salary as SecondHighestSalary from Employee where salary < (select max(salary) from Employee) order by salary desc limit 1;
SELECT IFNULL((
    SELECT salary
    FROM Employee
    WHERE salary < (SELECT MAX(salary) FROM Employee)
    ORDER BY salary DESC
    LIMIT 1
), NULL) AS SecondHighestSalary;
