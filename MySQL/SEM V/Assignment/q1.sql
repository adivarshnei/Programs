-- Initializaiton
\! cls
DROP DATABASE q1_0129;

CREATE DATABASE q1_0129;

USE q1_0129;

-- Table Creation
CREATE TABLE Course_0129(
    COURSE_NO   CHAR(4)     NOT NULL    UNIQUE  PRIMARY KEY,
    COURSE_NAME VARCHAR(30)
);

CREATE TABLE Course_Fee_0129(
    COURSE_NO   CHAR(4) NOT NULL    UNIQUE,
    FULL_PART   CHAR(1) NOT NULL
    CHECK (
        FULL_PART = "F"
        OR FULL_PART = "P"
    ),
    FEES        INTEGER(10),

    CONSTRAINT FOREIGN KEY(COURSE_NO) REFERENCES Course_0129(COURSE_NO)
);

CREATE TABLE Student_0129 (
    PROSPECTUS_NO   INTEGER(10)     NOT NULL    UNIQUE  PRIMARY KEY,
    NAME            VARCHAR(20)     NOT NULL,
    ADDRESS         VARCHAR(30),
    PHONE_NO        DECIMAL(11, 0)  UNIQUE,
    D_O_B           DATE            NOT NULL,
    TOTAL_AMT       DECIMAL(10, 2)  NOT NULL,
    AMT_PAID        DECIMAL(10, 2)  NOT NULL,
    INSTALLMENT     CHAR(1)         NOT NULL
    CHECK (
        INSTALLMENT = "I"
        OR INSTALLMENT = "F"
    ),

    CONSTRAINT CHECK (AMT_PAID <= TOTAL_AMT)
);

CREATE TABLE Installment_0129 (
    PROSPECTUS_NO   INTEGER(10)     NOT NULL    UNIQUE,
    INSTALLMENT_AMT DECIMAL(10, 2)  NOT NULL,
    DUE_DT          DATE            NOT NULL,
    PAID            CHAR(1)         NOT NULL    CHECK(PAID = "P" OR PAID = "U"),

    CONSTRAINT
        FOREIGN KEY(PROSPECTUS_NO)
        REFERENCES Student_0129(PROSPECTUS_NO)
        ON DELETE CASCADE
);

CREATE TABLE Course_Taken_0129 (
    PROSPECTUS_NO   INTEGER(10) NOT NULL    UNIQUE,
    COURSE_NO       CHAR(4)     NOT NULL,
    START_DT        DATE,
    FULL_PART       CHAR(1)     NOT NULL
    CHECK (
        FULL_PART = "F"
        OR FULL_PART = "P"
    ),
    TIME_SLOT       CHAR(2),
    PERFORMANCE     VARCHAR(20),

    CONSTRAINT
        FOREIGN KEY(PROSPECTUS_NO) REFERENCES Student_0129(PROSPECTUS_NO),
    CONSTRAINT FOREIGN KEY(COURSE_NO) REFERENCES Course_0129(COURSE_NO)
);

-- Data Entry
INSERT INTO Course_0129 (COURSE_NO, COURSE_NAME) VALUES
    ("2926", "Cognitive Skills"),
    ("7612", "Database Management"),
    ("8098", "Algorithms"),
    ("3953", "R Programming"),
    ("3494", "Comm. French-II"),
    ("8381", "Networks"),
    ("9744", "Aptitude"),
    ("6005", "Machine Learning"),
    ("5839", "Unix"),
    ("2938", "Oracle");

INSERT INTO Course_Fee_0129 (COURSE_NO, FULL_PART, FEES) VALUES
    ("2926", "P", 8000),
    ("7612", "F", 9000),
    ("8098", "P", 9400),
    ("3953", "F", 7200),
    ("3494", "P", 4000),
    ("8381", "P", 4600),
    ("9744", "F", 9200),
    ("6005", "F", 5500),
    ("5839", "P", 8300),
    ("2938", "P", 4800);

