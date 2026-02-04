# Write your MySQL query statement below
SELECT d.name AS Department, e.name AS Employee, e.salary AS Salary FROM employee e JOIN department d ON e.departmentId = d.id JOIN (SELECT departmentId, MAX(salary) AS max_salary FROM employee GROUP BY departmentId) m ON e.departmentId = m.departmentId AND e.salary = m.max_salary;
