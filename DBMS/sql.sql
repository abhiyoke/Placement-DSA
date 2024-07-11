1.total_price decimal(6,2),

2.--to delete data
delete from amazon_orders;

3.--limiting rows
select top 1 * from amazon_orders;

4.--data sorting
select * from amazon_orders
order by order_date desc,product_name desc,payment_method;

5.insert into amazon_orders values(3,'2022-10-01','Baby cream',30.5,'UPI');
insert into a_orders(order_id,order_date,product_name,total_price,payment_method) 
values(7,'2022-10-01','Shirts',132.5,'UPI');

6.--change data type of a column
alter table amazon_orders alter column order_date datetime; --DDL

7.payment_method varchar(20) check (payment_method in ('UPI','CREDIT CARD')) default 'UPI', --check constraint
discount integer check (discount<=20) , --check constraint,
category varchar(20) default 'Mens Wear' --default constarint

8.select top 5 sub_category,sum(sales) as total_sales
from orders
where profit>50
group by sub_category
having sum(sales) > 100000
order by total_sales desc

9. average of timestamp in which activtiy type is start and end and so need to subtract end-start.
select a1.machine_id,round(avg(a2.timestamp-a1.timestamp),3) as processing_time from Activity a1 join 
Activity a2 on a1.machine_id=a2.machine_id and a1.process_id=a2.process_id and a1.activity_type='start'
and a2.activity_type='end'
 group by a1.machine_id;

10. is null:
select e.name,b.bonus from Employee e left join Bonus b on e.empId=b.empId where b.bonus<1000 or bonus is null  order by e.empId;

11.COALESCE is a function that returns the first non-null value from a list of expressions. It's commonly used to handle NULL values by providing a 
 default value when a NULL is encountered.
 Imagine you have a table with employee information, and some employees don't have a middle name recorded.
SELECT  employee_id, first_name, COALESCE(middle_name, 'N/A') AS middle_name, last_nameFROM  Employees;

12.cross join:tb krte h jb hme do table sare columns chahiye hote h.
 select s.student_id,s.student_name,sub.subject_name,count(e.subject_name) as attended_exams from 
Students s cross join Subjects sub left join Examinations e on s.student_id=e.student_id and
sub.subject_name=e.subject_name group 
by s.student_id,s.student_name,sub.subject_name order by s.student_id,s.student_name; 

13.SELECT 
    s.user_id, 
    ROUND(avg(if(c.action = 'confirmed',1,0)), 2) AS confirmation_rate
FROM 
    Signups s 
LEFT JOIN 
    Confirmations c 
ON 
    s.user_id = c.user_id 
GROUP BY 
    s.user_id;

14.The ISNULL() function in SQL is used to replace NULL values with a specified replacement value.syntax:ISNULL(expression, replacement_value).
 SELECT p.product_id, IFNULL(round(SUM(p.price*u.units)/sum(u.units),2),0) as average_price FROM Prices p LEFT JOIN UnitsSold u
ON p.product_id = u.product_id AND  u.purchase_date BETWEEN p.Start_date and p.end_date GROUP BY p.product_id

15.if required count from another table:
select contest_id,round(count(distinct user_id)*100/(select count(user_id)from Users),2) as percentage from Register group by contest_id 
 order by percentage desc,contest_id ;

16.the SUBSTR (or SUBSTRING) function is used to extract a portion of a string. It's like cutting out a specific part of the text from a longer piece of text.
SUBSTR(string, start_position, length)
string: The text you want to cut from.
start_position: The position in the text where you want to start cutting.
length (optional): How many characters you want to cut out. If omitted, it will cut everything from the start position to the end of the string.

17.DATE_SUB function in SQL is used to subtract a specified time interval from a date. This function is often used to calculate dates in the past relative to a given date. The syntax for DATE_SUB is as follows:
DATE_SUB(date, INTERVAL expr unit)
date: The starting date from which the interval will be subtracted.
expr: The number of units of time to subtract.
unit: The unit of time, such as DAY, MONTH, YEAR, etc.Ex:SELECT * FROM orders WHERE order_date >= DATE_SUB(CURDATE(), INTERVAL 30 DAY);

18.count can't be added in where and can only added in starting or in having.
 select class from Courses  group by class having count(student)>=5;

19.UNION operator in SQL combines the results of two or more SELECT statements into a single result set.
 Each SELECT statement must have the same number of columns, with matching data types in the same order.
 select employee_id,department_id from Employee  where primary_flag='Y' union select employee_id,department_id from Employee group by employee_id
having count(employee_id)=1

20.LEAD Function:Fetches the value from the next row in the result set.
 SELECT employee_id, salary, LEAD(salary, 1) OVER (ORDER BY employee_id) AS next_salary FROM employees;
LAG Function: Fetches the value from the previous row in the result set.
 SELECT  employee_id, salary,  LAG(salary, 1) OVER (ORDER BY employee_id) AS previous_salaryFROM employees;

