<span style = "font-family: Nunito">

# CSE201 Lab Assignment
---
#### Name: Adersh Varshnei
#### Enrollment No: A2305220129
#### Section: 5CSE-2Y
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
    D_O_B date
    total_amt number(10, 2)
    amt_paid number(10, 2)
    installment char(1) (I/F)
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

##### Query:
```sql
```

##### Output:
```
```

### Queries:
#### 1. Retrieve name and course number of all students.

##### Query:
```sql
```

##### Output:
```
```

#### 2. List the names of students who have paid the full amount at the time of admission.

##### Query:
```sql
```

##### Output:
```
```

#### 3. Find the names of students starting with <span style = "font-family:Input">A</span>.

##### Query:
```sql
```

##### Output:
```
```

#### 4. Print the names of students whose total amount is not equal to amount due.

##### Query:
```sql
```

##### Output:
```
```

#### 5. Count the number of students who have joined in the current year, current month.

##### Query:
```sql
```

##### Output:
```
```

#### 6. Determine the maximum and minimum course fees.

##### Query:
```sql
```

##### Output:
```
```

#### 7. Increase the fee of <span style = "font-family:Input">oracle</span> by $50\%$.

##### Query:
```sql
```

##### Output:
```
```

#### 8. Print the details of courses whose fees are between $5000$ and $10000$.

##### Query:
```sql
```

##### Output:
```
```

#### 9. Display the admission date in <span style = "font-family:Input">Date, Month, Year</span> format.

##### Query:
```sql
```

##### Output:
```
```

#### 10. Find out in which course maximum number of students have taken admission.

##### Query:
```sql
```

##### Output:
```
```

#### 11. Change the <span style = "font-family:Input">course_name</span> from <span style = "font-family:Input">Unix</span> to <span style = "font-family:Input">Unix Operating System</span>.

##### Query:
```sql
```

##### Output:
```
```

#### 12. Display the admission date in <span style = "font-family:Input">DD-MONTH-YYYY</span> format.

##### Query:
```sql
```

##### Output:
```
```

#### 13. Get the sum of amount to be collected from students in this month.

##### Query:
```sql
```

##### Output:
```
```

#### 14. Find out in which course the maximum number of students have taken admission in the current month.

##### Query:
```sql
```

##### Output:
```
```

#### 15. Select the students who have not yet paid full amount of fees.

##### Query:
```sql
```

