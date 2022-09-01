# CSE201 Lab Assignment
---
## Q1.
### Create the following tables:
```
Course
    course_no char(4)
    course_name varchar(20)
Course_fee
    course_no char(4)
    full_part char(1) (F/P)
    fees number(10)

    Note: course_no and full part should be unique.
Student
    prospectus_no number(10)
    name varchar(20)
    address varchar(30)
    phone_no number(11)
    DOB date
    total_amt number(10, 2)
    due_dt date
    paid char(1) (P/U)
Installment
    prospectus_no number(10) (foreign key) on delete cascade
    installment_amt number(10, 2)
    due_dt date
    paid char(1) (P/U)

    Note: prospectus_no and due_dt should be unique.

Course_taken
    prospectus_no number (foreign key)
    course_no char(4)
    start_dt date
    full_part char(1) (F/P)
    time_slot char(2)
    performance varchar(20)
```

```sql
-- Write Table creation and data entry syntax here
```

### Queries:
1. Retrieve name and course number of all students.
```sql
```
2. List the names of students who have paid the full amount at the time of admission.
```sql
```
3. Find the names of students starting with `A`.
```sql
```
4. Print the names of students whose total amount is not equal to amount due.
```sql
```
5. Count the number of students who have joined in the current year, current month.
```sql
```
6. Determine the maximum and minimum course fees.
```sql
```
7. Increase the fee of `oracle` by `50%`.
```sql
```
8. Print the details of courses whose fees are between `5000` and `10000`.
```sql
```
9. Display the admission date in `Date, Month, Year` format.
```sql
```
10. Find out in which course maximum number of students have taken admission.
```sql
```
11. Change the `course_name` from `Unix` to `Unix Operating System`.
```sql
```
12. Display the admission date in `DD-MONTH-YYYY` format.
```sql
```
13. Get the sum of amount to be collected from students in this month.
```sql
```
14. Find out in which course the maximum number of students have taken admission in the current month.
```sql
```
15. Select the students who have not yet paid full amount of fees.
```sql
```
---
## Q2.
### Create the following tables and answer the queries: (Take appropriate data types and relationships to define the columns and then insert relevant data).
```
SUPPLIER
    SNO
    SNAME
    STATUS
    CITY
PARTS
    PNO
    PNAME
    COLOR
    WEIGHT
    CITY
PROJECT
    JNO
    JNAME
    CITY
SPJ
    SNO
    PNO
    JNO
    QTY
```

```sql
-- Table Creation
CREATE TABLE SUPPLIER (
    SNO     INTEGER(5)      NOT NULL    UNIQUE  PRIMARY KEY,
    SNAME   VARCHAR(10)     NOT NULL    UNIQUE,
    STATUS  CHAR(11)
    CHECK (
        STATUS = "WORKING" OR STATUS = "NOT WORKING"
    ),
    CITY    VARCHAR(10)
);

CREATE TABLE PARTS (
    PNO     INTEGER(5)      NOT NULL    UNIQUE  PRIMARY KEY,
    PNAME   VARCHAR(10)     NOT NULL    UNIQUE,
    COLOR   VARCHAR(10)     NOT NULL,
    WEIGHT  INTEGER(5),
    CITY    VARCHAR(10)
);

CREATE TABLE PROJECT (
    JNO     INTEGER(5)      NOT NULL    UNIQUE  PRIMARY KEY,
    JNAME   VARCHAR(10)     NOT NULL    UNIQUE,
    CITY    VARCHAR(10)
);

CREATE TABLE SPJ (
    SNO INTEGER(5)  NOT NULL    UNIQUE,
    PNO INTEGER(5)  NOT NULL    UNIQUE,
    JNO INTEGER(5)  NOT NULL    UNIQUE,
    QTY INTEGER(5)  NOT NULL    UNIQUE,

    CONSTRAINT FOREIGN KEY(SNO) REFERENCES SUPPLIER(SNO),
    CONSTRAINT FOREIGN KEY(PNO) REFERENCES PARTS(PNO),
    CONSTRAINT FOREIGN KEY(JNO) REFERENCES PROJECT(JNO)
);

SHOW TABLES;
DESC SUPPLIER;
DESC PARTS;
DESC PROJECT;
DESC SPJ;

-- Data Entry

```

### Queries:
1. Get `SNO` values for suppliers who supply project `j1`.
```sql
```
2. Get `SNO` values for suppliers who supply project `j1` with part `p1`.
```sql
```
3. Get `JNAME` values for projects supplied by supplier `s1`.
```sql
```
4. Get `COLOR` values for parts supplied by suppler `s1`.
```sql
```
5. Get `PNO` values for parts supplied to any project in `London`.
```sql
```
6. Get `SNO` values for suppliers who supply project `j1` with a `Red` part.
```sql
```
7. Get `SNO` values for suppliers who supply a `London` or `Paris` project with a `Red` part.
```sql
```
8. Get `PNO` values for parts supplied to any project by a supplier in the same city.
```sql
```
9. Get `PNO` values for parts supplied to any project in `London` by a supplier in `London`.
```sql
```
10. Get `JNO` values for projects supplied by at least one supplier not in the same city.
```sql
```
11. Get all pairs of `CITY` values such that a supplier in the first city supplies a project in the second city.
```sql
```
12. Get `SNO` values for suppliers who supply the same part to all projects.
```sql
```
13. Get `PNO` values for parts supplied to all projects in `London`.
```sql
```
14. Get `SNAME` values for suppliers who supply at least one `Red` part to any project.
```sql
```
15. Get total quantity of part `p1` supplied by supplier `s1`.
```sql
```
16. Get the total number of projects supplied by supplier `s3`.
```sql
```
17. Change color of all `Red` parts to `Orange`.
```sql
```
18. Get `SNAME` values for suppliers who supply to both projects `j1` and `j2`.
```sql
```
19. Get all `CITY`, `PNO`, `CITY` triples such that a supplier in the first city supplies the specified part to a project in the second city.
```sql
```
20. Get `JNAMES` for those project which are supplied by supplier `XYZ`.
```sql
```
---
## Q3.
### Create the required tables
```
```

```sql
-- Write Table creation and data entry syntax here
```

### Queries:
1.	Display each employee name and hiredate of systems department.
```sql
```
2.	Write query to calculate length of service of each employee.
```sql
```
3.	Find the second maximum salary of all employees.
```sql
```
4.	Display all employee name and department name in department name order.
```sql
```
5.	Find the name of lowest paid employee for each manager.
```sql
```
6.	Display the department that has no employee.
```sql
```
7.	Find the employees who earn the maximum salary in each job type. Sort in descending order of salary.
```sql
```
8.	In which year did most people joined the company? Display the year and number of employees.
```sql
```
9.	Display the details of those employees who earn greater than average of their department.
```sql
```
10.	List the employees having salary between `10000` and `20000`.
```sql
```
11.	Display all employees hired during `1983`and those employees who earn greater than average of their department.
```sql
```
12.	Update the salaries of all employees in marketing department & hike it by `15%`.
```sql
```
13.	Get the gross salaries of all the employees.
```sql
```
14.	Get the names of employees and their managers name.
```sql
```
15.	Display the name, location and department name of all the employees earning more than `1500`.
```sql
```
16.	Show all the employees in `Dallas`.
```sql
```
17.	List the employees name, job, salary, grade, and department for employees in the company except clerks. Sort on employee names.
```sql
```
18.	Find the employees who earns the minimum salary for their job. Sort in descending order of salary.
```sql
```
19.	Find the most recently hired employees in the department order by hiredate.
```sql
```
20.	Find out the difference between highest and lowest salaries.
```sql
```
---
