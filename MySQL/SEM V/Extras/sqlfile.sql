\! cls

-- Initialization
DROP DATABASE extras;
CREATE DATABASE extras;
USE extras;

-- Table Creation and Data Entry
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

-- Queries
-- 1. Write an SQL query to fetch FIRST_NAME from Worker table in uppercase.
SELECT UPPER(W.FIRST_NAME) AS 'First Name in Uppercase'
FROM Worker W;

-- 2. Write an SQL query to fetch unique values of DEPARTMENT from Worker table.
SELECT W.DEPARTMENT AS 'Department'
FROM Worker W
GROUP BY W.DEPARTMENT;

-- 3. Write an SQL query to print the first three characters of FIRST_NAME from
-- Worker.
SELECT SUBSTRING(W.FIRST_NAME, 1, 3) AS 'First Three Characters of First Name'
FROM Worker W;

-- 4. Write an SQL query to find the position of the alphabet ('a') in the first
-- name column 'Amitabh' from Worker table.
SELECT
    INSTR(W.FIRST_NAME, 'a')
        AS 'Position of ''a'' in ''Amitabh'' in FIRST_NAME'
FROM Worker W
WHERE W.FIRST_NAME = 'Amitabh';

-- 5. Write an SQL query that fetches the unique values of DEPARTMENT from
-- Worker table and prints its length.
SELECT W.DEPARTMENT AS 'Department', LENGTH(W.DEPARTMENT) AS 'Name Length'
FROM Worker W
GROUP BY W.DEPARTMENT;

-- 6. Write an SQL query to print details of the Workers whose FIRST_NAME
-- contains 'a'.
SELECT
    W.WORKER_ID AS 'Worker ID',
    W.FIRST_NAME AS "First Name",
    W.LAST_NAME AS "Last Name",
    W.SALARY AS "Salary",
    W.JOINING_DATE AS "Joining Date",
    W.DEPARTMENT AS "Department"
FROM Worker W
WHERE W.FIRST_NAME LIKE '%a%';

-- 7. Write an SQL query to print details of the Workers whose FIRST_NAME ends
-- with 'h' and contains six alphabets.
SELECT
    W.WORKER_ID AS 'Worker ID',
    W.FIRST_NAME AS 'First Name',
    W.LAST_NAME AS 'Last Name',
    W.SALARY AS 'Salary',
    W.JOINING_DATE AS 'Joining Date',
    W.DEPARTMENT AS 'Department'
FROM Worker W
WHERE W.FIRST_NAME LIKE '_____h';

-- 8. Write an SQL query to fetch the no. of workers for each department in
-- descending order.
SELECT W.DEPARTMENT AS 'Department', COUNT(W.DEPARTMENT) AS 'Number of Workers'
FROM Worker W
GROUP BY W.DEPARTMENT
ORDER BY COUNT(W.DEPARTMENT);

-- 9. Write an SQL query to print details of workers who are also managers.
SELECT
    W.WORKER_ID AS 'Worker ID',
    W.FIRST_NAME AS 'First Name',
    W.LAST_NAME AS 'Last Name',
    W.SALARY AS 'Salary',
    W.JOINING_DATE AS 'Joining Date',
    W.DEPARTMENT AS 'Department',
    T.WORKER_TITLE AS 'Title',
    T.AFFECTED_FROM AS 'Title Affect Date'
FROM Worker W, Title T
WHERE W.WORKER_ID = T.WORKER_REF_ID AND T.WORKER_TITLE = "Manager";

-- 10. Write an SQL query to show only odd rows from a table.
SELECT
    W.WORKER_ID AS 'Worker ID',
    W.FIRST_NAME AS 'First Name',
    W.LAST_NAME AS 'Last Name',
    W.SALARY AS 'Salary',
    W.JOINING_DATE AS 'Joining Date',
    W.DEPARTMENT AS 'Department'
FROM Worker W
WHERE MOD(W.WORKER_ID, 2) <> 0;

