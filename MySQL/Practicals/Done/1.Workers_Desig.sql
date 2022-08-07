CREATE DATABASE p1;
USE p1;

#--------------------------------------------------------------------------------------------------------------------------

CREATE TABLE DESIG
	(W_ID		INTEGER		NOT NULL,
	SALARY		INTEGER		NOT NULL,
	BENEFITS		INTEGER		NOT NULL,
	DESIGNATION	VARCHAR(10));

INSERT INTO DESIG VALUES
	(102, 75000, 15000, "Manager");
INSERT INTO DESIG VALUES
	(105, 85000, 25000, "Director");
INSERT INTO DESIG VALUES
	(144, 70000, 15000, "Manager");
INSERT INTO DESIG VALUES
	(210, 75000, 12500, "Manager");
INSERT INTO DESIG VALUES
	(255, 50000, 12000, "Clerk");
INSERT INTO DESIG VALUES
	(300, 45000, 10000, "Clerk");
INSERT INTO DESIG VALUES
	(335, 40000, 10000, "Clerk");
INSERT INTO DESIG VALUES
	(400, 32000, 7500, "Salesman");
INSERT INTO DESIG VALUES
	(451, 28000, 7500, "Salesman");

#--------------------------------------------------------------------------------------------------------------------------

CREATE TABLE WORKERS
	(W_ID	INTEGER		NOT NULL,
	FIRSTNAME	VARCHAR(10),
	LASTNAME	VARCHAR(10),
	ADDRESS 	VARCHAR(20),
	CITY		VARCHAR(20));

INSERT INTO WORKERS VALUES
	(102, "Sam", "Tones", "33 Elm St.", "Paris");
INSERT INTO WORKERS VALUES
	(105, "Sarah", "Ackerman", "440 U.S. 110", "New York");
INSERT INTO WORKERS VALUES
	(144, "Manila", "Sengupta", "24 Friends Street", "New Delhi");
INSERT INTO WORKERS VALUES
	(210, "George", "Smith", "83 First Street", "Howard");
INSERT INTO WORKERS VALUES
	(255, "Mary", "Jones", "842 Vine Ave.", "Losantiville");
INSERT INTO WORKERS VALUES
	(300, "Robert", "Samuel", "9 Fifth Cross", "Wasington");
INSERT INTO WORKERS VALUES
	(335, "Henry", "Williams", "12Moore St.", "Boston");
INSERT INTO WORKERS VALUES
	(400, "Ronny", "Lee", "121 Harrison St.", "New York");
INSERT INTO WORKERS VALUES
	(451, "Pat", "Thompson", "11 Red Road", "Paris");

#--------------------------------------------------------------------------------------------------------------------------

# (i)
SELECT 
	W_ID, FIRSTNAME, ADDRESS, CITY 
FROM 
	WORKERS 
WHERE 
	CITY="New York";

#--------------------------------------------------------------------------------------------------------------------------

# (ii)
SELECT 
	*
FROM 
	WORKERS
ORDER BY 
	LASTNAME ASC;

#--------------------------------------------------------------------------------------------------------------------------

# (iii)
SELECT 
	WORKERS.FIRSTNAME, WORKERS.LASTNAME, 
	DESIG.SALARY + DESIG.BENEFITS AS "SALARY + BENEFITS"
FROM 
	WORKERS, DESIG
WHERE 
	WORKERS.W_ID = DESIG.W_ID;

#--------------------------------------------------------------------------------------------------------------------------

# (iv)
SELECT 
	MIN(SALARY) AS "Min Salary", DESIGNATION
FROM 
	DESIG
WHERE 
	DESIGNATION IN ("Manager", "Clerk");

#--------------------------------------------------------------------------------------------------------------------------

# (v)
SELECT 
	SUM(SALARY), DESIGNATION
FROM 
	DESIG
GROUP BY 
	DESIGNATION
HAVING
	COUNT(DESIGNATION) > 3;

#--------------------------------------------------------------------------------------------------------------------------

# (vi)
SELECT 
	WORKERS.FIRSTNAME,
	DESIG.SALARY
FROM 
	WORKERS, DESIG
WHERE 
	WORKERS.W_ID = DESIG.W_ID 
	AND 
	DESIG.DESIGNATION = "Manager";
