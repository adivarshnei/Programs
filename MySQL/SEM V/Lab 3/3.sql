\! cls
DROP DATABASE p3;

CREATE DATABASE p3;

USE p3;

CREATE TABLE student(
	ADM_NO		INTEGER		NOT NULL	UNIQUE	PRIMARY KEY,
	NAME		VARCHAR(20)	NOT NULL,
	MARKS		FLOAT(5,2)	CHECK (MARKS <= 100 AND MARKS >= 0),
	FEE_STATUS  CHAR(8)
);

DESC student;

INSERT INTO student(ADM_NO, NAME, MARKS, FEE_STATUS) VALUES
	(3988, "TOR", 3.69, "PAID"),
	(6937, "KVI", 68.44, "NOT PAID"),
	(5713, "XJH", 48.53, "NOT PAID"),
	(1209, "WHE", 48.08, "PAID"),
	(3244, "VTV", 79.82, "PAID"),
	(2112, "QFJ", 35.43, "PAID"),
	(5755, "RTL", 51.97, "PAID"),
	(7531, "FTQ", 42.90, "PAID"),
	(5579, "DPO", 48.83, "PAID"),
	(8200, "UBH", 52.25, "NOT PAID");

-- Projection (Using WHERE Clause)
SELECT ADM_NO, MARKS
FROM student
WHERE FEE_STATUS = "PAID";

-- Elimination of Duplicate Rows (Using DISTINCT clause)
SELECT DISTINCT FEE_STATUS
FROM student;

-- Aliases in SQL
SELECT
	ADM_NO AS "Admission Number",
	NAME AS "Name",
	MARKS AS "Marks Gained",
	FEE_STATUS AS "Fee Status"
FROM student;

-- Text in Query Output
SELECT NAME AS "Name", "Scored", MARKS AS "Marks"
FROM student;

-- Aggregate Functions
SELECT
	SUM(MARKS) AS "Total Marks",
	AVG(MARKS) AS "Average Marks",
	MAX(MARKS) AS "Maximum Marks",
	MIN(MARKS) AS "Minimum Marks",
	COUNT(*) AS "Total Rows",
	COUNT(DISTINCT FEE_STATUS) AS "Fee Status Count"
FROM student;

-- Ordering in SQL
SELECT *
FROM student
ORDER BY MARKS ASC;

SELECT *
FROM student
ORDER BY MARKS DESC;

-- Range in SQL (BETWEEN...AND, NOT BETWEEN...AND)
SELECT *
FROM student
WHERE marks BETWEEN 30.0 AND 60.0;

SELECT *
FROM student
WHERE marks NOT BETWEEN 30.0 AND 60.0;

-- List Based Searching (IN, NOT IN)
SELECT *
FROM student
WHERE NAME IN ("TOR", "KVI", "VTV");

SELECT *
FROM student
WHERE NAME NOT IN ("TOR", "KVI", "VTV");

-- Pattern Matching (LIKE)
SELECT *
FROM student
WHERE MARKS LIKE "48%";