##### Output:
```
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

##### Query:
```sql
```

##### Output:
```
```

### Queries:
#### 1. Get <span style = "font-family:Input">SNO</span> values for suppliers who supply project <span style = "font-family:Input">j1</span>.

##### Query:
```sql
```

##### Output:
```
```

#### 2. Get <span style = "font-family:Input">SNO</span> values for suppliers who supply project <span style = "font-family:Input">j1</span> with part <span style = "font-family:Input">p1</span>.

##### Query:
```sql
```

##### Output:
```
```

#### 3. Get <span style = "font-family:Input">JNAME</span> values for projects supplied by supplier <span style = "font-family:Input">s1</span>.

##### Query:
```sql
```

##### Output:
```
```

#### 4. Get <span style = "font-family:Input">COLOR</span> values for parts supplied by supplier <span style = "font-family:Input">s1</span>.

##### Query:
```sql
```

##### Output:
```
```

#### 5. Get <span style = "font-family:Input">PNO</span> values for parts supplied to any project in <span style = "font-family:Input">London</span>.

##### Query:
```sql
```

##### Output:
```
```

#### 6. Get <span style = "font-family:Input">SNO</span> values for suppliers who supply project <span style = "font-family:Input">j1</span> with a <span style = "font-family:Input">Red</span> part.

##### Query:
```sql
```

##### Output:
```
```

#### 7. Get <span style = "font-family:Input">SNO</span> values for suppliers who supply a <span style = "font-family:Input">London</span> or <span style = "font-family:Input">Paris</span> project with a <span style = "font-family:Input">Red</span> part.

##### Query:
```sql
```

##### Output:
```
```

#### 8. Get <span style = "font-family:Input">PNO</span> values for parts supplied to any project by a supplier in the same city.

##### Query:
```sql
```

##### Output:
```
```

#### 9. Get <span style = "font-family:Input">PNO</span> values for parts supplied to any project in <span style = "font-family:Input">London</span> by a supplier in <span style = "font-family:Input">London</span>.

##### Query:
```sql
```

##### Output:
```
```

#### 10. Get <span style = "font-family:Input">JNO</span> values for projects supplied by at least one supplier not in the same city.

##### Query:
```sql
```

##### Output:
```
```

#### 11. Get all pairs of <span style = "font-family:Input">CITY</span> values such that a supplier in the first city supplies a project in the second city.

##### Query:
```sql
```

##### Output:
```
```

#### 12. Get <span style = "font-family:Input">SNO</span> values for suppliers who supply the same part to all projects.

##### Query:
```sql
```

##### Output:
```
```

#### 13. Get <span style = "font-family:Input">PNO</span> values for parts supplied to all projects in <span style = "font-family:Input">London</span>.

##### Query:
```sql
```

##### Output:
```
```

#### 14. Get <span style = "font-family:Input">SNAME</span> values for suppliers who supply at least one <span style = "font-family:Input">Red</span> part to any project.

##### Query:
```sql
```

##### Output:
```
```

#### 15. Get total quantity of part <span style = "font-family:Input">p1</span> supplied by supplier <span style = "font-family:Input">s1</span>.

##### Query:
```sql
```

##### Output:
```
```

#### 16. Get the total number of projects supplied by supplier <span style = "font-family:Input">s3</span>.

##### Query:
```sql
```

##### Output:
```
```

#### 17. Change color of all <span style = "font-family:Input">Red</span> parts to <span style = "font-family:Input">Orange</span>.

##### Query:
```sql
```

##### Output:
```
```

#### 18. Get <span style = "font-family:Input">SNAME</span> values for suppliers who supply to both projects <span style = "font-family:Input">j1</span> and <span style = "font-family:Input">j2</span>.

##### Query:
```sql
```

##### Output:
```
```

#### 19. Get all <span style = "font-family:Input">CITY</span>, <span style = "font-family:Input">PNO</span>, <span style = "font-family:Input">CITY</span> triples such that a supplier in the first city supplies the specified part to a project in the second city.

##### Query:
```sql
```

##### Output:
```
```

#### 20. Get <span style = "font-family:Input">JNAMES</span> for those project which are supplied by supplier <span style = "font-family:Input">XYZ</span>.

##### Query:
```sql
```

##### Output:
```
```

---
## Q3.
### Create the required tables
```
```

##### Query:
```sql
```

##### Output:
```
```

### Queries:
#### 1. Display each employee name and hiredate of systems department.

##### Query:
```sql
```

##### Output:
```
```

#### 2. Write query to calculate length of service of each employee.

##### Query:
```sql
```

##### Output:
```
```

#### 3. Find the second maximum salary of all employees.

##### Query:
```sql
```

##### Output:
```
```

#### 4. Display all employee name and department name in department name order.

##### Query:
```sql
```

##### Output:
```
```

#### 5. Find the name of lowest paid employee for each manager.

##### Query:
```sql
```

##### Output:
```
```

#### 6. Display the department that has no employee.

##### Query:
```sql
```

##### Output:
```
```

#### 7. Find the employees who earn the maximum salary in each job type. Sort in descending order of salary.

##### Query:
```sql
```

##### Output:
```
```

#### 8. In which year did most people joined the company? Display the year and number of employees.

##### Query:
```sql
```

##### Output:
```
```

#### 9. Display the details of those employees who earn greater than average of their department.

##### Query:
```sql
```

##### Output:
```
```

#### 10. List the employees having salary between $10000$ and $20000$.

##### Query:
```sql
```

##### Output:
```
```

#### 11. Display all employees hired during $1983$ and those employees who earn greater than average of their department.

##### Query:
```sql
```

##### Output:
```
```

#### 12. Update the salaries of all employees in marketing department & hike it by $15\%$.

##### Query:
```sql
```

##### Output:
```
```

#### 13. Get the gross salaries of all the employees.

##### Query:
```sql
```

##### Output:
```
```

#### 14. Get the names of employees and their managers name.

##### Query:
```sql
```

##### Output:
```
```

#### 15. Display the name, location and department name of all the employees earning more than $1500$.

##### Query:
```sql
```

##### Output:
```
```

#### 16. Show all the employees in <span style = "font-family:Input">Dallas</span>.

##### Query:
```sql
```

##### Output:
```
```

#### 17. List the employees name, job, salary, grade, and department for employees in the company except clerks. Sort on employee names.

##### Query:
```sql
```

##### Output:
```
```

#### 18. Find the employees who earns the minimum salary for their job. Sort in descending order of salary.

##### Query:
```sql
```

##### Output:
```
```

#### 19. Find the most recently hired employees in the department order by hiredate.

##### Query:
```sql
```

##### Output:
```
```

#### 20. Find out the difference between highest and lowest salaries.

##### Query:
```sql
```

##### Output:
```
```

---
</span>
