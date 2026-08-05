-- create
CREATE TABLE employees (
    emp_id INT PRIMARY KEY,
    name VARCHAR(50),
    department VARCHAR(50),
    manager_id INT,
    salary INT,
    hire_date DATE
);

-- insert
INSERT INTO employees VALUES
(1, 'Aarav', 'Engineering', NULL, 95000, '2021-03-15'),
(2, 'Diya', 'Engineering', 1, 82000, '2022-01-10'),
(3, 'Kabir', 'Engineering', 1, 78000, '2022-06-20'),
(4, 'Meera', 'Sales', NULL, 70000, '2020-11-05'),
(5, 'Rohan', 'Sales', 4, 65000, '2023-02-14'),
(6, 'Ishaan', 'Sales', 4, 68000, '2021-09-30'),
(7, 'Ananya', 'Marketing', NULL, 72000, '2022-04-01'),
(8, 'Vivaan', 'Marketing', 7, 60000, '2023-07-19'),
(9, 'Sara', 'Engineering', 1, 91000, '2020-08-12'),
(10, 'Kiaan', 'Sales', 4, 73000, '2022-12-01');

-- Date format is year-month-date 
-- if want some specific pattern SELECT DATE_FORMAT(NOW(), '%m/%d/%Y');

-- 1a Get the average salary per department, but only for departments with more than 3 employees.
SELECT department , AVG(salary)
from employees
group by department
having count(*) >3;

-- 1b
SELECT * from employees
where hire_date > '2021-12-31'
order by salary desc;

CREATE TABLE departments (
    dept_name VARCHAR(50) PRIMARY KEY,
    budget INT,
    location VARCHAR(50)
);

INSERT INTO departments VALUES
('Engineering', 500000, 'Bangalore'),
('Sales', 300000, 'Mumbai'),
('HR', 150000, 'Delhi');

-- 2a List each employee's name alongside their department's budget and location. Only show employees whose department has a budget record.
SELECT e.name , d.dept_name , d.budget , d.location
from employees e 
inner join departments d 
on e.department = d.dept_name;
-- 2b
SELECT d.dept_name , count(e.emp_id) as employee_count 
from departments d 
left join employees e
on d.dept_name = e.department
group by dept_name
order by employee_count desc;


SELECT e.name as employee , m.name as manager 
from employees e 
left join employees m 
on e.manager_id = m.emp_id;


SELECT e.name AS employee , m.name AS manager
FROM employees e
inner JOIN employees m
ON e.manager_id = m.emp_id
where e.salary > m.salary;


SELECT e.name as employee , e.salary as emp_salary 
from employees e
where e.salary > (SELECT AVG(e.salary) from employees e );


with avg_sal as ( SELECT AVG(salary) as avg_salary from employees)
SELECT e.name , e.salary
from employees e , avg_sal
where e.salary >avg_sal.avg_salary;


SELECT department, name, salary,
rank() over(partition by department order by salary desc) as salary_rank
from employees;


UPDATE employees SET salary = 82000 WHERE emp_id = 3;

SELECT department, name, salary,
    RANK() OVER (PARTITION BY department ORDER BY salary DESC) AS rnk,
    DENSE_RANK() OVER (PARTITION BY department ORDER BY salary DESC) AS dense_rnk,
    ROW_NUMBER() OVER (PARTITION BY department ORDER BY salary DESC) AS row_num
FROM employees;

-- 2nd highest salary in each department

with ranked as (
    SELECT department, name, salary,
    dense_rank() over (partition by department order by salary desc) as dranked
    from employees
)
SELECT department,name,salary
from ranked
where dranked =2;

with cumsal as (
    SELECT department, name, hire_date,
    sum(salary) over(partition by department order by hire_date desc) as cumsals
    from employees
)
SELECT department, name, hire_date, cumsals
from cumsal
order by department, hire_date desc;


with ranked as(
    SELECT department,name,salary,
    dense_rank() over(partition by department order by salary desc) as toptwo
    from employees 
)
SELECT department,name,salary
from ranked
where toptwo<=2
order by department;


SELECT department, name,hire_date,salary,
lag(salary) over(partition by department order by hire_date asc) as prev_salary
from employees;

SELECT name, salary FROM employees WHERE department = 'Engineering' AND salary > 90000
UNION
SELECT name, salary FROM employees WHERE department = 'Sales' AND salary > 70000;



SELECT name,salary,
case
    when salary >85000 then 'Senior'
    when salary between 70000 and 85000 then 'Mid'
else 'Junior'
end as Seniority 
from employees;



with labelled as (

    SELECT name,salary,
case
    when salary >85000 then 'Senior'
    when salary between 70000 and 85000 then 'Mid'
else 'Junior'
end as Seniority 
from employees
)

SELECT Seniority , count(*) as emp_pd from labelled 
group by Seniority
order by emp_pd desc;




















