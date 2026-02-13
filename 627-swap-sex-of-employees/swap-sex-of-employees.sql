# Write your MySQL query statement below
-- select id, name, 
-- case when sex = 'f' then 'm' else 'f'  end as sex, salary from Salary ;

UPDATE Salary 
SET sex = CASE 
    WHEN sex = 'm' THEN 'f' 
    ELSE 'm' 
END;