INSERT INTO Student_0129 (
    PROSPECTUS_NO,
    NAME,
    ADDRESS,
    PHONE_NO,
    D_O_B,
    TOTAL_AMT,
    AMT_PAID,
    INSTALLMENT
)
VALUES
    (30336, "Emílie Shōhei", "Zimland", 1292801969, "2002-1-8", 7200, 0, "I"),
    (80652, "Aleksy Toivo", "Ontgas", 8365416489, "2001-2-9", 9200, 9200, "F"),
    (96013, "Norbert Lailoken", "Fand", 8176515222, "1998-8-14", 9400, 9400, "F"),
    (43852, "Feidlimid Adrijan", "Zimland", 4889216273, "1999-11-18", 4000, 4000, "F"),
    (55850, "Virginia Ríghnach", "Straford", 5769568428, "2002-6-14", 4000, 1000, "I"),
    (52238, "Aamir Jelka", "Klaxstea", 7289156515, "2000-2-21", 4600, 4600, "F"),
    (96858, "Viola Francine", "Volas", 6526425614, "2002-5-21", 7200, 4700, "I"),
    (94311, "Gilles Yusuf", "Boni", 9564043944, "1998-3-16", 7200, 6200, "I"),
    (56924, "Doireann Gaëlle", "Straford", 6592912808, "1998-11-29", 9200, 0, "I"),
    (97257, "Therapon Ayaz", "Bedtin", 1573206254, "2001-4-26", 9200, 9200, "F"),
    (15345, "Quirino Vivek", "Khora", 4235853677, "2000-10-14", 8300, 2700, "I"),
    (39524, "Afi Tessouat", "Ontgas", 4332954027, "1998-1-21", 7200, 2400, "I"),
    (40515, "Susann Chisom", "Anegan", 9187010108, "1999-11-30", 7200, 1700, "I"),
    (89292, "Martialis Hacî", "Straford", 5301049309, "1999-10-19", 9400, 9400, "F"),
    (88905, "Chi Titilayo", "Volas", 4847733538, "1996-10-19", 8300, 8300, "F"),
    (11443, "Nicușor Sultan", "Ontgas", 6352625141, "2000-10-27", 4600, 4600, "F"),
    (65459, "Celyn Hilarion", "Zimland", 8297094562, "1999-10-2", 4600, 0, "I"),
    (73579, "Úrsula Dermid", "Khora", 5337070977, "2000-1-1", 9400, 1800, "I"),
    (41867, "Magni Mehmet", "Boni", 3759652478, "1999-7-13", 9000, 7500, "I"),
    (97528, "Robert Shariah", "Boni", 5829643889, "2002-1-25", 8000, 4400, "I");

INSERT INTO Installment_0129 (
    PROSPECTUS_NO,
    INSTALLMENT_AMT,
    DUE_DT,
    PAID
) VALUES
    (40515, 340, "2022-09-30", "P"),
    (30336, 230, "2022-09-30", "P"),
    (15345, 240, "2022-09-30", "U"),
    (65459, 670, "2022-09-30", "P"),
    (97528, 520, "2022-09-30", "P"),
    (55850, 570, "2022-09-30", "U"),
    (94311, 530, "2022-09-30", "P"),
    (96858, 720, "2022-09-30", "P"),
    (73579, 170, "2022-09-30", "U"),
    (39524, 290, "2022-09-30", "P"),
    (56924, 900, "2022-09-30", "P"),
    (41867, 800, "2022-09-30", "P");