-- 11. Write an SQL query to show only even rows from a table.
SELECT
    W.WORKER_ID AS 'Worker ID',
    W.FIRST_NAME AS 'First Name',
    W.LAST_NAME AS 'Last Name',
    W.SALARY AS 'Salary',
    W.JOINING_DATE AS 'Joining Date',
    W.DEPARTMENT AS 'Department'
FROM Worker W
WHERE MOD(W.WORKER_ID, 2) = 0;

-- 12. Write an SQL query to show the current date and time.
SELECT CONCAT(DATE(NOW()), " ", TIME(NOW())) AS "Current Date, Time";

-- 13. Write an SQL query to show the top n (say 10) records of a table.
SELECT
    W.WORKER_ID AS 'Worker ID',
    W.FIRST_NAME AS 'First Name',
    W.LAST_NAME AS 'Last Name',
    W.SALARY AS 'Salary',
    W.JOINING_DATE AS 'Joining Date',
    W.DEPARTMENT AS 'Department'
FROM Worker W
LIMIT 5;

-- 14. Write a SQL query to determine the nth (say n=5) highest salary from a
-- table.
SELECT
    W.WORKER_ID AS 'Worker ID',
    W.FIRST_NAME AS 'First Name',
    W.LAST_NAME AS 'Last Name',
    W.SALARY AS 'Salary',
    W.JOINING_DATE AS 'Joining Date',
    W.DEPARTMENT AS 'Department'
FROM Worker W
ORDER BY W.SALARY DESC
LIMIT 1
OFFSET 4;

-- 15. Write an SQL query to determine the 5th highest salary without using TOP
-- or limit method.
SELECT
    W1.WORKER_ID AS 'Worker ID',
    W1.FIRST_NAME AS 'First Name',
    W1.LAST_NAME AS 'Last Name',
    W1.SALARY AS 'Salary',
    W1.JOINING_DATE AS 'Joining Date',
    W1.DEPARTMENT AS 'Department'
FROM Worker W1
WHERE 4 = (
    SELECT COUNT(DISTINCT W2.SALARY)
    FROM Worker W2
    WHERE W2.SALARY >= W1.SALARY
);

-- 16. Write an SQL query to fetch the list of employees with the same salary.
SELECT 
    W1.WORKER_ID AS 'Worker ID',
    W1.FIRST_NAME AS 'First Name',
    W1.LAST_NAME AS 'Last Name',
    W1.SALARY AS 'Salary',
    W1.JOINING_DATE AS 'Joining Date',
    W1.DEPARTMENT AS 'Department' 
FROM Worker W1, Worker W2
WHERE W1.WORKER_ID <> W2.WORKER_ID AND W1.SALARY = W2.SALARY;

-- 17. Write an SQL query to show the second highest salary from a table.
SELECT MAX(W1.SALARY) AS "2nd Highest Salary"
FROM Worker W1
WHERE W1.SALARY NOT IN (
    SELECT MAX(W2.SALARY)
    FROM W2.Worker
);

-- 18. Write an SQL query to fetch the first 50% records from a table.
DELIMITER &&
CREATE PROCEDURE selectfifty(IN fiftyperc INT)
BEGIN
    SELECT
        W.WORKER_ID AS 'Worker ID',
        W.FIRST_NAME AS 'First Name',
        W.LAST_NAME AS 'Last Name',
        W.SALARY AS 'Salary',
        W.JOINING_DATE AS 'Joining Date',
        W.DEPARTMENT AS 'Department'
    FROM Worker W
    LIMIT fiftyperc;
END &&
DELIMITER ;

SET @fifty = (
    SELECT COUNT(W.WORKER_ID) / 2 
    FROM Worker W
);

CALL selectfifty(@fifty);

-- 19. Write an SQL query to fetch the departments that have less than 55 people
-- in it.
SELECT W.DEPARTMENT AS "Department", COUNT(W.DEPARTMENT) AS "Number of Workers"
FROM Worker W
GROUP BY W.DEPARTMENT
HAVING COUNT(W.DEPARTMENT) < 55;

-- 20. Write an SQL query to print the name of employees having the highest
-- salary in each department.
SELECT W.DEPARTMENT AS "Department", MAX(W.SALARY) AS "Maximum Salary"
FROM Worker W
GROUP BY W.DEPARTMENT;