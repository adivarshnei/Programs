-- Initialization
\! cls

DROP DATABASE q3_0129;
CREATE DATABASE q3_0129;
USE q3_0129;

-- Table Creation
CREATE TABLE Department_0129 (
    DEPT_NO     INTEGER(2)  NOT NULL    UNIQUE  PRIMARY KEY,
    DEPT_NAME   VARCHAR(10) UNIQUE
);

CREATE TABLE Employee_0129 (
    E_ID        INTEGER(4)  NOT NULL    UNIQUE  PRIMARY KEY,
    ENAME       VARCHAR(20),
    SALARY      INTEGER(12),
    HIREDATE    DATE,
    LOC         VARCHAR(20),
    MGR_E_ID    INTEGER(4),
    JOB         VARCHAR(10),
    GRADE       CHAR(10),
    DEPT_NO     INTEGER(2),

    CONSTRAINT
        FOREIGN KEY(DEPT_NO)
        REFERENCES Department_0129(DEPT_NO)
        ON DELETE CASCADE
);

-- Data Entry
INSERT INTO Department_0129 (DEPT_NO, DEPT_NAME) VALUES
    (14, "Systems"),
    (93, "Marketing"),
    (89, "HR"),
    (18, "Research"),
    (37, "Frontend"),
    (47, "Backend"),
    (78, "Maint.");

