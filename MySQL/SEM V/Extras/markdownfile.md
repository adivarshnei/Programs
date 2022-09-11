<span style = "font-family:Nunito">

# Given Tables:

## Worker
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

## Bonus
|WORKER_REF_ID|    BONUS_DATE     |BONUS_AMOUNT|
|:-----------:|:-----------------:|:----------:|
|      1      |2016-02-20 00:00:00|    5000    |
|      2      |2016-06-11 00:00:00|    3000    |
|      3      |2016-02-20 00:00:00|    4000    |
|      1      |2016-02-20 00:00:00|    4500    |
|      2      |2016-06-11 00:00:00|    3500    |

## Title
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

# Table Creation

## Worker

#### Query:
```sql
CREATE TABLE Worker (
    WORKER_ID INTEGER(3) NOT NULL UNIQUE PRIMARY KEY,
    FIRST_NAME VARCHAR(10),
    LAST_NAME VARCHAR(10),
    SALARY INTEGER(6),
    JOINING_DATE DATETIME,
    DEPARTMENT VARCHAR(10)
);

INSERT INTO Worker (
    WORKER_ID,
    FIRST_NAME,
    LAST_NAME,
    SALARY,
    JOINING_DATE,
    DEPARTMENT
) VALUES
    (001, 'Monika', 'Arora', 100000, '2014-02-20 09:00:00', 'HR'),
    (002, 'Niharika', 'Verma', 80000, '2014-06-11 09:00:00', 'Admin'),
    (003, 'Vishal', 'Singhal', 300000, '2014-02-20 09:00:00', 'HR'),
    (004, 'Amitabh', 'Singh', 500000, '2014-02-20 09:00:00', 'Admin'),
    (005, 'Vivek', 'Bhati', 500000, '2014-06-11 09:00:00', 'Admin'),
    (006, 'Vipul', 'Diwan', 200000, '2014-06-11 09:00:00', 'Account'),
    (007, 'Satish', 'Kumar', 75000, '2014-01-20 09:00:00', 'Account'),
    (008, 'Geetika', 'Chauhan', 90000, '2014-04-11 09:00:00', 'Admin');

SELECT *
FROM Worker;
```

#### Output:
```
mysql> CREATE TABLE Worker (
    ->     WORKER_ID INTEGER(3) NOT NULL UNIQUE PRIMARY KEY,
    ->     FIRST_NAME VARCHAR(10),
    ->     LAST_NAME VARCHAR(10),
    ->     SALARY INTEGER(6),
    ->     JOINING_DATE DATETIME,
    ->     DEPARTMENT VARCHAR(10)
    -> );
Query OK, 0 rows affected, 2 warnings (0.06 sec)

mysql> 
mysql> INSERT INTO Worker (
    ->     WORKER_ID,
    ->     FIRST_NAME,
    ->     LAST_NAME,
    ->     SALARY,
    ->     JOINING_DATE,
    ->     DEPARTMENT
    -> ) VALUES
    ->     (001, 'Monika', 'Arora', 100000, '2014-02-20 09:00:00', 'HR'),
    ->     (002, 'Niharika', 'Verma', 80000, '2014-06-11 09:00:00', 'Admin'),
    ->     (003, 'Vishal', 'Singhal', 300000, '2014-02-20 09:00:00', 'HR'),
    ->     (004, 'Amitabh', 'Singh', 500000, '2014-02-20 09:00:00', 'Admin'),
    ->     (005, 'Vivek', 'Bhati', 500000, '2014-06-11 09:00:00', 'Admin'),
    ->     (006, 'Vipul', 'Diwan', 200000, '2014-06-11 09:00:00', 'Account'),
    ->     (007, 'Satish', 'Kumar', 75000, '2014-01-20 09:00:00', 'Account'),
    ->     (008, 'Geetika', 'Chauhan', 90000, '2014-04-11 09:00:00', 'Admin');
Query OK, 8 rows affected (0.01 sec)
Records: 8  Duplicates: 0  Warnings: 0

mysql> 
mysql> SELECT *
    -> FROM Worker;
+-----------+------------+-----------+--------+---------------------+------------+
| WORKER_ID | FIRST_NAME | LAST_NAME | SALARY | JOINING_DATE        | DEPARTMENT |
+-----------+------------+-----------+--------+---------------------+------------+
|         1 | Monika     | Arora     | 100000 | 2014-02-20 09:00:00 | HR         |
|         2 | Niharika   | Verma     |  80000 | 2014-06-11 09:00:00 | Admin      | 
|         3 | Vishal     | Singhal   | 300000 | 2014-02-20 09:00:00 | HR         | 
|         4 | Amitabh    | Singh     | 500000 | 2014-02-20 09:00:00 | Admin      | 
|         5 | Vivek      | Bhati     | 500000 | 2014-06-11 09:00:00 | Admin      | 
|         6 | Vipul      | Diwan     | 200000 | 2014-06-11 09:00:00 | Account    | 
|         7 | Satish     | Kumar     |  75000 | 2014-01-20 09:00:00 | Account    | 
|         8 | Geetika    | Chauhan   |  90000 | 2014-04-11 09:00:00 | Admin      |
+-----------+------------+-----------+--------+---------------------+------------+ 
8 rows in set (0.00 sec)
```