INSERT INTO Course_Taken_0129 (
    PROSPECTUS_NO,
    COURSE_NO,
    START_DT,
    FULL_PART,
    TIME_SLOT,
    PERFORMANCE
) VALUES
    (55850, "3494", "2022-3-19", "P", "2", "satisfactory"),
    (30336, "2938", "2022-4-1", "P", "2", "satisfactory"),
    (94311, "3953", "2022-3-25", "P", "2", "excellent"),
    (15345, "5839", "2022-9-5", "P", "2", "good"),
    (65459, "8381", "2022-6-4", "P", "2", "satisfactory"),
    (89292, "8098", "2022-4-12", "F", "3", "good"),
    (56924, "9744", "2022-2-1", "P", "3", "excellent"),
    (40515, "3953", "2022-9-9", "P", "3", "excellent"),
    (97257, "9744", "2022-1-17", "F", "2", "excellent"),
    (43852, "3494", "2022-2-3", "F", "2", "excellent"),
    (88905, "5839", "2022-9-10", "F", "1", "satisfactory"),
    (52238, "8381", "2022-8-22", "F", "2", "excellent"),
    (39524, "2938", "2022-9-2", "P", "3", "good"),
    (11443, "8381", "2022-6-19", "F", "3", "good"),
    (73579, "8098", "2021-11-30", "P", "3", "unsatisfactory"),
    (97528, "2926", "2022-1-26", "P", "2", "satisfactory"),
    (80652, "9744", "2022-4-29", "F", "2", "unsatisfactory"),
    (96858, "3953", "2022-9-5", "P", "1", "excellent"),
    (41867, "7612", "2022-6-18", "P", "2", "unsatisfactory"),
    (96013, "8098", "2021-12-10", "F", "3", "unsatisfactory");

-- Queries
-- 1. Retrieve name and course number of all students
SELECT S.NAME AS "Name", CT.COURSE_NO AS "Course No."
FROM Student_0129 S, Course_Taken_0129 CT
WHERE S.PROSPECTUS_NO = CT.PROSPECTUS_NO;

-- 2. List the names of students who have paid the full amount at the time of
-- admission.
SELECT S.NAME AS "Name"
FROM Student_0129 S
WHERE S.INSTALLMENT = "F";

-- 3. Find the names of students starting with A.
SELECT S.NAME AS "Name"
FROM Student_0129 S
WHERE S.NAME LIKE "A%";

-- 4. Print the names of students whose total amount is not equal to amount due.
SELECT S.NAME AS "Name"
FROM Student_0129 S
WHERE S.TOTAL_AMT <> (S.TOTAL_AMT - S.AMT_PAID);

-- 5. Count the number of students who have joined in the current year, current
-- month.
SELECT COUNT(*) AS "Number of Students Joining in Current Year, Month"
FROM Course_Taken_0129 CT
WHERE MONTH(CT.START_DT) = MONTH(NOW()) AND YEAR(CT.START_DT) = YEAR(NOW());

-- 6. Determine the maximum and minimum course fees.
SELECT
    C.COURSE_NO AS "Course No.",
    CF.FEES AS "Course Fees",
    C.COURSE_NAME AS "Course Name"
FROM Course_0129 C, Course_Fee_0129 CF
WHERE
    C.COURSE_NO = CF.COURSE_NO
    AND (
        CF.FEES = (
            SELECT MAX(CF.FEES)
            FROM Course_Fee_0129 CF
        )
        OR CF.FEES = (
            SELECT MIN(CF.FEES)
            FROM Course_Fee_0129 CF
        )
    );

-- 7. Increase the fee of oracle by 50%.
SELECT
    C.COURSE_NO AS "Course No.",
    C.COURSE_NAME AS "Course Name",
    CF.FEES AS "Course Fees"
FROM Course_0129 C, Course_Fee_0129 CF
WHERE C.COURSE_NO = CF.COURSE_NO AND C.COURSE_NAME = "Oracle";

UPDATE Course_Fee_0129 CF
SET CF.FEES = CF.FEES * 1.5
WHERE
    CF.COURSE_NO = (
        SELECT C.COURSE_NO
        FROM Course_0129 C
        WHERE C.COURSE_NAME = "Oracle"
    );

SELECT
    C.COURSE_NO AS "Course No.",
    C.COURSE_NAME AS "Course Name",
    CF.FEES AS "Course Fees"
FROM Course_0129 C, Course_Fee_0129 CF
WHERE C.COURSE_NO = CF.COURSE_NO AND C.COURSE_NAME = "Oracle";

-- 8. Print the details of courses whose fees are between 5000 and 10000.
SELECT
    C.COURSE_NO AS "Course No.",
    C.COURSE_NAME AS "Course Name",
    CF.FULL_PART AS "Course Fees/Part",
    CF.FEES AS "Course Fees"
FROM Course_0129 C, Course_Fee_0129 CF
WHERE C.COURSE_NO = CF.COURSE_NO AND CF.FEES BETWEEN 5000 AND 10000;