INSERT INTO Employee_0129 (
    E_ID,
    ENAME,
    SALARY,
    HIREDATE,
    LOC,
    MGR_E_ID,
    JOB,
    GRADE,
    DEPT_NO
) VALUES
    (8908, "Oscar Reid", 12000, "1984-12-01", "New York", 8908, "Manager", "B", 37),
    (6267, "Dean Allen", 25000, "1984-12-11", "Boston", 6267, "Manager", "B", 93),
    (5669, "Sonja Bush", 18000, "1982-06-12", "Seattle", 5669, "Manager", "B", 18),
    (9488, "Christina Harmon", 12000, "1981-03-30", "Dallas", 8908, "Jr. Emp.", "A", 37),
    (1318, "Terry Fleming", 15000, "1981-09-08", "Dallas", 8908, "Officer", "B", 37),
    (6514, "Isabel Taylor", 16000, "1983-07-07", "New York", 5669, "Jr. Emp.", "B", 18),
    (8038, "Tom Morris", 12000, "1981-04-27", "San Francisco", 6267, "Officer", "B", 93),
    (7248, "Marta Pierce", 20000, "1981-05-02", "Seattle", 7248, "Manager", "B", 47),
    (1236, "Amber Howard", 22000, "1982-01-19", "San Francisco", 7248, "Officer", "B", 47),
    (6485, "Harvey Klein", 19000, "1981-05-29", "Dallas", 5669, "Officer", "B", 18),
    (2006, "Alexander Barnes", 18000, "1984-10-14", "Boston", 7248, "Officer", "B", 47),
    (8584, "Vernon Bennett", 12000, "1983-11-30", "Dallas", 6267, "Clerk", "A", 93),
    (6199, "Beth Jordan", 11000, "1982-12-17", "Boston", 5669, "Jr. Emp.", "C", 18),
    (6543, "Ramon Russell", 16000, "1984-09-13", "Dallas", 5669, "Officer", "C", 18),
    (3634, "Chad Bowen", 17000, "1984-11-20", "New Orleans", 8908, "Officer", "A", 37),
    (5306, "Boyd Watkins", 6000, "1983-11-01", "Dallas", 6267, "Officer", "C", 93),
    (8468, "Pat Gardner", 10000, "1982-08-21", "Boston", 5669, "Jr. Emp.", "B", 18),
    (4255, "Wayne Myers", 24000, "1983-03-06", "New Orleans", 6267, "Clerk", "A", 93),
    (6505, "Donnie Robertson", 23000, "1984-04-05", "San Francisco", 5050, "Jr. Emp.", "B", 89),
    (9626, "Clarence Hamilton", 9000, "1982-07-19", "Seattle", 8908, "Officer", "A", 37),
    (5952, "Kristopher Douglas", 11000, "1981-03-31", "San Francisco", 6267, "Jr. Emp.", "B", 93),
    (4208, "Caroline Evans", 13000, "1984-02-16", "Boston", 5669, "Clerk", "A", 18),
    (1336, "Stephen Lane", 7000, "1983-01-15", "San Francisco", 8908, "Jr. Emp.", "C", 37),
    (6982, "Ellis Brady", 14000, "1981-06-22", "San Francisco", 6267, "Officer", "B", 93),
    (5582, "Victor Boyd", 8000, "1982-06-06", "Boston", 8908, "Jr. Emp.", "A", 37),
    (3733, "Bertha Pearson", 7000, "1981-11-20", "Seattle", 3151, "Jr. Emp.", "A", 14),
    (7827, "Jill Powers", 16000, "1981-04-25", "New Orleans", 3151, "Jr. Emp.", "C", 14),
    (1990, "Sophia Spencer", 21000, "1982-01-14", "Boston", 5050, "Clerk", "B", 89),
    (3074, "Jose Santos", 16000, "1984-12-20", "Dallas", 6267, "Officer", "C", 93),
    (5142, "Gloria Peterson", 8000, "1983-04-03", "Boston", 6267, "Clerk", "C", 93),
    (8593, "Bruce Mitchell", 14000, "1981-09-09", "Seattle", 7248, "Jr. Emp.", "C", 47),
    (5344, "Lee Robbins", 19000, "1982-05-10", "Boston", 6267, "Officer", "B", 93),
    (1242, "Yvette Mcbride", 21000, "1982-03-22", "New York", 3151, "Officer", "A", 14),
    (9845, "Cecilia Hammond", 20000, "1982-12-26", "Seattle", 5669, "Jr. Emp.", "A", 18),
    (6028, "Lyle Daniel", 21000, "1982-01-18", "New York", 6267, "Clerk", "A", 93),
    (7424, "Adrian Long", 8000, "1982-05-30", "Seattle", 7248, "Officer", "C", 47),
    (2846, "Eddie Greer", 8000, "1981-02-27", "New York", 5669, "Clerk", "C", 18),
    (3151, "Roger Mccormick", 22000, "1983-01-23", "Seattle", 3151, "Manager", "C", 14),
    (5050, "Emanuel Barker", 10000, "1982-04-06", "San Francisco", 5050, "Manager", "B", 89),
    (4269, "Henry Barber", 19000, "1983-03-18", "San Francisco", 7248, "Jr. Emp.", "B", 47),
    (7962, "Carolyn Graves", 16000, "1981-11-08", "Dallas", 7248, "Officer", "B", 47),
    (7754, "Marian Lucas", 20000, "1981-09-29", "Seattle", 5050, "Jr. Emp.", "B", 89),
    (9546, "Wilma Wilkins", 14000, "1982-04-15", "New Orleans", 6267, "Jr. Emp.", "B", 93),
    (7061, "Bryant Stevens", 13000, "1984-04-06", "Seattle", 3151, "Clerk", "B", 14),
    (5891, "Angelina Maxwell", 9000, "1982-05-22", "Dallas", 5669, "Officer", "A", 18),
    (5056, "Darin Alexander", 10000, "1983-03-24", "San Francisco", 5050, "Manager", "B", 89),
    (1022, "Carlos Wise", 11000, "1983-04-20", "New York", 8908, "Jr. Emp.", "C", 37),
    (4704, "Traci Jones", 20000, "1984-07-05", "Dallas", 8908, "Officer", "C", 37),
    (4528, "Whitney Collier", 12000, "1981-11-17", "New Orleans", 6267, "Officer", "C", 93),
    (7655, "Beverly Holt", 22000, "1982-07-04", "Dallas", 5669, "Officer", "A", 18);

-- Queries
-- 1. Display each employee and hire date of systems department
SELECT
    E.ENAME AS "Employee Name",
    E.HIREDATE AS "Hiring Date",
    D.DEPT_NAME AS "Department Name"
FROM Employee_0129 E, Department_0129 D
WHERE E.DEPT_NO = D.DEPT_NO AND D.DEPT_NAME = "Systems";