## Bonus

#### Query:
```sql
CREATE TABLE Bonus (
    WORKER_REF_ID INTEGER(3) NOT NULL,
    BONUS_DATE DATETIME,
    BONUS_AMOUNT INTEGER(5),

    CONSTRAINT FOREIGN KEY(WORKER_REF_ID) REFERENCES Worker(WORKER_ID)
);

INSERT INTO Bonus (WORKER_REF_ID, BONUS_DATE, BONUS_AMOUNT) VALUES
    (1, '2016-02-20 00:00:00', 5000),
    (2, '2016-06-11 00:00:00', 3000),
    (3, '2016-02-20 00:00:00', 4000),
    (1, '2016-02-20 00:00:00', 4500),
    (2, '2016-06-11 00:00:00', 3500);

SELECT *
FROM Bonus;
```

#### Output:
```
mysql> CREATE TABLE Bonus (
    ->     WORKER_REF_ID INTEGER(3) NOT NULL,
    ->     BONUS_DATE DATETIME,
    ->     BONUS_AMOUNT INTEGER(5),
    ->
    ->     CONSTRAINT FOREIGN KEY(WORKER_REF_ID) REFERENCES Worker(WORKER_ID)      
    -> );
Query OK, 0 rows affected, 2 warnings (0.06 sec)

mysql>
mysql> INSERT INTO Bonus (WORKER_REF_ID, BONUS_DATE, BONUS_AMOUNT) VALUES
    ->     (1, '2016-02-20 00:00:00', 5000),
    ->     (2, '2016-06-11 00:00:00', 3000),
    ->     (3, '2016-02-20 00:00:00', 4000),
    ->     (1, '2016-02-20 00:00:00', 4500),
    ->     (2, '2016-06-11 00:00:00', 3500);
Query OK, 5 rows affected (0.01 sec)
Records: 5  Duplicates: 0  Warnings: 0

mysql>
mysql> SELECT *
    -> FROM Bonus;
+---------------+---------------------+--------------+
| WORKER_REF_ID | BONUS_DATE          | BONUS_AMOUNT |
+---------------+---------------------+--------------+
|             1 | 2016-02-20 00:00:00 |         5000 |
|             2 | 2016-06-11 00:00:00 |         3000 |
|             3 | 2016-02-20 00:00:00 |         4000 |
|             1 | 2016-02-20 00:00:00 |         4500 |
|             2 | 2016-06-11 00:00:00 |         3500 |
+---------------+---------------------+--------------+
5 rows in set (0.00 sec)
```

## Title

#### Query:
```sql
CREATE TABLE Title (
    WORKER_REF_ID INTEGER(3) NOT NULL,
    WORKER_TITLE VARCHAR(15),
    AFFECTED_FROM DATETIME,

    CONSTRAINT FOREIGN KEY(WORKER_REF_ID) REFERENCES Worker(WORKER_ID)
);

INSERT INTO Title (WORKER_REF_ID, WORKER_TITLE, AFFECTED_FROM) VALUES
    (1, 'Manager', '2016-02-20 00:00:00'),
    (2, 'Executive', '2016-06-11 00:00:00'),
    (8, 'Executive', '2016-06-11 00:00:00'),
    (5, 'Manager', '2016-06-11 00:00:00'),
    (4, 'Asst. Manager', '2016-06-11 00:00:00'),
    (7, 'Executive', '2016-06-11 00:00:00'),
    (6, 'Lead', '2016-06-11 00:00:00'),
    (3, 'Lead', '2016-06-11 00:00:00');

SELECT *
FROM Title;
```

