# Write your MySQL query statement below
select Department.name as Department, Employee.name as Employee, Employee.salary as Salary
from Employee
join Department
on Employee.departmentId = Department.id
where
    3 > (select count(distinct e.salary)
        from Employee e
        where e.salary > Employee.salary and Employee.departmentId = e.departmentId);