-- 2. Write query to calculate length of service of each employee
SELECT
    E.ENAME AS "Employee Name",
    E.HIREDATE AS "Hire Date",
    CONCAT(
        YEAR(FROM_DAYS(DATEDIFF(DATE(NOW()), E.HIREDATE))),
        " Years, ",
        MONTH(FROM_DAYS(DATEDIFF(DATE(NOW()), E.HIREDATE))),
        " Months, ",
        DAY(FROM_DAYS(DATEDIFF(DATE(NOW()), E.HIREDATE))),
        " Days"
    ) AS "Length of Service"
FROM Employee_0129 E;

-- 3. Find the second maximum salary of all employees
SELECT E2.ENAME AS "Employee Name", MAX(E2.SALARY) AS "Second Highest Salary"
FROM Employee_0129 E2
WHERE
    E2.SALARY NOT IN (
    SELECT MAX(E1.SALARY)
    FROM Employee_0129 E1
);

-- 4. Display all employee names and department names in department name order
SELECT E.ENAME AS "Employee Name", D.DEPT_NAME AS "Department Name"
FROM Employee_0129 E, Department_0129 D
WHERE E.DEPT_NO = D.DEPT_NO
ORDER BY D.DEPT_NAME;

-- 5. Find the name of lowest paid employee for each manager
SELECT
    E.ENAME AS "Employee Name",
    MIN(E.SALARY) AS "Minimum Salary",
    E.MGR_E_ID AS "Manager Name"
FROM Employee_0129 E
GROUP BY E.MGR_E_ID;

-- 6. Display the department that has no employee
SELECT D.DEPT_NO AS "Department Number", D.DEPT_NAME AS "Department Name"
FROM Department_0129 D
WHERE
    D.DEPT_NO NOT IN (
        SELECT E.DEPT_NO
        FROM Employee_0129 E
    );

-- 7. Find the employees who earn the maximum salary in each job type. Sort in
-- descending order of salary
SELECT
    MAXSAL.ENAME AS "Employee Name",
    MAXSAL.MAXSALARIES AS "Maximum Salary",
    MAXSAL.JOB AS "Job Type"
FROM (
    SELECT E.ENAME, MAX(E.SALARY) AS MAXSALARIES, E.JOB
    FROM Employee_0129 E
    GROUP BY E.JOB
) MAXSAL
ORDER BY MAXSAL.MAXSALARIES DESC;

-- 8. In which year did most people joined the company? Display the year and
-- number of employees
SELECT
    COUNT(E1.E_ID) AS "Maximum Number of Employees",
    YEAR(E1.HIREDATE) AS "Year"
FROM Employee_0129 E1
GROUP BY YEAR(E1.HIREDATE)
HAVING
    COUNT(E1.E_ID) IN (
        SELECT MAX(YEAR_COUNTS)
        FROM (
            SELECT COUNT(E2.E_ID) AS YEAR_COUNTS
            FROM Employee_0129 E2
            GROUP BY YEAR(E2.HIREDATE)
        ) COUNTS
    );

-- 9. Display the details of those employees who earn greater than average of
-- their department
SELECT
    E1.E_ID AS "Employee ID", 
    E1.ENAME AS "Employee Name",
    E1.SALARY AS "Salary",
    D.DEPT_NAME AS "Department",
    E1.JOB AS "Job"
FROM Employee_0129 E1, Department_0129 D
WHERE
    D.DEPT_NO = E1.DEPT_NO
    AND SALARY > (
        SELECT AVG(E2.SALARY)
        FROM Employee_0129 E2
        WHERE E1.DEPT_NO = E2.DEPT_NO
    );

-- 10. List the employees having salary between 10000 and 20000
SELECT
    E.E_ID AS "Employee ID", 
    E.ENAME AS "Employee Name",
    E.SALARY AS "Salary",
    E.JOB AS "Job"
FROM Employee_0129 E
WHERE E.SALARY BETWEEN 10000 AND 20000;

-- 11. Display all employees hired during 1983 and those employees who earn
-- greater than average of their department
SELECT
    E1.E_ID AS "Employee ID", 
    E1.ENAME AS "Employee Name",
    E1.SALARY AS "Salary",
    D.DEPT_NAME AS "Department",
    E1.JOB AS "Job"
