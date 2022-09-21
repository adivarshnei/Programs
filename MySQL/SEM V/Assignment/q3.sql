-- Initialization
/! cls

DROP DATABASE q3_0129;
CREATE DATABASE q3_0129;
USE q3_0129;

-- Table Creation
CREATE TABLE Department_0129 (
    DEPT_NO INTEGER(2) NOT NULL UNIQUE PRIMARY KEY,
    DEPT_NAME VARCHAR(10) UNIQUE
);

CREATE TABLE Employee_0129 (
    E_ID INTEGER(4) NOT NULL UNIQUE PRIMARY KEY,
    ENAME VARCHAR(20),
    SALARY INTEGER(12),
    HIREDATE DATE,
    LOC VARCHAR(20),
    MGR_E_ID NUMBER(4),
    JOB VARCHAR(10),
    GRADE CHAR(10),
    DEPT_NO INTEGER(2),

    CONSTRAINT
        FOREIGN KEY DEPT_NO
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
	(47, "Backend");



-- Queries
-- 1. Display each employee and hiredate of systems department


-- 2. Write query to calculate length of service of each employee


-- 3. Find the second maximum salary of all employees


-- 4. Display all employee name and department name in department name order


-- 5. Find the name of lowest paid employee for each manager


-- 6. Display the department that has no employee


-- 7. Find the employees who earn the maximum salary in each job type. Sort in
-- descending order of salary


-- 8. In which year did most people joined the company? Display the year and
-- number of employees


-- 9. Display the details of those employees who earn greater than average of
-- their department


-- 10. List the employees having salary between 10000 and 20000


-- 11. Display all employees hired during 1983 and those employees who earn
-- greater than average of their department


-- 12. Update the salaries of all employees in marketing department and hike it
-- by 15%


-- 13. Get the gross salaries of all the employees


-- 14. Get the names of employees and their managers name


-- 15. Display the name, location and department name of all the employees
-- earning more than 15000


-- 16. Show all the employees in Dallas


-- 17. List the employees name, job, salary, grade, and department for employees
-- in the company except clerks. Sort on employee names


-- 18. Find the employees who earns the minimum salary for their job. Sort in
-- descending order of salary


-- 19. Find the most recently hired employees in the department order by
-- hiredate


-- 20. Find out the difference between highest and lowest salaries.
