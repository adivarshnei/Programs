<span style = "font-family:Nunito">

## Given Tables:

### Worker
|WORKER_ID|FIRST_NAME|LAST_NAME|SALARY|   JOINING_DATE    |DEPARTMENT|
|:-------:|:--------:|:-------:|:----:|:-----------------:|:--------:|
|   001   |  Monika  |  Arora  |100000|2014-02-20 09:00:00|    HR    |
|   002   | Niharika |  Verma  |80000 |2014-06-11 09:00:00|  Admin   |
|   003   |  Vishal  | Singhal |300000|2014-02-20 09:00:00|    HR    |
|   004   | Amitabh  |  Singh  |500000|2014-02-20 09:00:00|  Admin   |
|   005   |  Vivek   |  Bhati  |500000|2014-06-11 09:00:00|  Admin   |
|   006   |  Vipul   |  Diwan  |200000|2014-06-11 09:00:00| Account  |
|   007   |  Satish  |  Kumar  |75000 |2014-01-20 09:00:00| Account  |
|   008   | Geetika  | Chauhan |90000 |2014-04-11 09:00:00|  Admin   |

### Bonus
|WORKER_REF_ID|    BONUS_DATE     |BONUS_AMOUNT|
|:-----------:|:-----------------:|:----------:|
|      1      |2016-02-20 00:00:00|    5000    |
|      2      |2016-06-11 00:00:00|    3000    |
|      3      |2016-02-20 00:00:00|    4000    |
|      1      |2016-02-20 00:00:00|    4500    |
|      2      |2016-06-11 00:00:00|    3500    |

### Title
|WORKER_REF_ID|WORKER_TITLE |   AFFECTED_FROM   |
|:-----------:|:-----------:|:-----------------:|
|      1      |   Manager   |2016-02-20 00:00:00|
|      2      |  Executive  |2016-06-11 00:00:00|
|      8      |  Executive  |2016-06-11 00:00:00|
|      5      |   Manager   |2016-06-11 00:00:00|
|      4      |Asst. Manager|2016-06-11 00:00:00|
|      7      |  Executive  |2016-06-11 00:00:00|
|      6      |    Lead     |2016-06-11 00:00:00|
|      3      |    Lead     |2016-06-11 00:00:00|

## SQL Queries:

#### 1. Write an SQL query to fetch <span style = "font-family:Input">FIRST_NAME</span> from <span style = "font-family:Input">Worker</span> table in uppercase.
#### 2. Write an SQL query to fetch unique values of <span style = "font-family:Input">DEPARTMENT</span> from <span style = "font-family:Input">Worker</span> table.
#### 3. Write an SQL query to print the first three characters of <span style = "font-family:Input">FIRST_NAME</span> from <span style = "font-family:Input">Worker</span>.
#### 4. Write an SQL query to find the position of the alphabet <span style = "font-family:Input">('a')</span> in the first name column <span style = "font-family:Input">'Amitabh'</span> from <span style = "font-family:Input">Worker</span> table.
#### 5. Write an SQL query that fetches the unique values of <span style = "font-family:Input">DEPARTMENT</span> from <span style = "font-family:Input">Worker</span> table and prints its length.
#### 6. Write an SQL query to print details of the Workers whose <span style = "font-family:Input">FIRST_NAME</span> contains <span style = "font-family:Input">'a'</span>.
#### 7. Write an SQL query to print details of the Workers whose <span style = "font-family:Input">FIRST_NAME</span> ends with <span style = "font-family:Input">'h'</span> and contains six alphabets.
#### 8. Write an SQL query to fetch the no. of workers for each department in descending order.
#### 9. Write an SQL query to print details of workers who are also managers.
#### 10. Write an SQL query to show only odd rows from a table.
#### 11. Write an SQL query to show only even rows from a table.
#### 12. Write an SQL query to show the current date and time.
#### 13. Write an SQL query to show the top $n$ (say $10$) records of a table.
#### 14. Write an SQL query to determine the $n$<sup>th</sup> (say $n=5$) highest salary from a table.
#### 15. Write an SQL query to determine the $5$<sup>th</sup> highest salary without using <span style = "font-family:Input">TOP</span> or <span style = "font-family:Input">limit</span> method.
#### 16. Write an SQL query to fetch the list of employees with the same salary.
#### 17. Write an SQL query to show the second highest salary from a table.
#### 18. Write an SQL query to fetch the first $50$% records from a table.
#### 19. Write an SQL query to fetch the departments that have less than $5$ people in it.
#### 20. Write an SQL query to print the name of employees having the highest salary in each department.
</span>