FROM Employee_0129 E1, Department_0129 D
WHERE
    E1.DEPT_NO = D.DEPT_NO
    AND YEAR(E1.HIREDATE) = 1983
    AND E1.SALARY > (
        SELECT AVG(E2.SALARY)
        FROM Employee_0129 E2
        WHERE E1.DEPT_NO = E2.DEPT_NO
    );

-- 12. Update the salaries of all employees in marketing department and hike it
-- by 15%
SELECT E.ENAME AS "Employee Name", E.SALARY AS "Salary"
FROM Employee_0129 E, Department_0129 D
WHERE E.DEPT_NO = D.DEPT_NO AND D.DEPT_NAME = "Marketing";

UPDATE Employee_0129 E
SET E.SALARY = E.SALARY * 1.15
WHERE
    E.DEPT_NO = (
        SELECT D.DEPT_NO
        FROM Department_0129 D
        WHERE D.DEPT_NAME = "Marketing"
    );

SELECT E.ENAME AS "Employee Name", E.SALARY AS "Salary"
FROM Employee_0129 E, Department_0129 D
WHERE E.DEPT_NO = D.DEPT_NO AND D.DEPT_NAME = "Marketing";

-- 13. Get the gross salaries of all the employees
SELECT E.ENAME AS "Employee Name", E.SALARY AS "Salary"
FROM Employee_0129 E;

-- 14. Get the names of employees and their managers name
SELECT E.ENAME AS "Employee Name", M.ENAME AS "Manager Name"
FROM Employee_0129 E, Employee_0129 M
WHERE E.MGR_E_ID = M.E_ID;

-- 15. Display the name, location and department name of all the employees
-- earning more than 15000
SELECT
    E.ENAME AS "Employee Name",
    E.LOC AS "Location",
    D.DEPT_NAME AS "Department"
FROM Employee_0129 E, Department_0129 D
WHERE E.SALARY > 15000 AND E.DEPT_NO = D.DEPT_NO;

-- 16. Show all the employees in Dallas
SELECT
    E.E_ID AS "Employee ID",
    E.ENAME AS "Employee Name",
    E.SALARY AS "Salary",
    E.JOB AS "Job",
    E.LOC AS "Location"
FROM Employee_0129 E
WHERE E.LOC = "Dallas";

-- 17. List the employees name, job, salary, grade, and department for employees
-- in the company except clerks. Sort on employee names
SELECT
    E.ENAME AS "Employee Name",
    E.JOB AS "Job",
    E.SALARY AS "Salary",
    E.GRADE AS "Grade",
    D.DEPT_NAME AS "Department"
FROM Employee_0129 E, Department_0129 D
WHERE E.DEPT_NO = D.DEPT_NO AND E.JOB NOT LIKE ("Clerk")
ORDER BY E.ENAME;

-- 18. Find the employees who earns the minimum salary for their job. Sort in
-- descending order of salary
SELECT
    MINSAL.ENAME AS "Employee Name",
    MINSAL.MINSALARIES AS "Minimum Salary",
    MINSAL.JOB AS "Job"
FROM (
    SELECT E.ENAME, MIN(E.SALARY) AS MINSALARIES, E.JOB
    FROM Employee_0129 E
    GROUP BY E.JOB
) MINSAL
ORDER BY MINSAL.MINSALARIES DESC;

-- 19. Find the most recently hired employees in the department order by
-- hiredate
SELECT
    E1.ENAME AS "Employee Name",
    E1.HIREDATE AS "Hiring Date",
    D.DEPT_NAME AS "Department"
FROM Employee_0129 E1, Department_0129 D
WHERE
    E1.DEPT_NO = D.DEPT_NO
    AND E1.HIREDATE IN (
        SELECT MAX(E2.HIREDATE)
        FROM Employee_0129 E2
        GROUP BY E2.DEPT_NO
    )
ORDER BY E1.HIREDATE;

-- 20. Find out the difference between highest and lowest salaries.
SELECT
    MAX(E.SALARY) AS "Maximum Salary",
    "-",
    MIN(E.SALARY) AS "Minimum Salary",
    "=",
    MAX(E.SALARY) - MIN(E.SALARY) AS "Difference"
FROM Employee_0129 E;
