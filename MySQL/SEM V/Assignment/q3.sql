-- Initialization
/! cls

DROP DATABASE q3;
CREATE DATABASE q3;
USE q3;

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
    
    CONSTRAINT FOREIGN KEY DEPT_NO REFERENCES Department_0129(DEPT_NO)
);