#### Output:
```
mysql> CREATE TABLE Title (
    ->     WORKER_REF_ID INTEGER(3) NOT NULL,
    ->     WORKER_TITLE VARCHAR(15),
    ->     AFFECTED_FROM DATETIME,
    ->
    ->     CONSTRAINT FOREIGN KEY(WORKER_REF_ID) REFERENCES Worker(WORKER_ID)
    -> );
Query OK, 0 rows affected, 1 warning (0.06 sec)

mysql>
mysql> INSERT INTO Title (WORKER_REF_ID, WORKER_TITLE, AFFECTED_FROM) VALUES
    ->     (1, 'Manager', '2016-02-20 00:00:00'),
    ->     (2, 'Executive', '2016-06-11 00:00:00'),
    ->     (8, 'Executive', '2016-06-11 00:00:00'),
    ->     (5, 'Manager', '2016-06-11 00:00:00'),
    ->     (4, 'Asst. Manager', '2016-06-11 00:00:00'),
    ->     (7, 'Executive', '2016-06-11 00:00:00'),
    ->     (6, 'Lead', '2016-06-11 00:00:00'),
    ->     (3, 'Lead', '2016-06-11 00:00:00');
Query OK, 8 rows affected (0.01 sec)
Records: 8  Duplicates: 0  Warnings: 0

mysql>
mysql> SELECT *
    -> FROM Title;
+---------------+---------------+---------------------+
| WORKER_REF_ID | WORKER_TITLE  | AFFECTED_FROM       |
+---------------+---------------+---------------------+
|             1 | Manager       | 2016-02-20 00:00:00 |
|             2 | Executive     | 2016-06-11 00:00:00 |
|             8 | Executive     | 2016-06-11 00:00:00 |
|             5 | Manager       | 2016-06-11 00:00:00 |
|             4 | Asst. Manager | 2016-06-11 00:00:00 |
|             7 | Executive     | 2016-06-11 00:00:00 |
|             6 | Lead          | 2016-06-11 00:00:00 |
|             3 | Lead          | 2016-06-11 00:00:00 |
+---------------+---------------+---------------------+
8 rows in set (0.00 sec)
```

# SQL Queries

### 1. Write an SQL query to fetch <span style = "font-family:Input">FIRST_NAME</span> from <span style = "font-family:Input">Worker</span> table in uppercase.

#### Query:
```sql
SELECT UPPER(FIRST_NAME) AS 'First Name in Uppercase'
FROM Worker;
```

#### Output:
```
mysql> SELECT UPPER(FIRST_NAME) AS 'First Name in Uppercase'
    -> FROM Worker;
+-------------------------+
| First Name in Uppercase |
+-------------------------+
| MONIKA                  |
| NIHARIKA                |
| VISHAL                  |
| AMITABH                 |
| VIVEK                   |
| VIPUL                   |
| SATISH                  |
| GEETIKA                 |
+-------------------------+
8 rows in set (0.01 sec)
```

### 2. Write an SQL query to fetch unique values of <span style = "font-family:Input">DEPARTMENT</span> from <span style = "font-family:Input">Worker</span> table.

#### Query:
```sql
SELECT DEPARTMENT AS 'Department'
FROM Worker
GROUP BY DEPARTMENT;
```

#### Output:
```
mysql> SELECT DEPARTMENT AS 'Department'
    -> FROM Worker
    -> GROUP BY DEPARTMENT;
+------------+
| Department |
+------------+
| HR         |
| Admin      |
| Account    |
+------------+
3 rows in set (0.00 sec)
```

### 3. Write an SQL query to print the first three characters of <span style = "font-family:Input">FIRST_NAME</span> from <span style = "font-family:Input">Worker</span>.

#### Query:
```sql
SELECT SUBSTRING(FIRST_NAME, 1, 3) AS 'First Three Characters of First Name'
FROM Worker;
```

