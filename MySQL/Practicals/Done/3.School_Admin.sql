CREATE DATABASE p3;
USE p3;

#--------------------------------------------------------------------------------------------------------------------------

CREATE TABLE SCHOOL
	(CODE		INTEGER		NOT NULL,
	TEACHERNAME	VARCHAR(20),
	SUBJECT		VARCHAR(10),
	DOJ			DATE			NOT NULL,
	PERIODS		INTEGER		NOT NULL,
	EXPERIENCE	INTEGER		NOT NULL);

INSERT INTO SCHOOL VALUES
	(1001, "RAVI SHANKAR", "ENGLISH", "2000-03-12", 24, 10);
INSERT INTO SCHOOL VALUES
	(1009, "PRIYA RAI", "PHYSICS", "1998-09-03", 26, 12);
INSERT INTO SCHOOL VALUES
	(1203, "LISA ANAND", "ENGLISH", "2000-04-09", 27, 5);
INSERT INTO SCHOOL VALUES
	(1045, "YASHRAJ", "MATHS", "2000-08-24", 24, 15);
INSERT INTO SCHOOL VALUES
	(1123, "GANAN", "PHYSICS", "1999-07-16", 28, 3);
INSERT INTO SCHOOL VALUES
	(1167, "HARISH B", "CHEMISTY", "1999-10-19", 27, 5);
INSERT INTO SCHOOL VALUES
	(1215, "UMESH", "PHYSICS", "1998-05-11", 22, 16);

#--------------------------------------------------------------------------------------------------------------------------

CREATE TABLE ADMIN
	(CODE		INTEGER		NOT NULL,
	GENDER		VARCHAR(10),
	DESIGNATION	VARCHAR(20));

INSERT INTO ADMIN VALUES
	(1001, "MALE", "VICE PRINCIPAL");
INSERT INTO ADMIN VALUES
	(1009, "FEMALE", "COORDINATOR");
INSERT INTO ADMIN VALUES
	(1203, "FEMALE", "COORDINATOR");
INSERT INTO ADMIN VALUES
	(1045, "MALE", "HOD");
INSERT INTO ADMIN VALUES
	(1123, "MALE", "SENIOR TEACHER");
INSERT INTO ADMIN VALUES
	(1167, "MALE", "SENIOR TEACHER");
INSERT INTO ADMIN VALUES
	(1215, "MALE", "HOD");

#--------------------------------------------------------------------------------------------------------------------------

# (i)
SELECT 
	TEACHERNAME, PERIODS
FROM 
	SCHOOL
WHERE 
	PERIODS < 25;

#--------------------------------------------------------------------------------------------------------------------------

# (ii)
SELECT
	SCHOOL.TEACHERNAME, SCHOOL.PERIODS,
	ADMIN.DESIGNATION
FROM 
	SCHOOL, ADMIN
WHERE 
	SCHOOL.CODE = ADMIN.CODE;

#--------------------------------------------------------------------------------------------------------------------------

# (iii)
SELECT 
	TEACHERNAME, MIN(PERIODS)
FROM 
	SCHOOL
WHERE
	PERIODS = (SELECT
				MIN(PERIODS)
			FROM
				SCHOOL);

#--------------------------------------------------------------------------------------------------------------------------

# (iv)
SELECT 
	CODE, TEACHERNAME, SUBJECT
FROM 
	SCHOOL
WHERE 
	DOJ > "1999-01-01";

#--------------------------------------------------------------------------------------------------------------------------

# (v)
SELECT 
	MAX(EXPERIENCE), SUBJECT
FROM 
	SCHOOL
GROUP BY 
	SUBJECT;

#--------------------------------------------------------------------------------------------------------------------------

# (vi)
SELECT
	SCHOOL.TEACHERNAME,
	ADMIN.GENDER
FROM 
	SCHOOL, ADMIN
WHERE 
	ADMIN.DESIGNATION = "COORDINATOR"
	AND
	SCHOOL.CODE = ADMIN.CODE;

#--------------------------------------------------------------------------------------------------------------------------

# (vii)
SELECT
	COUNT(DESIGNATION), DESIGNATION
FROM
	ADMIN
GROUP BY
	DESIGNATION
HAVING
	COUNT(DESIGNATION) > 3;
