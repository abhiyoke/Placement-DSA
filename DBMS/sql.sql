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