-- 9. Display the admission date in Date, Month, Year format.
SELECT
    S.PROSPECTUS_NO AS "Prospectus No.",
    S.NAME AS "Student Name",
    CT.COURSE_NO AS "Course Number",
    CONCAT(
        DAY(CT.START_DT),
        " ",
        MONTHNAME(CT.START_DT),
        ", ",
        YEAR(CT.START_DT)
    ) AS "Date of Admission"
FROM Student_0129 S, Course_Taken_0129 CT
WHERE S.PROSPECTUS_NO = CT.PROSPECTUS_NO;

-- 10. Find out in which course maximum number of students have taken admission.
SELECT
    C.COURSE_NO AS "Course No.",
    C.COURSE_NAME AS "Course Name",
    COUNT(*) AS "Course Count"
FROM Course_0129 C, Course_Taken_0129 CT
WHERE C.COURSE_NO = CT.COURSE_NO
GROUP BY CT.COURSE_NO
HAVING COUNT(*) = (
    SELECT MAX(ALL_COURSE_COUNTS)
    FROM (
        SELECT COUNT(*) AS ALL_COURSE_COUNTS
        FROM Course_Taken_0129 CT
        GROUP BY CT.COURSE_NO
    ) COURSE_COUNTS_TABLE
);

-- 11. Change the course_name from Unix to Unix Operating System.
SELECT COURSE_NO AS "Course No.", COURSE_NAME AS "Course Name"
FROM Course_0129 C;

UPDATE Course_0129 C
SET C.COURSE_NAME = "Unix Operating System"
WHERE C.COURSE_NAME = "Unix";

SELECT COURSE_NO AS "Course No.", COURSE_NAME AS "Course Name"
FROM Course_0129 C;

-- 12. Display the admission date in DD-MONTH-YYYY format.
SELECT
    S.PROSPECTUS_NO AS "Prospectus No.",
    S.NAME AS "Name",
    CT.COURSE_NO AS "Course No.",
    CONCAT(
        DAY(CT.START_DT),
        "-",
        UPPER(MONTHNAME(CT.START_DT)),
        "-",
        YEAR(CT.START_DT)
    ) AS "Date of Admission"
FROM Student_0129 S, Course_Taken_0129 CT
WHERE S.PROSPECTUS_NO = CT.PROSPECTUS_NO;

-- 13. Get the sum of amount to be collected from students in this month.
SELECT SUM(I.INSTALLMENT_AMT) AS "Amount to be Collected"
FROM Installment_0129 I
WHERE MONTH(I.DUE_DT) = MONTH(NOW());

-- 14. Find out in which course the maximum number of students have taken
-- admission in the current month.
SELECT
    C.COURSE_NO AS "Course No.",
    C.COURSE_NAME AS "Course Name",
    COUNT(*) AS "Course Count"
FROM Course_0129 C, Course_Taken_0129 CT
WHERE C.COURSE_NO = CT.COURSE_NO
GROUP BY CT.COURSE_NO
HAVING COUNT(*) = (
    SELECT MAX(ALL_COURSE_COUNTS)
    FROM (
        SELECT COUNT(*) AS ALL_COURSE_COUNTS
        FROM Course_Taken_0129 CT
        WHERE
            MONTH(CT.START_DT) = MONTH(NOW())
            AND YEAR(CT.START_DT) = YEAR(NOW())
        GROUP BY CT.COURSE_NO
    ) COURSE_COUNTS_TABLE
);

-- 15. Select the students who have not yet paid full amount of fees.
SELECT
    S.PROSPECTUS_NO AS "Prospectus No.",
    S.NAME AS "Name",
    S.ADDRESS AS "Address",
    S.PHONE_NO AS "Phone No.",
    S.D_O_B AS "Date of Birth",
    S.TOTAL_AMT AS "Total Amount to Pay",
    S.AMT_PAID AS "Amount Paid",
    S.INSTALLMENT AS "Installment Status"
FROM Student_0129 S
WHERE S.TOTAL_AMT > S.AMT_PAID;
