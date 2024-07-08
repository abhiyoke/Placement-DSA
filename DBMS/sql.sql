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