#### Output:
```
mysql> SELECT SUBSTRING(FIRST_NAME, 1, 3) AS 'First Three Characters of First Name'
    -> FROM Worker;
+--------------------------------------+
| First Three Characters of First Name |
+--------------------------------------+
| Mon                                  |
| Nih                                  |
| Vis                                  |
| Ami                                  |
| Viv                                  |
| Vip                                  |
| Sat                                  |
| Gee                                  |
+--------------------------------------+
8 rows in set (0.00 sec)
```

### 4. Write an SQL query to find the position of the alphabet <span style = "font-family:Input">('a')</span> in the first name column <span style = "font-family:Input">'Amitabh'</span> from <span style = "font-family:Input">Worker</span> table.

#### Query:
```sql
SELECT
    INSTR(FIRST_NAME, 'a')
        AS 'Position of ''a'' in ''Amitabh'' in FIRST_NAME'
FROM Worker
WHERE FIRST_NAME = 'Amitabh';
```

#### Output:
```
mysql> SELECT
    ->     INSTR(FIRST_NAME, 'a')
    ->         AS 'Position of ''a'' in ''Amitabh'' in FIRST_NAME'
    -> FROM Worker
    -> WHERE FIRST_NAME = 'Amitabh';
+--------------------------------------------+
| Position of 'a' in 'Amitabh' in FIRST_NAME |
+--------------------------------------------+
|                                          1 |
+--------------------------------------------+
1 row in set (0.00 sec)
```

### 5. Write an SQL query that fetches the unique values of <span style = "font-family:Input">DEPARTMENT</span> from <span style = "font-family:Input">Worker</span> table and prints its length.

#### Query:
```sql
SELECT DEPARTMENT AS 'Department', LENGTH(DEPARTMENT) AS 'Name Length'
FROM Worker
GROUP BY DEPARTMENT;
```

#### Output:
```
mysql> SELECT DEPARTMENT AS 'Department', LENGTH(DEPARTMENT) AS 'Name Length'
    -> FROM Worker
    -> GROUP BY DEPARTMENT;
+------------+-------------+
| Department | Name Length |
+------------+-------------+
| HR         |           2 |
| Admin      |           5 |
| Account    |           7 |
+------------+-------------+
3 rows in set (0.00 sec)
```

### 6. Write an SQL query to print details of the Workers whose <span style = "font-family:Input">FIRST_NAME</span> contains <span style = "font-family:Input">'a'</span>.

#### Query:
```sql
```

#### Output:
```
```

### 7. Write an SQL query to print details of the Workers whose <span style = "font-family:Input">FIRST_NAME</span> ends with <span style = "font-family:Input">'h'</span> and contains six alphabets.

#### Query:
```sql
```

#### Output:
```
```

### 8. Write an SQL query to fetch the no. of workers for each department in descending order.

#### Query:
```sql
```

#### Output:
```
```

### 9. Write an SQL query to print details of workers who are also managers.

#### Query:
```sql
```

#### Output:
```
```

### 10. Write an SQL query to show only odd rows from a table.

#### Query:
```sql
```

#### Output:
```
```

### 11. Write an SQL query to show only even rows from a table.

#### Query:
```sql
```

#### Output:
```
```

### 12. Write an SQL query to show the current date and time.

#### Query:
```sql
```

#### Output:
```
```

### 13. Write an SQL query to show the top $n$ (say $10$) records of a table.

#### Query:
```sql
```

#### Output:
```
```

### 14. Write a SQL query to determine the $n$<sup>th</sup> (say $n=5$) highest salary from a table.

#### Query:
```sql
```

#### Output:
```
```

### 15. Write an SQL query to determine the $5$<sup>th</sup> highest salary without using <span style = "font-family:Input">TOP</span> or <span style = "font-family:Input">limit</span> method.

#### Query:
```sql
```

#### Output:
```
```

### 16. Write an SQL query to fetch the list of employees with the same salary.

#### Query:
```sql
```

#### Output:
```
```

### 17. Write an SQL query to show the second highest salary from a table.

#### Query:
```sql
```

#### Output:
```
```

### 18. Write an SQL query to fetch the first $50$% records from a table.

#### Query:
```sql
```

#### Output:
```
```

### 19. Write an SQL query to fetch the departments that have less than $5$ people in it.

#### Query:
```sql
```

#### Output:
```
```

### 20. Write an SQL query to print the name of employees having the highest salary in each department.

#### Query:
```sql
```

#### Output:
```
```

</span>
=]=]
