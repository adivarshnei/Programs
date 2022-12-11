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
```

##### Output:
```
mysql> -- Table Creation
mysql> CREATE TABLE Course_0129(
    ->     COURSE_NO   CHAR(4)     NOT NULL    UNIQUE  PRIMARY KEY,
    ->     COURSE_NAME VARCHAR(30)
    -> );
Query OK, 0 rows affected (0.06 sec)

mysql>
mysql> CREATE TABLE Course_Fee_0129(
    ->     COURSE_NO   CHAR(4) NOT NULL    UNIQUE,
    ->     FULL_PART   CHAR(1) NOT NULL
    ->     CHECK (
    ->         FULL_PART = "F"
    ->         OR FULL_PART = "P"
    ->     ),
    ->     FEES        INTEGER(10),
    ->
    ->     CONSTRAINT
    ->         FOREIGN KEY(COURSE_NO)
    ->         REFERENCES Course_0129(COURSE_NO)
    ->         ON DELETE CASCADE
    -> );
Query OK, 0 rows affected, 1 warning (0.04 sec)

mysql>
mysql> CREATE TABLE Student_0129 (
    ->     PROSPECTUS_NO   INTEGER(10)     NOT NULL    UNIQUE  PRIMARY KEY,
    ->     NAME            VARCHAR(20)     NOT NULL,
    ->     ADDRESS         VARCHAR(30),
    ->     PHONE_NO        DECIMAL(11, 0)  UNIQUE,
    ->     D_O_B           DATE            NOT NULL,
    ->     TOTAL_AMT       DECIMAL(10, 2)  NOT NULL,
    ->     AMT_PAID        DECIMAL(10, 2)  NOT NULL,
    ->     INSTALLMENT     CHAR(1)         NOT NULL
    ->     CHECK (
    ->         INSTALLMENT = "I"
    ->         OR INSTALLMENT = "F"
    ->     ),
    ->
    ->     CONSTRAINT CHECK (AMT_PAID <= TOTAL_AMT)
    -> );
Query OK, 0 rows affected, 1 warning (0.07 sec)

mysql>
mysql> CREATE TABLE Installment_0129 (
    ->     PROSPECTUS_NO   INTEGER(10)     NOT NULL    UNIQUE,
    ->     INSTALLMENT_AMT DECIMAL(10, 2)  NOT NULL,
    ->     DUE_DT          DATE            NOT NULL,
    ->     PAID            CHAR(1)         NOT NULL    CHECK(PAID = "P" OR PAID = "U"),
    ->
    ->     CONSTRAINT
    ->         FOREIGN KEY(PROSPECTUS_NO)
    ->         REFERENCES Student_0129(PROSPECTUS_NO)
    ->         ON DELETE CASCADE
    -> );
Query OK, 0 rows affected, 1 warning (0.05 sec)

mysql>
mysql> CREATE TABLE Course_Taken_0129 (
    ->     PROSPECTUS_NO   INTEGER(10) NOT NULL    UNIQUE,
    ->     COURSE_NO       CHAR(4)     NOT NULL,
    ->     START_DT        DATE,
    ->     FULL_PART       CHAR(1)     NOT NULL
    ->     CHECK (
    ->         FULL_PART = "F"
    ->         OR FULL_PART = "P"
    ->     ),
    ->     TIME_SLOT       CHAR(2),
    ->     PERFORMANCE     VARCHAR(20),
    ->
    ->     CONSTRAINT
    ->         FOREIGN KEY(PROSPECTUS_NO)
    ->         REFERENCES Student_0129(PROSPECTUS_NO)
    ->         ON DELETE CASCADE,
    ->     CONSTRAINT
    ->         FOREIGN KEY(COURSE_NO)
    ->         REFERENCES Course_0129(COURSE_NO)
    ->         ON DELETE CASCADE
    -> );
Query OK, 0 rows affected, 1 warning (0.07 sec)

mysql>
mysql> -- Data Entry
mysql> INSERT INTO Course_0129 (COURSE_NO, COURSE_NAME) VALUES
    ->     ("2926", "Cognitive Skills"),
    ->     ("7612", "Database Management"),
    ->     ("8098", "Algorithms"),
    ->     ("3953", "R Programming"),
    ->     ("3494", "Comm. French-II"),
    ->     ("8381", "Networks"),
    ->     ("9744", "Aptitude"),
    ->     ("6005", "Machine Learning"),
    ->     ("5839", "Unix"),
    ->     ("2938", "Oracle");
Query OK, 10 rows affected (0.01 sec)
Records: 10  Duplicates: 0  Warnings: 0

mysql>
mysql> INSERT INTO Course_Fee_0129 (COURSE_NO, FULL_PART, FEES) VALUES
    ->     ("2926", "P", 8000),
    ->     ("7612", "F", 9000),
    ->     ("8098", "P", 9400),
    ->     ("3953", "F", 7200),
    ->     ("3494", "P", 4000),
    ->     ("8381", "P", 4600),
    ->     ("9744", "F", 9200),
    ->     ("6005", "F", 5500),
    ->     ("5839", "P", 8300),
    ->     ("2938", "P", 4800);
Query OK, 10 rows affected (0.01 sec)
Records: 10  Duplicates: 0  Warnings: 0

mysql>
mysql> INSERT INTO Student_0129 (
    ->     PROSPECTUS_NO,
    ->     NAME,
    ->     ADDRESS,
    ->     PHONE_NO,
    ->     D_O_B,
    ->     TOTAL_AMT,
    ->     AMT_PAID,
    ->     INSTALLMENT
    -> )
    -> VALUES
    ->     (30336, "Emílie Shōhei", "Zimland", 1292801969, "2002-1-8", 7200, 0, "I"),
    ->     (80652, "Aleksy Toivo", "Ontgas", 8365416489, "2001-2-9", 9200, 9200, "F"),
    ->     (96013, "Norbert Lailoken", "Fand", 8176515222, "1998-8-14", 9400, 9400, "F"),
    ->     (43852, "Feidlimid Adrijan", "Zimland", 4889216273, "1999-11-18", 4000, 4000, "F"),
    ->     (55850, "Virginia Ríghnach", "Straford", 5769568428, "2002-6-14", 4000, 1000, "I"),
    ->     (52238, "Aamir Jelka", "Klaxstea", 7289156515, "2000-2-21", 4600, 4600, "F"),
    ->     (96858, "Viola Francine", "Volas", 6526425614, "2002-5-21", 7200, 4700, "I"),
    ->     (94311, "Gilles Yusuf", "Boni", 9564043944, "1998-3-16", 7200, 6200, "I"),
    ->     (56924, "Doireann Gaëlle", "Straford", 6592912808, "1998-11-29", 9200, 0, "I"),
    ->     (97257, "Therapon Ayaz", "Bedtin", 1573206254, "2001-4-26", 9200, 9200, "F"),
    ->     (15345, "Quirino Vivek", "Khora", 4235853677, "2000-10-14", 8300, 2700, "I"),
    ->     (39524, "Afi Tessouat", "Ontgas", 4332954027, "1998-1-21", 7200, 2400, "I"),
    ->     (40515, "Susann Chisom", "Anegan", 9187010108, "1999-11-30", 7200, 1700, "I"),
    ->     (89292, "Martialis Hacî", "Straford", 5301049309, "1999-10-19", 9400, 9400, "F"),
    ->     (88905, "Chi Titilayo", "Volas", 4847733538, "1996-10-19", 8300, 8300, "F"),
    ->     (11443, "Nicușor Sultan", "Ontgas", 6352625141, "2000-10-27", 4600, 4600, "F"),
    ->     (65459, "Celyn Hilarion", "Zimland", 8297094562, "1999-10-2", 4600, 0, "I"),
    ->     (73579, "Úrsula Dermid", "Khora", 5337070977, "2000-1-1", 9400, 1800, "I"),
    ->     (41867, "Magni Mehmet", "Boni", 3759652478, "1999-7-13", 9000, 7500, "I"),
    ->     (97528, "Robert Shariah", "Boni", 5829643889, "2002-1-25", 8000, 4400, "I");
Query OK, 20 rows affected (0.01 sec)
Records: 20  Duplicates: 0  Warnings: 0

mysql>
mysql> INSERT INTO Installment_0129 (
    ->     PROSPECTUS_NO,
    ->     INSTALLMENT_AMT,
    ->     DUE_DT,
    ->     PAID
    -> ) VALUES
    ->     (40515, 340, "2022-09-30", "P"),
    ->     (30336, 230, "2022-09-30", "P"),
    ->     (15345, 240, "2022-09-30", "U"),
    ->     (65459, 670, "2022-09-30", "P"),
    ->     (97528, 520, "2022-09-30", "P"),
    ->     (55850, 570, "2022-09-30", "U"),
    ->     (94311, 530, "2022-09-30", "P"),
    ->     (96858, 720, "2022-09-30", "P"),
    ->     (73579, 170, "2022-09-30", "U"),
    ->     (39524, 290, "2022-09-30", "P"),
    ->     (56924, 900, "2022-09-30", "P"),
    ->     (41867, 800, "2022-09-30", "P");
Query OK, 12 rows affected (0.01 sec)
Records: 12  Duplicates: 0  Warnings: 0

mysql>
mysql> INSERT INTO Course_Taken_0129 (
    ->     PROSPECTUS_NO,
    ->     COURSE_NO,
    ->     START_DT,
    ->     FULL_PART,
    ->     TIME_SLOT,
    ->     PERFORMANCE
    -> ) VALUES
    ->     (55850, "3494", "2022-3-19", "P", "2", "satisfactory"),
    ->     (30336, "2938", "2022-4-1", "P", "2", "satisfactory"),
    ->     (94311, "3953", "2022-3-25", "P", "2", "excellent"),
    ->     (15345, "5839", "2022-9-5", "P", "2", "good"),
    ->     (65459, "8381", "2022-6-4", "P", "2", "satisfactory"),
    ->     (89292, "8098", "2022-4-12", "F", "3", "good"),
    ->     (56924, "9744", "2022-2-1", "P", "3", "excellent"),
    ->     (40515, "3953", "2022-9-9", "P", "3", "excellent"),
    ->     (97257, "9744", "2022-1-17", "F", "2", "excellent"),
    ->     (43852, "3494", "2022-2-3", "F", "2", "excellent"),
    ->     (88905, "5839", "2022-9-10", "F", "1", "satisfactory"),
    ->     (52238, "8381", "2022-8-22", "F", "2", "excellent"),
    ->     (39524, "2938", "2022-9-2", "P", "3", "good"),
    ->     (11443, "8381", "2022-6-19", "F", "3", "good"),
    ->     (73579, "8098", "2021-11-30", "P", "3", "unsatisfactory"),
    ->     (97528, "2926", "2022-1-26", "P", "2", "satisfactory"),
    ->     (80652, "9744", "2022-4-29", "F", "2", "unsatisfactory"),
    ->     (96858, "3953", "2022-9-5", "P", "1", "excellent"),
    ->     (41867, "7612", "2022-6-18", "P", "2", "unsatisfactory"),
    ->     (96013, "8098", "2021-12-10", "F", "3", "unsatisfactory");
Query OK, 20 rows affected (0.01 sec)
Records: 20  Duplicates: 0  Warnings: 0
```

### Queries:
#### 1. Retrieve name and course number of all students.

##### Query:
```sql
SELECT S.NAME AS "Name", CT.COURSE_NO AS "Course No."
FROM Student_0129 S, Course_Taken_0129 CT
WHERE S.PROSPECTUS_NO = CT.PROSPECTUS_NO;
```

##### Output:
```
mysql> SELECT S.NAME AS "Name", CT.COURSE_NO AS "Course No."
    -> FROM Student_0129 S, Course_Taken_0129 CT
    -> WHERE S.PROSPECTUS_NO = CT.PROSPECTUS_NO;
+--------------------+------------+
| Name               | Course No. |
+--------------------+------------+
| Nicușor Sultan     | 8381       |
| Quirino Vivek      | 5839       |
| Emílie Shōhei      | 2938       |
| Afi Tessouat       | 2938       |
| Susann Chisom      | 3953       |
| Magni Mehmet       | 7612       |
| Feidlimid Adrijan  | 3494       |
| Aamir Jelka        | 8381       |
| Virginia Ríghnach  | 3494       |
| Doireann Gaëlle    | 9744       |
| Celyn Hilarion     | 8381       |
| Úrsula Dermid      | 8098       |
| Aleksy Toivo       | 9744       |
| Chi Titilayo       | 5839       |
| Martialis Hacî     | 8098       |
| Gilles Yusuf       | 3953       |
| Norbert Lailoken   | 8098       |
| Viola Francine     | 3953       |
| Therapon Ayaz      | 9744       |
| Robert Shariah     | 2926       |
+--------------------+------------+
20 rows in set (0.00 sec)
```

#### 2. List the names of students who have paid the full amount at the time of admission.

##### Query:
```sql
SELECT S.NAME AS "Name"
FROM Student_0129 S
WHERE S.INSTALLMENT = "F";
```

##### Output:
```
mysql> SELECT S.NAME AS "Name"
    -> FROM Student_0129 S
    -> WHERE S.INSTALLMENT = "F";
+-------------------+
| Name              |
+-------------------+
| Nicușor Sultan    |
| Feidlimid Adrijan |
| Aamir Jelka       |
| Aleksy Toivo      |
| Chi Titilayo      |
| Martialis Hacî    |
| Norbert Lailoken  |
| Therapon Ayaz     |
+-------------------+
8 rows in set (0.00 sec)
```

#### 3. Find the names of students starting with <span style = "font-family:Input">A</span>.

##### Query:
```sql
SELECT S.NAME AS "Name"
FROM Student_0129 S
WHERE S.NAME LIKE "A%";
```

##### Output:
```
mysql> SELECT S.NAME AS "Name"
    -> FROM Student_0129 S
    -> WHERE S.NAME LIKE "A%";
+--------------+
| Name         |
+--------------+
| Afi Tessouat |
| Aamir Jelka  |
| Aleksy Toivo |
+--------------+
3 rows in set (0.00 sec)
```

#### 4. Print the names of students whose total amount is not equal to amount due.

##### Query:
```sql
SELECT S.NAME AS "Name"
FROM Student_0129 S
WHERE S.TOTAL_AMT <> (S.TOTAL_AMT - S.AMT_PAID);
```

##### Output:
```
mysql> SELECT S.NAME AS "Name"
    -> FROM Student_0129 S
    -> WHERE S.TOTAL_AMT <> (S.TOTAL_AMT - S.AMT_PAID);
+--------------------+
| Name               |
+--------------------+
| Nicușor Sultan     |
| Quirino Vivek      |
| Afi Tessouat       |
| Susann Chisom      |
| Magni Mehmet       |
| Feidlimid Adrijan  |
| Aamir Jelka        |
| Virginia Ríghnach  |
| Úrsula Dermid      |
| Aleksy Toivo       |
| Chi Titilayo       |
| Martialis Hacî     |
| Gilles Yusuf       |
| Norbert Lailoken   |
| Viola Francine     |
| Therapon Ayaz      |
| Robert Shariah     |
+--------------------+
17 rows in set (0.00 sec)
```

#### 5. Count the number of students who have joined in the current year, current month.

##### Query:
```sql
SELECT COUNT(*) AS "Number of Students Joining in Current Year, Month"
FROM Course_Taken_0129 CT
WHERE MONTH(CT.START_DT) = MONTH(NOW()) AND YEAR(CT.START_DT) = YEAR(NOW());
```

##### Output:
```
mysql> SELECT COUNT(*) AS "Number of Students Joining in Current Year, Month"
    -> FROM Course_Taken_0129 CT
    -> WHERE MONTH(CT.START_DT) = MONTH(NOW()) AND YEAR(CT.START_DT) = YEAR(NOW());
+---------------------------------------------------+
| Number of Students Joining in Current Year, Month |
+---------------------------------------------------+
|                                                 5 |
+---------------------------------------------------+
1 row in set (0.00 sec)
```

#### 6. Determine the maximum and minimum course fees.

##### Query:
```sql
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
```

##### Output:
```
mysql> SELECT
    ->     C.COURSE_NO AS "Course No.",
    ->     CF.FEES AS "Course Fees",
    ->     C.COURSE_NAME AS "Course Name"
    -> FROM Course_0129 C, Course_Fee_0129 CF
    -> WHERE
    ->     C.COURSE_NO = CF.COURSE_NO
    ->     AND (
    ->         CF.FEES = (
    ->             SELECT MAX(CF.FEES)
    ->             FROM Course_Fee_0129 CF
    ->         )
    ->         OR CF.FEES = (
    ->             SELECT MIN(CF.FEES)
    ->             FROM Course_Fee_0129 CF
    ->         )
    ->     );
+------------+-------------+-----------------+
| Course No. | Course Fees | Course Name     |
+------------+-------------+-----------------+
| 3494       |        4000 | Comm. French-II |
| 8098       |        9400 | Algorithms      |
+------------+-------------+-----------------+
2 rows in set (0.00 sec)
```

#### 7. Increase the fee of <span style = "font-family:Input">oracle</span> by $50\%$.

##### Query:
```sql
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
```

##### Output:
```
mysql> SELECT
    ->     C.COURSE_NO AS "Course No.",
    ->     C.COURSE_NAME AS "Course Name",
    ->     CF.FEES AS "Course Fees"
    -> FROM Course_0129 C, Course_Fee_0129 CF
    -> WHERE C.COURSE_NO = CF.COURSE_NO AND C.COURSE_NAME = "Oracle";
+------------+-------------+-------------+
| Course No. | Course Name | Course Fees |
+------------+-------------+-------------+
| 2938       | Oracle      |        4800 |
+------------+-------------+-------------+
1 row in set (0.00 sec)

mysql>
mysql> UPDATE Course_Fee_0129 CF
    -> SET CF.FEES = CF.FEES * 1.5
    -> WHERE
    ->     CF.COURSE_NO = (
    ->         SELECT C.COURSE_NO
    ->         FROM Course_0129 C
    ->         WHERE C.COURSE_NAME = "Oracle"
    ->     );
Query OK, 1 row affected (0.00 sec)
Rows matched: 1  Changed: 1  Warnings: 0

mysql>
mysql> SELECT
    ->     C.COURSE_NO AS "Course No.",
    ->     C.COURSE_NAME AS "Course Name",
    ->     CF.FEES AS "Course Fees"
    -> FROM Course_0129 C, Course_Fee_0129 CF
    -> WHERE C.COURSE_NO = CF.COURSE_NO AND C.COURSE_NAME = "Oracle";
+------------+-------------+-------------+
| Course No. | Course Name | Course Fees |
+------------+-------------+-------------+
| 2938       | Oracle      |        7200 |
+------------+-------------+-------------+
1 row in set (0.00 sec)
```

#### 8. Print the details of courses whose fees are between $5000$ and $10000$.

##### Query:
```sql
SELECT
    C.COURSE_NO AS "Course No.",
    C.COURSE_NAME AS "Course Name",
    CF.FULL_PART AS "Course Fees/Part",
    CF.FEES AS "Course Fees"
FROM Course_0129 C, Course_Fee_0129 CF
WHERE C.COURSE_NO = CF.COURSE_NO AND CF.FEES BETWEEN 5000 AND 10000;
```

##### Output:
```
mysql> SELECT
    ->     C.COURSE_NO AS "Course No.",
    ->     C.COURSE_NAME AS "Course Name",
    ->     CF.FULL_PART AS "Course Fees/Part",
    ->     CF.FEES AS "Course Fees"
    -> FROM Course_0129 C, Course_Fee_0129 CF
    -> WHERE C.COURSE_NO = CF.COURSE_NO AND CF.FEES BETWEEN 5000 AND 10000;
+------------+---------------------+------------------+-------------+
| Course No. | Course Name         | Course Fees/Part | Course Fees |
+------------+---------------------+------------------+-------------+
| 2926       | Cognitive Skills    | P                |        8000 |
| 2938       | Oracle              | P                |        7200 |
| 3953       | R Programming       | F                |        7200 |
| 5839       | Unix                | P                |        8300 |
| 6005       | Machine Learning    | F                |        5500 |
| 7612       | Database Management | F                |        9000 |
| 8098       | Algorithms          | P                |        9400 |
| 9744       | Aptitude            | F                |        9200 |
+------------+---------------------+------------------+-------------+
8 rows in set (0.00 sec)
```

#### 9. Display the admission date in <span style = "font-family:Input">Date, Month, Year</span> format.

##### Query:
```sql
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
```

##### Output:
```
mysql> SELECT
    ->     S.PROSPECTUS_NO AS "Prospectus No.",
    ->     S.NAME AS "Student Name",
    ->     CT.COURSE_NO AS "Course Number",
    ->     CONCAT(
    ->         DAY(CT.START_DT),
    ->         " ",
    ->         MONTHNAME(CT.START_DT),
    ->         ", ",
    ->         YEAR(CT.START_DT)
    ->     ) AS "Date of Admission"
    -> FROM Student_0129 S, Course_Taken_0129 CT
    -> WHERE S.PROSPECTUS_NO = CT.PROSPECTUS_NO;
+----------------+--------------------+---------------+--------------------+
| Prospectus No. | Student Name       | Course Number | Date of Admission  |
+----------------+--------------------+---------------+--------------------+
|          11443 | Nicușor Sultan     | 8381          | 19 June, 2022      |
|          15345 | Quirino Vivek      | 5839          | 5 September, 2022  |
|          30336 | Emílie Shōhei      | 2938          | 1 April, 2022      |
|          39524 | Afi Tessouat       | 2938          | 2 September, 2022  |
|          40515 | Susann Chisom      | 3953          | 9 September, 2022  |
|          41867 | Magni Mehmet       | 7612          | 18 June, 2022      |
|          43852 | Feidlimid Adrijan  | 3494          | 3 February, 2022   |
|          52238 | Aamir Jelka        | 8381          | 22 August, 2022    |
|          55850 | Virginia Ríghnach  | 3494          | 19 March, 2022     |
|          56924 | Doireann Gaëlle    | 9744          | 1 February, 2022   |
|          65459 | Celyn Hilarion     | 8381          | 4 June, 2022       |
|          73579 | Úrsula Dermid      | 8098          | 30 November, 2021  |
|          80652 | Aleksy Toivo       | 9744          | 29 April, 2022     |
|          88905 | Chi Titilayo       | 5839          | 10 September, 2022 |
|          89292 | Martialis Hacî     | 8098          | 12 April, 2022     |
|          94311 | Gilles Yusuf       | 3953          | 25 March, 2022     |
|          96013 | Norbert Lailoken   | 8098          | 10 December, 2021  |
|          96858 | Viola Francine     | 3953          | 5 September, 2022  |
|          97257 | Therapon Ayaz      | 9744          | 17 January, 2022   |
|          97528 | Robert Shariah     | 2926          | 26 January, 2022   |
+----------------+--------------------+---------------+--------------------+
20 rows in set (0.00 sec)
```

#### 10. Find out in which course maximum number of students have taken admission.

##### Query:
```sql
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
```

##### Output:
```
mysql> SELECT
    ->     C.COURSE_NO AS "Course No.",
    ->     C.COURSE_NAME AS "Course Name",
    ->     COUNT(*) AS "Course Count"
    -> FROM Course_0129 C, Course_Taken_0129 CT
    -> WHERE C.COURSE_NO = CT.COURSE_NO
    -> GROUP BY CT.COURSE_NO
    -> HAVING COUNT(*) = (
    ->     SELECT MAX(ALL_COURSE_COUNTS)
    ->     FROM (
    ->         SELECT COUNT(*) AS ALL_COURSE_COUNTS
    ->         FROM Course_Taken_0129 CT
    ->         GROUP BY CT.COURSE_NO
    ->     ) COURSE_COUNTS_TABLE
    -> );
+------------+---------------+--------------+
| Course No. | Course Name   | Course Count |
+------------+---------------+--------------+
| 3953       | R Programming |            3 |
| 8098       | Algorithms    |            3 |
| 8381       | Networks      |            3 |
| 9744       | Aptitude      |            3 |
+------------+---------------+--------------+
4 rows in set (0.00 sec)
```

#### 11. Change the <span style = "font-family:Input">course_name</span> from <span style = "font-family:Input">Unix</span> to <span style = "font-family:Input">Unix Operating System</span>.

##### Query:
```sql
SELECT COURSE_NO AS "Course No.", COURSE_NAME AS "Course Name"
FROM Course_0129 C;

UPDATE Course_0129 C
SET C.COURSE_NAME = "Unix Operating System"
WHERE C.COURSE_NAME = "Unix";

SELECT COURSE_NO AS "Course No.", COURSE_NAME AS "Course Name"
FROM Course_0129 C;
```

##### Output:
```
mysql> SELECT COURSE_NO AS "Course No.", COURSE_NAME AS "Course Name"
    -> FROM Course_0129 C;
+------------+---------------------+
| Course No. | Course Name         |
+------------+---------------------+
| 2926       | Cognitive Skills    |
| 2938       | Oracle              |
| 3494       | Comm. French-II     |
| 3953       | R Programming       |
| 5839       | Unix                |
| 6005       | Machine Learning    |
| 7612       | Database Management |
| 8098       | Algorithms          |
| 8381       | Networks            |
| 9744       | Aptitude            |
+------------+---------------------+
10 rows in set (0.00 sec)

mysql>
mysql> UPDATE Course_0129 C
    -> SET C.COURSE_NAME = "Unix Operating System"
    -> WHERE C.COURSE_NAME = "Unix";
Query OK, 1 row affected (0.00 sec)
Rows matched: 1  Changed: 1  Warnings: 0

mysql>
mysql> SELECT COURSE_NO AS "Course No.", COURSE_NAME AS "Course Name"
    -> FROM Course_0129 C;
+------------+-----------------------+
| Course No. | Course Name           |
+------------+-----------------------+
| 2926       | Cognitive Skills      |
| 2938       | Oracle                |
| 3494       | Comm. French-II       |
| 3953       | R Programming         |
| 5839       | Unix Operating System |
| 6005       | Machine Learning      |
| 7612       | Database Management   |
| 8098       | Algorithms            |
| 8381       | Networks              |
| 9744       | Aptitude              |
+------------+-----------------------+
10 rows in set (0.00 sec)
```

#### 12. Display the admission date in <span style = "font-family:Input">DD-MONTH-YYYY</span> format.

##### Query:
```sql
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
```

##### Output:
```
mysql> SELECT
    ->     S.PROSPECTUS_NO AS "Prospectus No.",
    ->     S.NAME AS "Name",
    ->     CT.COURSE_NO AS "Course No.",
    ->     CONCAT(
    ->         DAY(CT.START_DT),
    ->         "-",
    ->         UPPER(MONTHNAME(CT.START_DT)),
    ->         "-",
    ->         YEAR(CT.START_DT)
    ->     ) AS "Date of Admission"
    -> FROM Student_0129 S, Course_Taken_0129 CT
    -> WHERE S.PROSPECTUS_NO = CT.PROSPECTUS_NO;
+----------------+--------------------+------------+-------------------+
| Prospectus No. | Name               | Course No. | Date of Admission |
+----------------+--------------------+------------+-------------------+
|          11443 | Nicușor Sultan     | 8381       | 19-JUNE-2022      |
|          15345 | Quirino Vivek      | 5839       | 5-SEPTEMBER-2022  |
|          30336 | Emílie Shōhei      | 2938       | 1-APRIL-2022      |
|          39524 | Afi Tessouat       | 2938       | 2-SEPTEMBER-2022  |
|          40515 | Susann Chisom      | 3953       | 9-SEPTEMBER-2022  |
|          41867 | Magni Mehmet       | 7612       | 18-JUNE-2022      |
|          43852 | Feidlimid Adrijan  | 3494       | 3-FEBRUARY-2022   |
|          52238 | Aamir Jelka        | 8381       | 22-AUGUST-2022    |
|          55850 | Virginia Ríghnach  | 3494       | 19-MARCH-2022     |
|          56924 | Doireann Gaëlle    | 9744       | 1-FEBRUARY-2022   |
|          65459 | Celyn Hilarion     | 8381       | 4-JUNE-2022       |
|          73579 | Úrsula Dermid      | 8098       | 30-NOVEMBER-2021  |
|          80652 | Aleksy Toivo       | 9744       | 29-APRIL-2022     |
|          88905 | Chi Titilayo       | 5839       | 10-SEPTEMBER-2022 |
|          89292 | Martialis Hacî     | 8098       | 12-APRIL-2022     |
|          94311 | Gilles Yusuf       | 3953       | 25-MARCH-2022     |
|          96013 | Norbert Lailoken   | 8098       | 10-DECEMBER-2021  |
|          96858 | Viola Francine     | 3953       | 5-SEPTEMBER-2022  |
|          97257 | Therapon Ayaz      | 9744       | 17-JANUARY-2022   |
|          97528 | Robert Shariah     | 2926       | 26-JANUARY-2022   |
+----------------+--------------------+------------+-------------------+
20 rows in set (0.00 sec)
```

#### 13. Get the sum of amount to be collected from students in this month.

##### Query:
```sql
SELECT SUM(I.INSTALLMENT_AMT) AS "Amount to be Collected"
FROM Installment_0129 I
WHERE MONTH(I.DUE_DT) = MONTH(NOW());
```

##### Output:
```
mysql> SELECT SUM(I.INSTALLMENT_AMT) AS "Amount to be Collected"
    -> FROM Installment_0129 I
    -> WHERE MONTH(I.DUE_DT) = MONTH(NOW());
+------------------------+
| Amount to be Collected |
+------------------------+
|                5980.00 |
+------------------------+
1 row in set (0.00 sec)
```

#### 14. Find out in which course the maximum number of students have taken admission in the current month.

##### Query:
```sql
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
```

##### Output:
```
mysql> SELECT
    ->     C.COURSE_NO AS "Course No.",
    ->     C.COURSE_NAME AS "Course Name",
    ->     COUNT(*) AS "Course Count"
    -> FROM Course_0129 C, Course_Taken_0129 CT
    -> WHERE C.COURSE_NO = CT.COURSE_NO
    -> GROUP BY CT.COURSE_NO
    -> HAVING COUNT(*) = (
    ->     SELECT MAX(ALL_COURSE_COUNTS)
    ->     FROM (
    ->         SELECT COUNT(*) AS ALL_COURSE_COUNTS
    ->         FROM Course_Taken_0129 CT
    ->         WHERE
    ->             MONTH(CT.START_DT) = MONTH(NOW())
    ->             AND YEAR(CT.START_DT) = YEAR(NOW())
    ->         GROUP BY CT.COURSE_NO
    ->     ) COURSE_COUNTS_TABLE
    -> );
+------------+-----------------------+--------------+
| Course No. | Course Name           | Course Count |
+------------+-----------------------+--------------+
| 2938       | Oracle                |            2 |
| 3494       | Comm. French-II       |            2 |
| 5839       | Unix Operating System |            2 |
+------------+-----------------------+--------------+
3 rows in set (0.00 sec)
```

#### 15. Select the students who have not yet paid full amount of fees.

##### Query:
```sql
SELECT
    S.PROSPECTUS_NO AS "Prospectus No.",
    S.NAME AS "Name",
    S.TOTAL_AMT AS "Total Amount",
    S.AMT_PAID AS "Amount Paid",
    S.INSTALLMENT AS "Installment Status"
FROM Student_0129 S
WHERE S.TOTAL_AMT > S.AMT_PAID;
```

##### Output:
```
mysql> SELECT
    ->     S.PROSPECTUS_NO AS "Prospectus No.",
    ->     S.NAME AS "Name",
    ->     S.TOTAL_AMT AS "Total Amount",
    ->     S.AMT_PAID AS "Amount Paid",
    ->     S.INSTALLMENT AS "Installment Status"
    -> FROM Student_0129 S
    -> WHERE S.TOTAL_AMT > S.AMT_PAID;
+----------------+--------------------+--------------+-------------+--------------------+
| Prospectus No. | Name               | Total Amount | Amount Paid | Installment Status |
+----------------+--------------------+--------------+-------------+--------------------+
|          15345 | Quirino Vivek      |      8300.00 |     2700.00 | I                  |
|          30336 | Emílie Shōhei      |      7200.00 |        0.00 | I                  |
|          39524 | Afi Tessouat       |      7200.00 |     2400.00 | I                  |
|          40515 | Susann Chisom      |      7200.00 |     1700.00 | I                  |
|          41867 | Magni Mehmet       |      9000.00 |     7500.00 | I                  |
|          55850 | Virginia Ríghnach  |      4000.00 |     1000.00 | I                  |
|          56924 | Doireann Gaëlle    |      9200.00 |        0.00 | I                  |
|          65459 | Celyn Hilarion     |      4600.00 |        0.00 | I                  |
|          73579 | Úrsula Dermid      |      9400.00 |     1800.00 | I                  |
|          94311 | Gilles Yusuf       |      7200.00 |     6200.00 | I                  |
|          96858 | Viola Francine     |      7200.00 |     4700.00 | I                  |
|          97528 | Robert Shariah     |      8000.00 |     4400.00 | I                  |
+----------------+--------------------+--------------+-------------+--------------------+
12 rows in set (0.00 sec)
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
-- Table Creation
CREATE TABLE SUPPLIER_0129 (
    SNO     INTEGER(5)  NOT NULL    UNIQUE  PRIMARY KEY,
    SNAME   VARCHAR(10) NOT NULL    UNIQUE,
    STATUS  CHAR(11)
    CHECK (
        STATUS = "WORKING"
        OR STATUS = "NOT WORKING"
    ),
    CITY    VARCHAR(10)
);

CREATE TABLE PARTS_0129 (
    PNO     INTEGER(5)  NOT NULL    UNIQUE  PRIMARY KEY,
    PNAME   VARCHAR(10) NOT NULL    UNIQUE,
    COLOR   VARCHAR(10) NOT NULL,
    WEIGHT  INTEGER(5),
    CITY    VARCHAR(10)
);

CREATE TABLE PROJECT_0129 (
    JNO     INTEGER(5)  NOT NULL    UNIQUE PRIMARY KEY,
    JNAME   VARCHAR(10) NOT NULL    UNIQUE,
    CITY    VARCHAR(10)
);

CREATE TABLE SPJ_0129 (
    SNO     INTEGER(5)  NOT NULL,
    PNO     INTEGER(5)  NOT NULL,
    JNO     INTEGER(5)  NOT NULL,
    QTY     INTEGER(5)  NOT NULL,
    CONSTRAINT
        FOREIGN KEY(SNO)
        REFERENCES SUPPLIER_0129(SNO)
        ON DELETE CASCADE,
    CONSTRAINT
        FOREIGN KEY(PNO)
        REFERENCES PARTS_0129(PNO)
        ON DELETE CASCADE,
    CONSTRAINT
        FOREIGN KEY(JNO)
        REFERENCES PROJECT_0129(JNO)
        ON DELETE CASCADE
);

-- Data Entry
INSERT INTO SUPPLIER_0129 (SNO, SNAME, STATUS, CITY) VALUES
    (12579, "s1", "NOT WORKING", "Paris"),
    (14677, "s2", "WORKING", "Berlin"),
    (19187, "s3", "WORKING", "Paris"),
    (19379, "s4", "WORKING", "Vienna"),
    (17967, "s5", "WORKING", "Madrid"),
    (11048, "s6", "WORKING", "London"),
    (19690, "s7", "NOT WORKING", "Madrid"),
    (11859, "s8", "WORKING", "London"),
    (16240, "s9", "WORKING", "Madrid"),
    (15525, "s10", "NOT WORKING", "Madrid"),
    (10070, "s11", "WORKING", "Paris"),
    (17100, "s12", "WORKING", "Madrid"),
    (11500, "s13", "WORKING", "Paris"),
    (16518, "s14", "WORKING", "London"),
    (11230, "s15", "WORKING", "Vienna"),
    (18900, "s16", "WORKING", "Madrid"),
    (18643, "s17", "WORKING", "Vienna"),
    (19568, "s18", "WORKING", "Madrid"),
    (15739, "s19", "WORKING", "Madrid"),
    (18021, "s20", "NOT WORKING", "Berlin");

INSERT INTO PARTS_0129 (PNO, PNAME, COLOR, WEIGHT, CITY) VALUES
    (25203, "p1", "Blue", 150, "London"),
	(28326, "p2", "Red", 140, "Paris"),
	(21837, "p3", "Blue", 150, "Paris"),
	(21435, "p4", "Black", 110, "London"),
	(26383, "p5", "Yellow", 190, "Madrid"),
	(27083, "p6", "Green", 180, "Vienna"),
	(28631, "p7", "Green", 190, "Vienna"),
	(25212, "p8", "Blue", 200, "Paris"),
	(29445, "p9", "Black", 120, "London"),
	(23187, "p10", "Red", 170, "Berlin"),
	(29609, "p11", "Blue", 150, "Paris"),
	(25025, "p12", "Red", 170, "Paris"),
	(28842, "p13", "Black", 100, "Paris"),
	(24396, "p14", "Black", 150, "Berlin"),
	(28173, "p15", "Blue", 160, "Vienna"),
	(29457, "p16", "Yellow", 110, "Vienna"),
	(20876, "p17", "Red", 150, "Berlin"),
	(26749, "p18", "Green", 160, "Berlin"),
	(26188, "p19", "Red", 100, "London"),
	(29224, "p20", "Green", 120, "Vienna");

INSERT INTO PROJECT_0129 (JNO, JNAME, CITY) VALUES
	(35986, "j1", "Paris"),
	(31438, "j2", "London"),
	(39299, "j3", "Berlin"),
	(37650, "j4", "Paris"),
	(35151, "j5", "Berlin"),
	(37114, "j6", "London"),
	(37474, "j7", "Vienna"),
	(34872, "j8", "Madrid"),
	(33604, "j9", "London"),
	(33104, "j10", "Vienna");

INSERT INTO SPJ_0129 (SNO, PNO, JNO, QTY) VALUES
    (14677, 26188, 39299, 11),
	(16518, 28326, 35986, 14),
	(11230, 21837, 33604, 20),
	(18643, 29609, 33604, 2),
	(19690, 29224, 37650, 19),
	(19568, 24396, 33604, 11),
	(12579, 25203, 35151, 8),
	(18900, 21435, 37650, 2),
	(11500, 25025, 37474, 7),
	(16240, 29445, 37114, 7),
	(19379, 25203, 35986, 4),
	(17967, 27083, 33104, 1),
	(10070, 25212, 35986, 12),
	(11859, 28842, 34872, 6),
	(18021, 25203, 34872, 9),
	(16518, 28631, 31438, 12),
	(17100, 26749, 37650, 16),
	(15739, 23187, 35151, 7),
	(15525, 26383, 37114, 17),
	(19187, 20876, 33604, 9),
    (18900, 26383, 35986, 13),
    (18900, 26383, 31438, 1),
    (18900, 26383, 39299, 18),
    (18900, 26383, 37650, 1),
    (18900, 26383, 35151, 19),
    (18900, 26383, 37114, 11),
    (18900, 26383, 37474, 7),
    (18900, 26383, 34872, 1),
    (18900, 26383, 33604, 9),
    (18900, 26383, 33104, 16);
```

##### Output:
```
mysql> -- Table Creation
mysql> CREATE TABLE SUPPLIER_0129 (
    ->     SNO     INTEGER(5)  NOT NULL    UNIQUE  PRIMARY KEY,
    ->     SNAME   VARCHAR(10) NOT NULL    UNIQUE,
    ->     STATUS  CHAR(11)
    ->     CHECK (
    ->         STATUS = "WORKING"
    ->         OR STATUS = "NOT WORKING"
    ->     ),
    ->     CITY    VARCHAR(10)
    -> );
Query OK, 0 rows affected, 1 warning (0.04 sec)

mysql>
mysql> CREATE TABLE PARTS_0129 (
    ->     PNO     INTEGER(5)  NOT NULL    UNIQUE  PRIMARY KEY,
    ->     PNAME   VARCHAR(10) NOT NULL    UNIQUE,
    ->     COLOR   VARCHAR(10) NOT NULL,
    ->     WEIGHT  INTEGER(5),
    ->     CITY    VARCHAR(10)
    -> );
Query OK, 0 rows affected, 2 warnings (0.07 sec)

mysql>
mysql> CREATE TABLE PROJECT_0129 (
    ->     JNO     INTEGER(5)  NOT NULL    UNIQUE PRIMARY KEY,
    ->     JNAME   VARCHAR(10) NOT NULL    UNIQUE,
    ->     CITY    VARCHAR(10)
    -> );
Query OK, 0 rows affected, 1 warning (0.06 sec)

mysql>
mysql> CREATE TABLE SPJ_0129 (
    ->     SNO     INTEGER(5)  NOT NULL,
    ->     PNO     INTEGER(5)  NOT NULL,
    ->     JNO     INTEGER(5)  NOT NULL,
    ->     QTY     INTEGER(5)  NOT NULL,
    ->     CONSTRAINT
    ->         FOREIGN KEY(SNO)
    ->         REFERENCES SUPPLIER_0129(SNO)
    ->         ON DELETE CASCADE,
    ->     CONSTRAINT
    ->         FOREIGN KEY(PNO)
    ->         REFERENCES PARTS_0129(PNO)
    ->         ON DELETE CASCADE,
    ->     CONSTRAINT
    ->         FOREIGN KEY(JNO)
    ->         REFERENCES PROJECT_0129(JNO)
    ->         ON DELETE CASCADE
    -> );
Query OK, 0 rows affected, 4 warnings (0.08 sec)

mysql>
mysql> -- Data Entry
mysql> INSERT INTO SUPPLIER_0129 (SNO, SNAME, STATUS, CITY) VALUES
    ->     (12579, "s1", "NOT WORKING", "Paris"),
    ->     (14677, "s2", "WORKING", "Berlin"),
    ->     (19187, "s3", "WORKING", "Paris"),
    ->     (19379, "s4", "WORKING", "Vienna"),
    ->     (17967, "s5", "WORKING", "Madrid"),
    ->     (11048, "s6", "WORKING", "London"),
    ->     (19690, "s7", "NOT WORKING", "Madrid"),
    ->     (11859, "s8", "WORKING", "London"),
    ->     (16240, "s9", "WORKING", "Madrid"),
    ->     (15525, "s10", "NOT WORKING", "Madrid"),
    ->     (10070, "s11", "WORKING", "Paris"),
    ->     (17100, "s12", "WORKING", "Madrid"),
    ->     (11500, "s13", "WORKING", "Paris"),
    ->     (16518, "s14", "WORKING", "London"),
    ->     (11230, "s15", "WORKING", "Vienna"),
    ->     (18900, "s16", "WORKING", "Madrid"),
    ->     (18643, "s17", "WORKING", "Vienna"),
    ->     (19568, "s18", "WORKING", "Madrid"),
    ->     (15739, "s19", "WORKING", "Madrid"),
    ->     (18021, "s20", "NOT WORKING", "Berlin");
Query OK, 20 rows affected (0.01 sec)
Records: 20  Duplicates: 0  Warnings: 0

mysql>
mysql> INSERT INTO PARTS_0129 (PNO, PNAME, COLOR, WEIGHT, CITY) VALUES
    ->     (25203, "p1", "Blue", 150, "London"),
    ->  (28326, "p2", "Red", 140, "Paris"),
    ->  (21837, "p3", "Blue", 150, "Paris"),
    ->  (21435, "p4", "Black", 110, "London"),
    ->  (26383, "p5", "Yellow", 190, "Madrid"),
    ->  (27083, "p6", "Green", 180, "Vienna"),
    ->  (28631, "p7", "Green", 190, "Vienna"),
    ->  (25212, "p8", "Blue", 200, "Paris"),
    ->  (29445, "p9", "Black", 120, "London"),
    ->  (23187, "p10", "Red", 170, "Berlin"),
    ->  (29609, "p11", "Blue", 150, "Paris"),
    ->  (25025, "p12", "Red", 170, "Paris"),
    ->  (28842, "p13", "Black", 100, "Paris"),
    ->  (24396, "p14", "Black", 150, "Berlin"),
    ->  (28173, "p15", "Blue", 160, "Vienna"),
    ->  (29457, "p16", "Yellow", 110, "Vienna"),
    ->  (20876, "p17", "Red", 150, "Berlin"),
    ->  (26749, "p18", "Green", 160, "Berlin"),
    ->  (26188, "p19", "Red", 100, "London"),
    ->  (29224, "p20", "Green", 120, "Vienna");
Query OK, 20 rows affected (0.01 sec)
Records: 20  Duplicates: 0  Warnings: 0

mysql>
mysql> INSERT INTO PROJECT_0129 (JNO, JNAME, CITY) VALUES
    ->  (35986, "j1", "Paris"),
    ->  (31438, "j2", "London"),
    ->  (39299, "j3", "Berlin"),
    ->  (37650, "j4", "Paris"),
    ->  (35151, "j5", "Berlin"),
    ->  (37114, "j6", "London"),
    ->  (37474, "j7", "Vienna"),
    ->  (34872, "j8", "Madrid"),
    ->  (33604, "j9", "London"),
    ->  (33104, "j10", "Vienna");
Query OK, 10 rows affected (0.01 sec)
Records: 10  Duplicates: 0  Warnings: 0

mysql>
mysql> INSERT INTO SPJ_0129 (SNO, PNO, JNO, QTY) VALUES
    ->     (14677, 26188, 39299, 11),
    ->  (16518, 28326, 35986, 14),
    ->  (11230, 21837, 33604, 20),
    ->  (18643, 29609, 33604, 2),
    ->  (19690, 29224, 37650, 19),
    ->  (19568, 24396, 33604, 11),
    ->  (12579, 25203, 35151, 8),
    ->  (18900, 21435, 37650, 2),
    ->  (11500, 25025, 37474, 7),
    ->  (16240, 29445, 37114, 7),
    ->  (19379, 25203, 35986, 4),
    ->  (17967, 27083, 33104, 1),
    ->  (10070, 25212, 35986, 12),
    ->  (11859, 28842, 34872, 6),
    ->  (18021, 25203, 34872, 9),
    ->  (16518, 28631, 31438, 12),
    ->  (17100, 26749, 37650, 16),
    ->  (15739, 23187, 35151, 7),
    ->  (15525, 26383, 37114, 17),
    ->  (19187, 20876, 33604, 9),
    ->     (18900, 26383, 35986, 13),
    ->     (18900, 26383, 31438, 1),
    ->     (18900, 26383, 39299, 18),
    ->     (18900, 26383, 37650, 1),
    ->     (18900, 26383, 35151, 19),
    ->     (18900, 26383, 37114, 11),
    ->     (18900, 26383, 37474, 7),
    ->     (18900, 26383, 34872, 1),
    ->     (18900, 26383, 33604, 9),
    ->     (18900, 26383, 33104, 16);
Query OK, 30 rows affected (0.01 sec)
Records: 30  Duplicates: 0  Warnings: 0
```

### Queries:
#### 1. Get <span style = "font-family:Input">SNO</span> values for suppliers who supply project <span style = "font-family:Input">j1</span>.

##### Query:
```sql
SELECT SPJ.SNO AS "Supplier Number"
FROM PROJECT_0129 J, SPJ_0129 SPJ
WHERE SPJ.JNO = J.JNO AND J.JNAME="j1";
```

##### Output:
```
mysql> SELECT SPJ.SNO AS "Supplier Number"
    -> FROM PROJECT_0129 J, SPJ_0129 SPJ
    -> WHERE SPJ.JNO = J.JNO AND J.JNAME="j1";
+-----------------+
| Supplier Number |
+-----------------+
|           16518 |
|           19379 |
|           10070 |
|           18900 |
+-----------------+
4 rows in set (0.00 sec)
```

#### 2. Get <span style = "font-family:Input">SNO</span> values for suppliers who supply project <span style = "font-family:Input">j1</span> with part <span style = "font-family:Input">p1</span>.

##### Query:
```sql
SELECT SPJ.SNO AS "Supplier Number"
FROM PARTS_0129 P, PROJECT_0129 J, SPJ_0129 SPJ
WHERE SPJ.PNO = P.PNO AND SPJ.JNO = J.JNO AND P.PNAME = "p1" AND J.JNAME = "j1";
```

##### Output:
```
mysql> SELECT SPJ.SNO AS "Supplier Number"
    -> FROM PARTS_0129 P, PROJECT_0129 J, SPJ_0129 SPJ
    -> WHERE SPJ.PNO = P.PNO AND SPJ.JNO = J.JNO AND P.PNAME = "p1" AND J.JNAME = "j1";
+-----------------+
| Supplier Number |
+-----------------+
|           19379 |
+-----------------+
1 row in set (0.00 sec)
```

#### 3. Get <span style = "font-family:Input">JNAME</span> values for projects supplied by supplier <span style = "font-family:Input">s1</span>.

##### Query:
```sql
SELECT J.JNAME AS "Project Name"
FROM SUPPLIER_0129 S, PROJECT_0129 J, SPJ_0129 SPJ
WHERE S.SNAME = "s1" AND SPJ.SNO = S.SNO AND SPJ.JNO = J.JNO;
```

##### Output:
```
mysql> SELECT J.JNAME AS "Project Name"
    -> FROM SUPPLIER_0129 S, PROJECT_0129 J, SPJ_0129 SPJ
    -> WHERE S.SNAME = "s1" AND SPJ.SNO = S.SNO AND SPJ.JNO = J.JNO;
+--------------+
| Project Name |
+--------------+
| j5           |
+--------------+
1 row in set (0.00 sec)
```

#### 4. Get <span style = "font-family:Input">COLOR</span> values for parts supplied by supplier <span style = "font-family:Input">s1</span>.

##### Query:
```sql
SELECT P.COLOR AS "Part Color"
FROM SUPPLIER_0129 S, PARTS_0129 P, SPJ_0129 SPJ
WHERE S.SNAME = "s1" AND SPJ.PNO = P.PNO AND SPJ.SNO = S.SNO;
```

##### Output:
```
mysql> SELECT P.COLOR AS "Part Color"
    -> FROM SUPPLIER_0129 S, PARTS_0129 P, SPJ_0129 SPJ
    -> WHERE S.SNAME = "s1" AND SPJ.PNO = P.PNO AND SPJ.SNO = S.SNO;
+------------+
| Part Color |
+------------+
| Blue       |
+------------+
1 row in set (0.00 sec)
```

#### 5. Get <span style = "font-family:Input">PNO</span> values for parts supplied to any project in <span style = "font-family:Input">London</span>.

##### Query:
```sql
SELECT SPJ.PNO AS "Part Number"
FROM PROJECT_0129 J, SPJ_0129 SPJ
WHERE J.CITY = "London" AND SPJ.JNO = J.JNO;
```

##### Output:
```
mysql> SELECT SPJ.PNO AS "Part Number"
    -> FROM PROJECT_0129 J, SPJ_0129 SPJ
    -> WHERE J.CITY = "London" AND SPJ.JNO = J.JNO;
+-------------+
| Part Number |
+-------------+
|       21837 |
|       29609 |
|       24396 |
|       29445 |
|       28631 |
|       26383 |
|       20876 |
|       26383 |
|       26383 |
|       26383 |
+-------------+
10 rows in set (0.00 sec)
```

#### 6. Get <span style = "font-family:Input">SNO</span> values for suppliers who supply project <span style = "font-family:Input">j1</span> with a <span style = "font-family:Input">Red</span> part.

##### Query:
```sql
SELECT SPJ.SNO AS "Supplier Number"
FROM PARTS_0129 P, PROJECT_0129 J, SPJ_0129 SPJ
WHERE
    P.COLOR = "Red"
    AND J.JNAME = "j1"
    AND SPJ.PNO = P.PNO
    AND SPJ.JNO = J.JNO;
```

##### Output:
```
mysql> SELECT SPJ.SNO AS "Supplier Number"
    -> FROM PARTS_0129 P, PROJECT_0129 J, SPJ_0129 SPJ
    -> WHERE
    ->     P.COLOR = "Red"
    ->     AND J.JNAME = "j1"
    ->     AND SPJ.PNO = P.PNO
    ->     AND SPJ.JNO = J.JNO;
+-----------------+
| Supplier Number |
+-----------------+
|           16518 |
+-----------------+
1 row in set (0.00 sec)
```

#### 7. Get <span style = "font-family:Input">SNO</span> values for suppliers who supply a <span style = "font-family:Input">London</span> or <span style = "font-family:Input">Paris</span> project with a <span style = "font-family:Input">Red</span> part.

##### Query:
```sql
SELECT SPJ.SNO AS "Supplier Number"
FROM PARTS_0129 P, PROJECT_0129 J, SPJ_0129 SPJ
WHERE
    P.COLOR = "Red"
    AND (J.CITY = "London" OR J.CITY = "Paris")
    AND SPJ.PNO = P.PNO
    AND SPJ.JNO = J.JNO;
```

##### Output:
```
mysql> SELECT SPJ.SNO AS "Supplier Number"
    -> FROM PARTS_0129 P, PROJECT_0129 J, SPJ_0129 SPJ
    -> WHERE
    ->     P.COLOR = "Red"
    ->     AND (J.CITY = "London" OR J.CITY = "Paris")
    ->     AND SPJ.PNO = P.PNO
    ->     AND SPJ.JNO = J.JNO;
+-----------------+
| Supplier Number |
+-----------------+
|           16518 |
|           19187 |
+-----------------+
2 rows in set (0.00 sec)
```

#### 8. Get <span style = "font-family:Input">PNO</span> values for parts supplied to any project by a supplier in the same city.

##### Query:
```sql
SELECT P.PNO AS "Part Number"
FROM SUPPLIER_0129 S, PARTS_0129 P, PROJECT_0129 J, SPJ_0129 SPJ
WHERE
    S.CITY = J.CITY
    AND SPJ.SNO = S.SNO
    AND SPJ.PNO = P.PNO
    AND SPJ.JNO = J.JNO;
```

##### Output:
```
mysql> SELECT P.PNO AS "Part Number"
    -> FROM SUPPLIER_0129 S, PARTS_0129 P, PROJECT_0129 J, SPJ_0129 SPJ
    -> WHERE
    ->     S.CITY = J.CITY
    ->     AND SPJ.SNO = S.SNO
    ->     AND SPJ.PNO = P.PNO
    ->     AND SPJ.JNO = J.JNO;
+-------------+
| Part Number |
+-------------+
|       26188 |
|       25212 |
|       28631 |
|       26383 |
+-------------+
4 rows in set (0.00 sec)
```

#### 9. Get <span style = "font-family:Input">PNO</span> values for parts supplied to any project in <span style = "font-family:Input">London</span> by a supplier in <span style = "font-family:Input">London</span>.

##### Query:
```sql
SELECT P.PNO AS "Part Number"
FROM SUPPLIER_0129 S, PARTS_0129 P, PROJECT_0129 J, SPJ_0129 SPJ
WHERE
    S.CITY = J.CITY
    AND S.CITY = "London"
    AND SPJ.SNO = S.SNO
    AND SPJ.PNO = P.PNO
    AND SPJ.JNO = J.JNO;
```

##### Output:
```
mysql> SELECT P.PNO AS "Part Number"
    -> FROM SUPPLIER_0129 S, PARTS_0129 P, PROJECT_0129 J, SPJ_0129 SPJ
    -> WHERE
    ->     S.CITY = J.CITY
    ->     AND S.CITY = "London"
    ->     AND SPJ.SNO = S.SNO
    ->     AND SPJ.PNO = P.PNO
    ->     AND SPJ.JNO = J.JNO;
+-------------+
| Part Number |
+-------------+
|       28631 |
+-------------+
1 row in set (0.00 sec)
```

#### 10. Get <span style = "font-family:Input">JNO</span> values for projects supplied by at least one supplier not in the same city.

##### Query:
```sql
SELECT DISTINCT J.JNO AS "Project Number"
FROM SUPPLIER_0129 S, PROJECT_0129 J, SPJ_0129 SPJ
WHERE
    S.CITY <> J.CITY
    AND SPJ.SNO = S.SNO
    AND SPJ.JNO = J.JNO
ORDER BY J.JNAME;
```

##### Output:
```
mysql> SELECT DISTINCT J.JNO AS "Project Number"
    -> FROM SUPPLIER_0129 S, PROJECT_0129 J, SPJ_0129 SPJ
    -> WHERE
    ->     S.CITY <> J.CITY
    ->     AND SPJ.SNO = S.SNO
    ->     AND SPJ.JNO = J.JNO
    -> ORDER BY J.JNAME;
+----------------+
| Project Number |
+----------------+
|          35986 |
|          33104 |
|          31438 |
|          39299 |
|          37650 |
|          35151 |
|          37114 |
|          37474 |
|          34872 |
|          33604 |
+----------------+
10 rows in set (0.00 sec)
```

#### 11. Get all pairs of <span style = "font-family:Input">CITY</span> values such that a supplier in the first city supplies a project in the second city.

##### Query:
```sql
SELECT S.CITY AS "Supplier City", J.CITY AS "Project City"
FROM SUPPLIER_0129 S, PROJECT_0129 J, SPJ_0129 SPJ
WHERE
    SPJ.SNO = S.SNO
    AND SPJ.JNO = J.JNO
GROUP BY S.CITY, J.CITY;
```

##### Output:
```
mysql> SELECT S.CITY AS "Supplier City", J.CITY AS "Project City"
    -> FROM SUPPLIER_0129 S, PROJECT_0129 J, SPJ_0129 SPJ
    -> WHERE
    ->     SPJ.SNO = S.SNO
    ->     AND SPJ.JNO = J.JNO
    -> GROUP BY S.CITY, J.CITY;
+---------------+--------------+
| Supplier City | Project City |
+---------------+--------------+
| Berlin        | Berlin       |
| London        | Paris        |
| Vienna        | London       |
| Madrid        | Paris        |
| Madrid        | London       |
| Paris         | Berlin       |
| Paris         | Vienna       |
| Vienna        | Paris        |
| Madrid        | Vienna       |
| Paris         | Paris        |
| London        | Madrid       |
| Berlin        | Madrid       |
| London        | London       |
| Madrid        | Berlin       |
| Paris         | London       |
| Madrid        | Madrid       |
+---------------+--------------+
16 rows in set (0.00 sec)
```

#### 12. Get <span style = "font-family:Input">SNO</span> values for suppliers who supply the same part to all projects.

##### Query:
```sql
SELECT S.SNO AS "Supplier Number"
FROM SUPPLIER_0129 S
WHERE EXISTS (
    SELECT P.*  -- Gives parts which are not included in the next table, therefore giving table with parts which are included in all tables
    FROM PARTS_0129 P
    WHERE NOT EXISTS (
        SELECT J.*      -- Gives projects which are not included in the joined table
        FROM PROJECT_0129 J
        WHERE NOT EXISTS (
            SELECT SPJ.* -- Joins spj, j, p and s, gives all values from spj
            FROM SPJ_0129 SPJ
            WHERE
                SPJ.JNO = J.JNO
                AND SPJ.PNO = P.PNO
                AND SPJ.SNO = S.SNO
        )
    )
);
```

##### Output:
```
mysql> SELECT S.SNO AS "Supplier Number"
    -> FROM SUPPLIER_0129 S
    -> WHERE EXISTS (
    ->     SELECT P.*  -- Gives parts which are not included in the next table, therefore giving table with parts which are included in all tables
    ->     FROM PARTS_0129 P
    ->     WHERE NOT EXISTS (
    ->         SELECT J.*      -- Gives projects which are not included in the joined table
    ->         FROM PROJECT_0129 J
    ->         WHERE NOT EXISTS (
    ->             SELECT SPJ.* -- Joins spj, j, p and s, gives all values from spj
    ->             FROM SPJ_0129 SPJ
    ->             WHERE
    ->                 SPJ.JNO = J.JNO
    ->                 AND SPJ.PNO = P.PNO
    ->                 AND SPJ.SNO = S.SNO
    ->         )
    ->     )
    -> );
+-----------------+
| Supplier Number |
+-----------------+
|           18900 |
+-----------------+
1 row in set (0.03 sec)
```

#### 13. Get <span style = "font-family:Input">PNO</span> values for parts supplied to all projects in <span style = "font-family:Input">London</span>.

##### Query:
```sql
SELECT SPJ.PNO AS "Part Number"
FROM PROJECT_0129 J, SPJ_0129 SPJ
WHERE J.CITY = "London" AND SPJ.JNO = J.JNO;
```

##### Output:
```
mysql> SELECT SPJ.PNO AS "Part Number"
    -> FROM PROJECT_0129 J, SPJ_0129 SPJ
    -> WHERE J.CITY = "London" AND SPJ.JNO = J.JNO;
+-------------+
| Part Number |
+-------------+
|       21837 |
|       29609 |
|       24396 |
|       29445 |
|       28631 |
|       26383 |
|       20876 |
|       26383 |
|       26383 |
|       26383 |
+-------------+
10 rows in set (0.00 sec)
```

#### 14. Get <span style = "font-family:Input">SNAME</span> values for suppliers who supply at least one <span style = "font-family:Input">Red</span> part to any project.

##### Query:
```sql
SELECT
    S.SNAME AS "Supplier Name",
    P.COLOR AS "Part Color",
    SPJ.JNO AS "Project Number"
FROM SUPPLIER_0129 S, PARTS_0129 P, SPJ_0129 SPJ
WHERE P.COLOR = "Red" AND SPJ.SNO = S.SNO AND SPJ.PNO = P.PNO;
```

##### Output:
```
mysql> SELECT
    ->     S.SNAME AS "Supplier Name",
    ->     P.COLOR AS "Part Color",
    ->     SPJ.JNO AS "Project Number"
    -> FROM SUPPLIER_0129 S, PARTS_0129 P, SPJ_0129 SPJ
    -> WHERE P.COLOR = "Red" AND SPJ.SNO = S.SNO AND SPJ.PNO = P.PNO;
+---------------+------------+----------------+
| Supplier Name | Part Color | Project Number |
+---------------+------------+----------------+
| s3            | Red        |          33604 |
| s19           | Red        |          35151 |
| s13           | Red        |          37474 |
| s2            | Red        |          39299 |
| s14           | Red        |          35986 |
+---------------+------------+----------------+
5 rows in set (0.00 sec)
```

#### 15. Get total quantity of part <span style = "font-family:Input">p1</span> supplied by supplier <span style = "font-family:Input">s1</span>.

##### Query:
```sql
SELECT SUM(S1P1.S1P1QTY) AS "Total Quantity"
FROM (
    SELECT SPJ.QTY AS S1P1QTY
    FROM SUPPLIER_0129 S, PARTS_0129 P, SPJ_0129 SPJ
    WHERE
        S.SNAME = "s1"
        AND P.PNAME = "p1"
        AND SPJ.SNO = S.SNO
        AND SPJ.PNO = P.PNO
) S1P1;
```

##### Output:
```
mysql> SELECT SUM(S1P1.S1P1QTY) AS "Total Quantity"
    -> FROM (
    ->     SELECT SPJ.QTY AS S1P1QTY
    ->     FROM SUPPLIER_0129 S, PARTS_0129 P, SPJ_0129 SPJ
    ->     WHERE
    ->         S.SNAME = "s1"
    ->         AND P.PNAME = "p1"
    ->         AND SPJ.SNO = S.SNO
    ->         AND SPJ.PNO = P.PNO
    -> ) S1P1;
+----------------+
| Total Quantity |
+----------------+
|              8 |
+----------------+
1 row in set (0.00 sec)
```

#### 16. Get the total number of projects supplied by supplier <span style = "font-family:Input">s3</span>.

##### Query:
```sql
SELECT COUNT(*) AS "Number of Projects"
FROM (
    SELECT S.SNAME, P.PNAME
    FROM SUPPLIER_0129 S, PARTS_0129 P, SPJ_0129 SPJ
    WHERE
        S.SNAME = "s3"
        AND SPJ.SNO = S.SNO
        AND SPJ.PNO = P.PNO
) S3;
```

##### Output:
```
mysql> SELECT COUNT(*) AS "Number of Projects"
    -> FROM (
    ->     SELECT S.SNAME, P.PNAME
    ->     FROM SUPPLIER_0129 S, PARTS_0129 P, SPJ_0129 SPJ
    ->     WHERE
    ->         S.SNAME = "s3"
    ->         AND SPJ.SNO = S.SNO
    ->         AND SPJ.PNO = P.PNO
    -> ) S3;
+--------------------+
| Number of Projects |
+--------------------+
|                  1 |
+--------------------+
1 row in set (0.00 sec)
```

#### 17. Change color of all <span style = "font-family:Input">Red</span> parts to <span style = "font-family:Input">Orange</span>.

##### Query:
```sql
SELECT
    P.PNO AS "Part Number",
    P.PNAME AS "Part Name",
    P.COLOR AS "Part Color"
FROM PARTS_0129 P;

UPDATE PARTS_0129 P
SET P.COLOR = "Orange"
WHERE P.COLOR = "Red";

SELECT
    P.PNO AS "Part Number",
    P.PNAME AS "Part Name",
    P.COLOR AS "Part Color"
FROM PARTS_0129 P;
```

##### Output:
```
mysql> SELECT
    ->     P.PNO AS "Part Number",
    ->     P.PNAME AS "Part Name",
    ->     P.COLOR AS "Part Color"
    -> FROM PARTS_0129 P;
+-------------+-----------+------------+
| Part Number | Part Name | Part Color |
+-------------+-----------+------------+
|       20876 | p17       | Red        |
|       21435 | p4        | Black      |
|       21837 | p3        | Blue       |
|       23187 | p10       | Red        |
|       24396 | p14       | Black      |
|       25025 | p12       | Red        |
|       25203 | p1        | Blue       |
|       25212 | p8        | Blue       |
|       26188 | p19       | Red        |
|       26383 | p5        | Yellow     |
|       26749 | p18       | Green      |
|       27083 | p6        | Green      |
|       28173 | p15       | Blue       |
|       28326 | p2        | Red        |
|       28631 | p7        | Green      |
|       28842 | p13       | Black      |
|       29224 | p20       | Green      |
|       29445 | p9        | Black      |
|       29457 | p16       | Yellow     |
|       29609 | p11       | Blue       |
+-------------+-----------+------------+
20 rows in set (0.00 sec)

mysql>
mysql> UPDATE PARTS_0129 P
    -> SET P.COLOR = "Orange"
    -> WHERE P.COLOR = "Red";
Query OK, 5 rows affected (0.00 sec)
Rows matched: 5  Changed: 5  Warnings: 0

mysql>
mysql> SELECT
    ->     P.PNO AS "Part Number",
    ->     P.PNAME AS "Part Name",
    ->     P.COLOR AS "Part Color"
    -> FROM PARTS_0129 P;
+-------------+-----------+------------+
| Part Number | Part Name | Part Color |
+-------------+-----------+------------+
|       20876 | p17       | Orange     |
|       21435 | p4        | Black      |
|       21837 | p3        | Blue       |
|       23187 | p10       | Orange     |
|       24396 | p14       | Black      |
|       25025 | p12       | Orange     |
|       25203 | p1        | Blue       |
|       25212 | p8        | Blue       |
|       26188 | p19       | Orange     |
|       26383 | p5        | Yellow     |
|       26749 | p18       | Green      |
|       27083 | p6        | Green      |
|       28173 | p15       | Blue       |
|       28326 | p2        | Orange     |
|       28631 | p7        | Green      |
|       28842 | p13       | Black      |
|       29224 | p20       | Green      |
|       29445 | p9        | Black      |
|       29457 | p16       | Yellow     |
|       29609 | p11       | Blue       |
+-------------+-----------+------------+
20 rows in set (0.00 sec)
```

#### 18. Get <span style = "font-family:Input">SNAME</span> values for suppliers who supply to both projects <span style = "font-family:Input">j1</span> and <span style = "font-family:Input">j2</span>.

##### Query:
```sql
SELECT S1.SNAME AS "Supplier Name"
FROM SUPPLIER_0129 S1, PROJECT_0129 J1, SPJ_0129 SPJ1
WHERE
    S1.SNAME IN (
        SELECT S2.SNAME
        FROM SUPPLIER_0129 S2, PROJECT_0129 J2, SPJ_0129 SPJ2
        WHERE
            J2.JNAME = "j1"
            AND S2.SNAME = S2.SNAME
            AND SPJ2.SNO = S2.SNO
            AND SPJ2.JNO = J2.JNO
    )
    AND J1.JNAME = "j2"
    AND SPJ1.SNO = S1.SNO
    AND SPJ1.JNO = J1.JNO;
```

##### Output:
```
mysql> SELECT S1.SNAME AS "Supplier Name"
    -> FROM SUPPLIER_0129 S1, PROJECT_0129 J1, SPJ_0129 SPJ1
    -> WHERE
    ->     S1.SNAME IN (
    ->         SELECT S2.SNAME
    ->         FROM SUPPLIER_0129 S2, PROJECT_0129 J2, SPJ_0129 SPJ2
    ->         WHERE
    ->             J2.JNAME = "j1"
    ->             AND S2.SNAME = S2.SNAME
    ->             AND SPJ2.SNO = S2.SNO
    ->             AND SPJ2.JNO = J2.JNO
    ->     )
    ->     AND J1.JNAME = "j2"
    ->     AND SPJ1.SNO = S1.SNO
    ->     AND SPJ1.JNO = J1.JNO;
+---------------+
| Supplier Name |
+---------------+
| s14           |
| s16           |
+---------------+
2 rows in set (0.00 sec)
```

#### 19. Get all <span style = "font-family:Input">CITY</span>, <span style = "font-family:Input">PNO</span>, <span style = "font-family:Input">CITY</span> triples such that a supplier in the first city supplies the specified part to a project in the second city.

##### Query:
```sql
SELECT
    S.CITY AS "Supplier City",
    P.PNO AS "Project Number",
    J.CITY AS "Project City"
FROM SUPPLIER_0129 S, PARTS_0129 P, PROJECT_0129 J, SPJ_0129 SPJ
WHERE SPJ.SNO = S.SNO AND SPJ.PNO = P.PNO AND SPJ.JNO = J.JNO;
```

##### Output:
```
mysql> SELECT
    ->     S.CITY AS "Supplier City",
    ->     P.PNO AS "Project Number",
    ->     J.CITY AS "Project City"
    -> FROM SUPPLIER_0129 S, PARTS_0129 P, PROJECT_0129 J, SPJ_0129 SPJ
    -> WHERE SPJ.SNO = S.SNO AND SPJ.PNO = P.PNO AND SPJ.JNO = J.JNO;
+---------------+----------------+--------------+
| Supplier City | Project Number | Project City |
+---------------+----------------+--------------+
| Berlin        |          26188 | Berlin       |
| London        |          28326 | Paris        |
| Vienna        |          21837 | London       |
| Vienna        |          29609 | London       |
| Madrid        |          29224 | Paris        |
| Madrid        |          24396 | London       |
| Paris         |          25203 | Berlin       |
| Madrid        |          21435 | Paris        |
| Paris         |          25025 | Vienna       |
| Madrid        |          29445 | London       |
| Vienna        |          25203 | Paris        |
| Madrid        |          27083 | Vienna       |
| Paris         |          25212 | Paris        |
| London        |          28842 | Madrid       |
| Berlin        |          25203 | Madrid       |
| London        |          28631 | London       |
| Madrid        |          26749 | Paris        |
| Madrid        |          23187 | Berlin       |
| Madrid        |          26383 | London       |
| Paris         |          20876 | London       |
| Madrid        |          26383 | Paris        |
| Madrid        |          26383 | London       |
| Madrid        |          26383 | Berlin       |
| Madrid        |          26383 | Paris        |
| Madrid        |          26383 | Berlin       |
| Madrid        |          26383 | London       |
| Madrid        |          26383 | Vienna       |
| Madrid        |          26383 | Madrid       |
| Madrid        |          26383 | London       |
| Madrid        |          26383 | Vienna       |
+---------------+----------------+--------------+
30 rows in set (0.00 sec)
```

#### 20. Get <span style = "font-family:Input">JNAMES</span> for those projects which are supplied by supplier <span style = "font-family:Input">XYZ</span>.

##### Query:
```sql
DELIMITER &&
CREATE PROCEDURE JNAMES_GEN (IN SUPPLIER_NAME CHAR(2))
BEGIN
    SELECT J.JNAME AS "Project Name", S.SNAME AS "Supplier Name"
    FROM SUPPLIER_0129 S, PROJECT_0129 J, SPJ_0129 SPJ
    WHERE S.SNAME = SUPPLIER_NAME AND SPJ.SNO = S.SNO AND SPJ.JNO = J.JNO;
END &&
DELIMITER ;

CALL JNAMES_GEN("s1");
CALL JNAMES_GEN("s2");
CALL JNAMES_GEN("s3");
```

##### Output:
```
mysql> DELIMITER &&
mysql> CREATE PROCEDURE JNAMES_GEN (IN SUPPLIER_NAME CHAR(2))
    -> BEGIN
    ->     SELECT J.JNAME AS "Project Name", S.SNAME AS "Supplier Name"
    ->     FROM SUPPLIER_0129 S, PROJECT_0129 J, SPJ_0129 SPJ
    ->     WHERE S.SNAME = SUPPLIER_NAME AND SPJ.SNO = S.SNO AND SPJ.JNO = J.JNO;
    -> END &&
Query OK, 0 rows affected (0.01 sec)

mysql> DELIMITER ;
mysql>
mysql> CALL JNAMES_GEN("s1");
+--------------+---------------+
| Project Name | Supplier Name |
+--------------+---------------+
| j5           | s1            |
+--------------+---------------+
1 row in set (0.00 sec)

Query OK, 0 rows affected (0.00 sec)

mysql> CALL JNAMES_GEN("s2");
+--------------+---------------+
| Project Name | Supplier Name |
+--------------+---------------+
| j3           | s2            |
+--------------+---------------+
1 row in set (0.00 sec)

Query OK, 0 rows affected (0.00 sec)

mysql> CALL JNAMES_GEN("s3");
+--------------+---------------+
| Project Name | Supplier Name |
+--------------+---------------+
| j9           | s3            |
+--------------+---------------+
1 row in set (0.00 sec)

Query OK, 0 rows affected (0.01 sec)
```

---
## Q3.
### Create the required tables
```
Department
    DEPT_NO
    DEPT_NAME

Employee
    E_ID
    ENAME
    SALARY
    HIREDATE
    LOC
    MGR_E_ID
    JOB
    GRADE
    DEPT_NO
```

##### Query:
```sql
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
```

##### Output:
```
mysql> -- Table Creation
mysql> CREATE TABLE Department_0129 (
    ->     DEPT_NO     INTEGER(2)  NOT NULL    UNIQUE  PRIMARY KEY,
    ->     DEPT_NAME   VARCHAR(10) UNIQUE
    -> );
Query OK, 0 rows affected, 1 warning (0.06 sec)

mysql>
mysql> CREATE TABLE Employee_0129 (
    ->     E_ID        INTEGER(4)  NOT NULL    UNIQUE  PRIMARY KEY,
    ->     ENAME       VARCHAR(20),
    ->     SALARY      INTEGER(12),
    ->     HIREDATE    DATE,
    ->     LOC         VARCHAR(20),
    ->     MGR_E_ID    INTEGER(4),
    ->     JOB         VARCHAR(10),
    ->     GRADE       CHAR(10),
    ->     DEPT_NO     INTEGER(2),
    ->
    ->     CONSTRAINT
    ->         FOREIGN KEY(DEPT_NO)
    ->         REFERENCES Department_0129(DEPT_NO)
    ->         ON DELETE CASCADE
    -> );
Query OK, 0 rows affected, 4 warnings (0.10 sec)

mysql>
mysql> -- Data Entry
mysql> INSERT INTO Department_0129 (DEPT_NO, DEPT_NAME) VALUES
    ->     (14, "Systems"),
    ->     (93, "Marketing"),
    ->     (89, "HR"),
    ->     (18, "Research"),
    ->     (37, "Frontend"),
    ->     (47, "Backend"),
    ->     (78, "Maint.");
Query OK, 7 rows affected (0.01 sec)
Records: 7  Duplicates: 0  Warnings: 0

mysql>
mysql> INSERT INTO Employee_0129 (
    ->     E_ID,
    ->     ENAME,
    ->     SALARY,
    ->     HIREDATE,
    ->     LOC,
    ->     MGR_E_ID,
    ->     JOB,
    ->     GRADE,
    ->     DEPT_NO
    -> ) VALUES
    ->     (8908, "Oscar Reid", 12000, "1984-12-01", "New York", 8908, "Manager", "B", 37),
    ->     (6267, "Dean Allen", 25000, "1984-12-11", "Boston", 6267, "Manager", "B", 93),
    ->     (5669, "Sonja Bush", 18000, "1982-06-12", "Seattle", 5669, "Manager", "B", 18),
    ->     (9488, "Christina Harmon", 12000, "1981-03-30", "Dallas", 8908, "Jr. Emp.", "A", 37),
    ->     (1318, "Terry Fleming", 15000, "1981-09-08", "Dallas", 8908, "Officer", "B", 37),
    ->     (6514, "Isabel Taylor", 16000, "1983-07-07", "New York", 5669, "Jr. Emp.", "B", 18),
    ->     (8038, "Tom Morris", 12000, "1981-04-27", "San Francisco", 6267, "Officer", "B", 93),
    ->     (7248, "Marta Pierce", 20000, "1981-05-02", "Seattle", 7248, "Manager", "B", 47),
    ->     (1236, "Amber Howard", 22000, "1982-01-19", "San Francisco", 7248, "Officer", "B", 47),
    ->     (6485, "Harvey Klein", 19000, "1981-05-29", "Dallas", 5669, "Officer", "B", 18),
    ->     (2006, "Alexander Barnes", 18000, "1984-10-14", "Boston", 7248, "Officer", "B", 47),
    ->     (8584, "Vernon Bennett", 12000, "1983-11-30", "Dallas", 6267, "Clerk", "A", 93),
    ->     (6199, "Beth Jordan", 11000, "1982-12-17", "Boston", 5669, "Jr. Emp.", "C", 18),
    ->     (6543, "Ramon Russell", 16000, "1984-09-13", "Dallas", 5669, "Officer", "C", 18),
    ->     (3634, "Chad Bowen", 17000, "1984-11-20", "New Orleans", 8908, "Officer", "A", 37),
    ->     (5306, "Boyd Watkins", 6000, "1983-11-01", "Dallas", 6267, "Officer", "C", 93),
    ->     (8468, "Pat Gardner", 10000, "1982-08-21", "Boston", 5669, "Jr. Emp.", "B", 18),
    ->     (4255, "Wayne Myers", 24000, "1983-03-06", "New Orleans", 6267, "Clerk", "A", 93),
    ->     (6505, "Donnie Robertson", 23000, "1984-04-05", "San Francisco", 5050, "Jr. Emp.", "B", 89),
    ->     (9626, "Clarence Hamilton", 9000, "1982-07-19", "Seattle", 8908, "Officer", "A", 37),
    ->     (5952, "Kristopher Douglas", 11000, "1981-03-31", "San Francisco", 6267, "Jr. Emp.", "B", 93),
    ->     (4208, "Caroline Evans", 13000, "1984-02-16", "Boston", 5669, "Clerk", "A", 18),
    ->     (1336, "Stephen Lane", 7000, "1983-01-15", "San Francisco", 8908, "Jr. Emp.", "C", 37),
    ->     (6982, "Ellis Brady", 14000, "1981-06-22", "San Francisco", 6267, "Officer", "B", 93),
    ->     (5582, "Victor Boyd", 8000, "1982-06-06", "Boston", 8908, "Jr. Emp.", "A", 37),
    ->     (3733, "Bertha Pearson", 7000, "1981-11-20", "Seattle", 3151, "Jr. Emp.", "A", 14),
    ->     (7827, "Jill Powers", 16000, "1981-04-25", "New Orleans", 3151, "Jr. Emp.", "C", 14),
    ->     (1990, "Sophia Spencer", 21000, "1982-01-14", "Boston", 5050, "Clerk", "B", 89),
    ->     (3074, "Jose Santos", 16000, "1984-12-20", "Dallas", 6267, "Officer", "C", 93),
    ->     (5142, "Gloria Peterson", 8000, "1983-04-03", "Boston", 6267, "Clerk", "C", 93),
    ->     (8593, "Bruce Mitchell", 14000, "1981-09-09", "Seattle", 7248, "Jr. Emp.", "C", 47),
    ->     (5344, "Lee Robbins", 19000, "1982-05-10", "Boston", 6267, "Officer", "B", 93),
    ->     (1242, "Yvette Mcbride", 21000, "1982-03-22", "New York", 3151, "Officer", "A", 14),
    ->     (9845, "Cecilia Hammond", 20000, "1982-12-26", "Seattle", 5669, "Jr. Emp.", "A", 18),
    ->     (6028, "Lyle Daniel", 21000, "1982-01-18", "New York", 6267, "Clerk", "A", 93),
    ->     (7424, "Adrian Long", 8000, "1982-05-30", "Seattle", 7248, "Officer", "C", 47),
    ->     (2846, "Eddie Greer", 8000, "1981-02-27", "New York", 5669, "Clerk", "C", 18),
    ->     (3151, "Roger Mccormick", 22000, "1983-01-23", "Seattle", 3151, "Manager", "C", 14),
    ->     (5050, "Emanuel Barker", 10000, "1982-04-06", "San Francisco", 5050, "Manager", "B", 89),
    ->     (4269, "Henry Barber", 19000, "1983-03-18", "San Francisco", 7248, "Jr. Emp.", "B", 47),
    ->     (7962, "Carolyn Graves", 16000, "1981-11-08", "Dallas", 7248, "Officer", "B", 47),
    ->     (7754, "Marian Lucas", 20000, "1981-09-29", "Seattle", 5050, "Jr. Emp.", "B", 89),
    ->     (9546, "Wilma Wilkins", 14000, "1982-04-15", "New Orleans", 6267, "Jr. Emp.", "B", 93),
    ->     (7061, "Bryant Stevens", 13000, "1984-04-06", "Seattle", 3151, "Clerk", "B", 14),
    ->     (5891, "Angelina Maxwell", 9000, "1982-05-22", "Dallas", 5669, "Officer", "A", 18),
    ->     (5056, "Darin Alexander", 10000, "1983-03-24", "San Francisco", 5050, "Manager", "B", 89),
    ->     (1022, "Carlos Wise", 11000, "1983-04-20", "New York", 8908, "Jr. Emp.", "C", 37),
    ->     (4704, "Traci Jones", 20000, "1984-07-05", "Dallas", 8908, "Officer", "C", 37),
    ->     (4528, "Whitney Collier", 12000, "1981-11-17", "New Orleans", 6267, "Officer", "C", 93),
    ->     (7655, "Beverly Holt", 22000, "1982-07-04", "Dallas", 5669, "Officer", "A", 18);
Query OK, 50 rows affected (0.01 sec)
Records: 50  Duplicates: 0  Warnings: 0
```

### Queries:
#### 1. Display each employee name and hire date of systems department.

##### Query:
```sql
SELECT
    E.ENAME AS "Employee Name",
    E.HIREDATE AS "Hiring Date",
    D.DEPT_NAME AS "Department Name"
FROM Employee_0129 E, Department_0129 D
WHERE E.DEPT_NO = D.DEPT_NO AND D.DEPT_NAME = "Systems";
```

##### Output:
```
mysql> -- 1. Display each employee and hire date of systems department
mysql> SELECT
    ->     E.ENAME AS "Employee Name",
    ->     E.HIREDATE AS "Hiring Date",
    ->     D.DEPT_NAME AS "Department Name"
    -> FROM Employee_0129 E, Department_0129 D
    -> WHERE E.DEPT_NO = D.DEPT_NO AND D.DEPT_NAME = "Systems";
+-----------------+-------------+-----------------+
| Employee Name   | Hiring Date | Department Name |
+-----------------+-------------+-----------------+
| Yvette Mcbride  | 1982-03-22  | Systems         |
| Roger Mccormick | 1983-01-23  | Systems         |
| Bertha Pearson  | 1981-11-20  | Systems         |
| Bryant Stevens  | 1984-04-06  | Systems         |
| Jill Powers     | 1981-04-25  | Systems         |
+-----------------+-------------+-----------------+
5 rows in set (0.00 sec)
```

#### 2. Write query to calculate length of service of each employee.

##### Query:
```sql
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
```

##### Output:
```
mysql> SELECT
    ->     E.ENAME AS "Employee Name",
    ->     E.HIREDATE AS "Hire Date",
    ->     CONCAT(
    ->         YEAR(FROM_DAYS(DATEDIFF(DATE(NOW()), E.HIREDATE))),
    ->         " Years, ",
    ->         MONTH(FROM_DAYS(DATEDIFF(DATE(NOW()), E.HIREDATE))),
    ->         " Months, ",
    ->         DAY(FROM_DAYS(DATEDIFF(DATE(NOW()), E.HIREDATE))),
    ->         " Days"
    ->     ) AS "Length of Service"
    -> FROM Employee_0129 E;
+--------------------+------------+------------------------------+
| Employee Name      | Hire Date  | Length of Service            |
+--------------------+------------+------------------------------+
| Carlos Wise        | 1983-04-20 | 39 Years, 6 Months, 6 Days   |
| Amber Howard       | 1982-01-19 | 40 Years, 9 Months, 4 Days   |
| Yvette Mcbride     | 1982-03-22 | 40 Years, 7 Months, 4 Days   |
| Terry Fleming      | 1981-09-08 | 41 Years, 1 Months, 15 Days  |
| Stephen Lane       | 1983-01-15 | 39 Years, 9 Months, 9 Days   |
| Sophia Spencer     | 1982-01-14 | 40 Years, 9 Months, 9 Days   |
| Alexander Barnes   | 1984-10-14 | 37 Years, 12 Months, 10 Days |
| Eddie Greer        | 1981-02-27 | 41 Years, 7 Months, 27 Days  |
| Jose Santos        | 1984-12-20 | 37 Years, 10 Months, 4 Days  |
| Roger Mccormick    | 1983-01-23 | 39 Years, 9 Months, 1 Days   |
| Chad Bowen         | 1984-11-20 | 37 Years, 11 Months, 3 Days  |
| Bertha Pearson     | 1981-11-20 | 40 Years, 11 Months, 3 Days  |
| Caroline Evans     | 1984-02-16 | 38 Years, 8 Months, 8 Days   |
| Wayne Myers        | 1983-03-06 | 39 Years, 7 Months, 21 Days  |
| Henry Barber       | 1983-03-18 | 39 Years, 7 Months, 9 Days   |
| Whitney Collier    | 1981-11-17 | 40 Years, 11 Months, 6 Days  |
| Traci Jones        | 1984-07-05 | 38 Years, 3 Months, 21 Days  |
| Emanuel Barker     | 1982-04-06 | 40 Years, 6 Months, 19 Days  |
| Darin Alexander    | 1983-03-24 | 39 Years, 7 Months, 3 Days   |
| Gloria Peterson    | 1983-04-03 | 39 Years, 6 Months, 23 Days  |
| Boyd Watkins       | 1983-11-01 | 38 Years, 11 Months, 23 Days |
| Lee Robbins        | 1982-05-10 | 40 Years, 5 Months, 16 Days  |
| Victor Boyd        | 1982-06-06 | 40 Years, 4 Months, 19 Days  |
| Sonja Bush         | 1982-06-12 | 40 Years, 4 Months, 13 Days  |
| Angelina Maxwell   | 1982-05-22 | 40 Years, 5 Months, 4 Days   |
| Kristopher Douglas | 1981-03-31 | 41 Years, 6 Months, 25 Days  |
| Lyle Daniel        | 1982-01-18 | 40 Years, 9 Months, 5 Days   |
| Beth Jordan        | 1982-12-17 | 39 Years, 10 Months, 8 Days  |
| Dean Allen         | 1984-12-11 | 37 Years, 10 Months, 13 Days |
| Harvey Klein       | 1981-05-29 | 41 Years, 4 Months, 27 Days  |
| Donnie Robertson   | 1984-04-05 | 38 Years, 6 Months, 20 Days  |
| Isabel Taylor      | 1983-07-07 | 39 Years, 3 Months, 20 Days  |
| Ramon Russell      | 1984-09-13 | 38 Years, 1 Months, 10 Days  |
| Ellis Brady        | 1981-06-22 | 41 Years, 4 Months, 3 Days   |
| Bryant Stevens     | 1984-04-06 | 38 Years, 6 Months, 19 Days  |
| Marta Pierce       | 1981-05-02 | 41 Years, 5 Months, 24 Days  |
| Adrian Long        | 1982-05-30 | 40 Years, 4 Months, 26 Days  |
| Beverly Holt       | 1982-07-04 | 40 Years, 3 Months, 22 Days  |
| Marian Lucas       | 1981-09-29 | 40 Years, 12 Months, 25 Days |
| Jill Powers        | 1981-04-25 | 41 Years, 5 Months, 31 Days  |
| Carolyn Graves     | 1981-11-08 | 40 Years, 11 Months, 15 Days |
| Tom Morris         | 1981-04-27 | 41 Years, 5 Months, 29 Days  |
| Pat Gardner        | 1982-08-21 | 40 Years, 2 Months, 3 Days   |
| Vernon Bennett     | 1983-11-30 | 38 Years, 10 Months, 25 Days |
| Bruce Mitchell     | 1981-09-09 | 41 Years, 1 Months, 14 Days  |
| Oscar Reid         | 1984-12-01 | 37 Years, 10 Months, 23 Days |
| Christina Harmon   | 1981-03-30 | 41 Years, 6 Months, 26 Days  |
| Wilma Wilkins      | 1982-04-15 | 40 Years, 6 Months, 10 Days  |
| Clarence Hamilton  | 1982-07-19 | 40 Years, 3 Months, 7 Days   |
| Cecilia Hammond    | 1982-12-26 | 39 Years, 9 Months, 29 Days  |
+--------------------+------------+------------------------------+
50 rows in set (0.00 sec)
```

#### 3. Find the second maximum salary of all employees.

##### Query:
```sql
SELECT E2.ENAME AS "Employee Name", MAX(E2.SALARY) AS "Second Highest Salary"
FROM Employee_0129 E2
WHERE
    E2.SALARY NOT IN (
    SELECT MAX(E1.SALARY)
    FROM Employee_0129 E1
);
```

##### Output:
```
mysql> SELECT E2.ENAME AS "Employee Name", MAX(E2.SALARY) AS "Second Highest Salary"
    -> FROM Employee_0129 E2
    -> WHERE
    ->     E2.SALARY NOT IN (
    ->     SELECT MAX(E1.SALARY)
    ->     FROM Employee_0129 E1
    -> );
+---------------+-----------------------+
| Employee Name | Second Highest Salary |
+---------------+-----------------------+
| Carlos Wise   |                 24000 |
+---------------+-----------------------+
1 row in set (0.00 sec)
```

#### 4. Display all employee name and department name in department name order.

##### Query:
```sql
SELECT E.ENAME AS "Employee Name", D.DEPT_NAME AS "Department Name"
FROM Employee_0129 E, Department_0129 D
WHERE E.DEPT_NO = D.DEPT_NO
ORDER BY D.DEPT_NAME;
```

##### Output:
```
mysql> SELECT E.ENAME AS "Employee Name", D.DEPT_NAME AS "Department Name"
    -> FROM Employee_0129 E, Department_0129 D
    -> WHERE E.DEPT_NO = D.DEPT_NO
    -> ORDER BY D.DEPT_NAME;
+--------------------+-----------------+
| Employee Name      | Department Name |
+--------------------+-----------------+
| Alexander Barnes   | Backend         |
| Amber Howard       | Backend         |
| Bruce Mitchell     | Backend         |
| Carolyn Graves     | Backend         |
| Adrian Long        | Backend         |
| Marta Pierce       | Backend         |
| Henry Barber       | Backend         |
| Oscar Reid         | Frontend        |
| Terry Fleming      | Frontend        |
| Stephen Lane       | Frontend        |
| Carlos Wise        | Frontend        |
| Victor Boyd        | Frontend        |
| Chad Bowen         | Frontend        |
| Traci Jones        | Frontend        |
| Christina Harmon   | Frontend        |
| Clarence Hamilton  | Frontend        |
| Sophia Spencer     | HR              |
| Marian Lucas       | HR              |
| Donnie Robertson   | HR              |
| Emanuel Barker     | HR              |
| Darin Alexander    | HR              |
| Whitney Collier    | Marketing       |
| Gloria Peterson    | Marketing       |
| Boyd Watkins       | Marketing       |
| Lee Robbins        | Marketing       |
| Kristopher Douglas | Marketing       |
| Lyle Daniel        | Marketing       |
| Dean Allen         | Marketing       |
| Ellis Brady        | Marketing       |
| Vernon Bennett     | Marketing       |
| Tom Morris         | Marketing       |
| Jose Santos        | Marketing       |
| Wilma Wilkins      | Marketing       |
| Wayne Myers        | Marketing       |
| Sonja Bush         | Research        |
| Caroline Evans     | Research        |
| Harvey Klein       | Research        |
| Angelina Maxwell   | Research        |
| Pat Gardner        | Research        |
| Beverly Holt       | Research        |
| Eddie Greer        | Research        |
| Isabel Taylor      | Research        |
| Ramon Russell      | Research        |
| Beth Jordan        | Research        |
| Cecilia Hammond    | Research        |
| Bryant Stevens     | Systems         |
| Bertha Pearson     | Systems         |
| Jill Powers        | Systems         |
| Roger Mccormick    | Systems         |
| Yvette Mcbride     | Systems         |
+--------------------+-----------------+
50 rows in set (0.00 sec)
```

#### 5. Find the name of lowest paid employee for each manager.

##### Query:
```sql
SELECT
    E.ENAME AS "Employee Name",
    MIN(E.SALARY) AS "Minimum Salary",
    E.MGR_E_ID AS "Manager Name"
FROM Employee_0129 E
GROUP BY E.MGR_E_ID;
```

##### Output:
```
mysql> SELECT
    ->     E.ENAME AS "Employee Name",
    ->     MIN(E.SALARY) AS "Minimum Salary",
    ->     E.MGR_E_ID AS "Manager Name"
    -> FROM Employee_0129 E
    -> GROUP BY E.MGR_E_ID;
+----------------+----------------+--------------+
| Employee Name  | Minimum Salary | Manager Name |
+----------------+----------------+--------------+
| Carlos Wise    |           7000 |         8908 |
| Amber Howard   |           8000 |         7248 |
| Yvette Mcbride |           7000 |         3151 |
| Sophia Spencer |          10000 |         5050 |
| Eddie Greer    |           8000 |         5669 |
| Jose Santos    |           6000 |         6267 |
+----------------+----------------+--------------+
6 rows in set (0.00 sec)
```

#### 6. Display the department that has no employee.

##### Query:
```sql
SELECT D.DEPT_NO AS "Department Number", D.DEPT_NAME AS "Department Name"
FROM Department_0129 D
WHERE
    D.DEPT_NO NOT IN (
        SELECT E.DEPT_NO
        FROM Employee_0129 E
    );
```

##### Output:
```
mysql> SELECT D.DEPT_NO AS "Department Number", D.DEPT_NAME AS "Department Name"
    -> FROM Department_0129 D
    -> WHERE
    ->     D.DEPT_NO NOT IN (
    ->         SELECT E.DEPT_NO
    ->         FROM Employee_0129 E
    ->     );
+-------------------+-----------------+
| Department Number | Department Name |
+-------------------+-----------------+
|                78 | Maint.          |
+-------------------+-----------------+
1 row in set (0.00 sec)
```

#### 7. Find the employees who earn the maximum salary in each job type. Sort in descending order of salary.

##### Query:
```sql
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
```

##### Output:
```
mysql> SELECT
    ->     MAXSAL.ENAME AS "Employee Name",
    ->     MAXSAL.MAXSALARIES AS "Maximum Salary",
    ->     MAXSAL.JOB AS "Job Type"
    -> FROM (
    ->     SELECT E.ENAME, MAX(E.SALARY) AS MAXSALARIES, E.JOB
    ->     FROM Employee_0129 E
    ->     GROUP BY E.JOB
    -> ) MAXSAL
    -> ORDER BY MAXSAL.MAXSALARIES DESC;
+-----------------+----------------+----------+
| Employee Name   | Maximum Salary | Job Type |
+-----------------+----------------+----------+
| Roger Mccormick |          25000 | Manager  |
| Sophia Spencer  |          24000 | Clerk    |
| Carlos Wise     |          23000 | Jr. Emp. |
| Amber Howard    |          22000 | Officer  |
+-----------------+----------------+----------+
4 rows in set (0.00 sec)
```

#### 8. In which year did most people join the company? Display the year and number of employees.

##### Query:
```sql
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
```

##### Output:
```
mysql> SELECT
    ->     COUNT(E1.E_ID) AS "Maximum Number of Employees",
    ->     YEAR(E1.HIREDATE) AS "Year"
    -> FROM Employee_0129 E1
    -> GROUP BY YEAR(E1.HIREDATE)
    -> HAVING
    ->     COUNT(E1.E_ID) IN (
    ->         SELECT MAX(YEAR_COUNTS)
    ->         FROM (
    ->             SELECT COUNT(E2.E_ID) AS YEAR_COUNTS
    ->             FROM Employee_0129 E2
    ->             GROUP BY YEAR(E2.HIREDATE)
    ->         ) COUNTS
    ->     );
+-----------------------------+------+
| Maximum Number of Employees | Year |
+-----------------------------+------+
|                          16 | 1982 |
+-----------------------------+------+
1 row in set (0.00 sec)
```

#### 9. Display the details of those employees who earn greater than average of their department.

##### Query:
```sql
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
```

##### Output:
```
mysql> SELECT
    ->     E1.E_ID AS "Employee ID",
    ->     E1.ENAME AS "Employee Name",
    ->     E1.SALARY AS "Salary",
    ->     D.DEPT_NAME AS "Department",
    ->     E1.JOB AS "Job"
    -> FROM Employee_0129 E1, Department_0129 D
    -> WHERE
    ->     D.DEPT_NO = E1.DEPT_NO
    ->     AND SALARY > (
    ->         SELECT AVG(E2.SALARY)
    ->         FROM Employee_0129 E2
    ->         WHERE E1.DEPT_NO = E2.DEPT_NO
    ->     );
+-------------+------------------+--------+------------+----------+
| Employee ID | Employee Name    | Salary | Department | Job      |
+-------------+------------------+--------+------------+----------+
|        1236 | Amber Howard     |  22000 | Backend    | Officer  |
|        1242 | Yvette Mcbride   |  21000 | Systems    | Officer  |
|        1318 | Terry Fleming    |  15000 | Frontend   | Officer  |
|        1990 | Sophia Spencer   |  21000 | HR         | Clerk    |
|        2006 | Alexander Barnes |  18000 | Backend    | Officer  |
|        3074 | Jose Santos      |  16000 | Marketing  | Officer  |
|        3151 | Roger Mccormick  |  22000 | Systems    | Manager  |
|        3634 | Chad Bowen       |  17000 | Frontend   | Officer  |
|        4255 | Wayne Myers      |  24000 | Marketing  | Clerk    |
|        4269 | Henry Barber     |  19000 | Backend    | Jr. Emp. |
|        4704 | Traci Jones      |  20000 | Frontend   | Officer  |
|        5344 | Lee Robbins      |  19000 | Marketing  | Officer  |
|        5669 | Sonja Bush       |  18000 | Research   | Manager  |
|        6028 | Lyle Daniel      |  21000 | Marketing  | Clerk    |
|        6267 | Dean Allen       |  25000 | Marketing  | Manager  |
|        6485 | Harvey Klein     |  19000 | Research   | Officer  |
|        6505 | Donnie Robertson |  23000 | HR         | Jr. Emp. |
|        6514 | Isabel Taylor    |  16000 | Research   | Jr. Emp. |
|        6543 | Ramon Russell    |  16000 | Research   | Officer  |
|        7248 | Marta Pierce     |  20000 | Backend    | Manager  |
|        7655 | Beverly Holt     |  22000 | Research   | Officer  |
|        7754 | Marian Lucas     |  20000 | HR         | Jr. Emp. |
|        7827 | Jill Powers      |  16000 | Systems    | Jr. Emp. |
|        9845 | Cecilia Hammond  |  20000 | Research   | Jr. Emp. |
+-------------+------------------+--------+------------+----------+
24 rows in set (0.01 sec)
```

#### 10. List the employees having salary between $10000$ and $20000$.

##### Query:
```sql
SELECT
    E.E_ID AS "Employee ID", 
    E.ENAME AS "Employee Name",
    E.SALARY AS "Salary",
    E.JOB AS "Job"
FROM Employee_0129 E
WHERE E.SALARY BETWEEN 10000 AND 20000;
```

##### Output:
```
mysql> SELECT
    ->     E.E_ID AS "Employee ID",
    ->     E.ENAME AS "Employee Name",
    ->     E.SALARY AS "Salary",
    ->     E.JOB AS "Job"
    -> FROM Employee_0129 E
    -> WHERE E.SALARY BETWEEN 10000 AND 20000;
+-------------+--------------------+--------+----------+
| Employee ID | Employee Name      | Salary | Job      |
+-------------+--------------------+--------+----------+
|        1022 | Carlos Wise        |  11000 | Jr. Emp. |
|        1318 | Terry Fleming      |  15000 | Officer  |
|        2006 | Alexander Barnes   |  18000 | Officer  |
|        3074 | Jose Santos        |  16000 | Officer  |
|        3634 | Chad Bowen         |  17000 | Officer  |
|        4208 | Caroline Evans     |  13000 | Clerk    |
|        4269 | Henry Barber       |  19000 | Jr. Emp. |
|        4528 | Whitney Collier    |  12000 | Officer  |
|        4704 | Traci Jones        |  20000 | Officer  |
|        5050 | Emanuel Barker     |  10000 | Manager  |
|        5056 | Darin Alexander    |  10000 | Manager  |
|        5344 | Lee Robbins        |  19000 | Officer  |
|        5669 | Sonja Bush         |  18000 | Manager  |
|        5952 | Kristopher Douglas |  11000 | Jr. Emp. |
|        6199 | Beth Jordan        |  11000 | Jr. Emp. |
|        6485 | Harvey Klein       |  19000 | Officer  |
|        6514 | Isabel Taylor      |  16000 | Jr. Emp. |
|        6543 | Ramon Russell      |  16000 | Officer  |
|        6982 | Ellis Brady        |  14000 | Officer  |
|        7061 | Bryant Stevens     |  13000 | Clerk    |
|        7248 | Marta Pierce       |  20000 | Manager  |
|        7754 | Marian Lucas       |  20000 | Jr. Emp. |
|        7827 | Jill Powers        |  16000 | Jr. Emp. |
|        7962 | Carolyn Graves     |  16000 | Officer  |
|        8038 | Tom Morris         |  12000 | Officer  |
|        8468 | Pat Gardner        |  10000 | Jr. Emp. |
|        8584 | Vernon Bennett     |  12000 | Clerk    |
|        8593 | Bruce Mitchell     |  14000 | Jr. Emp. |
|        8908 | Oscar Reid         |  12000 | Manager  |
|        9488 | Christina Harmon   |  12000 | Jr. Emp. |
|        9546 | Wilma Wilkins      |  14000 | Jr. Emp. |
|        9845 | Cecilia Hammond    |  20000 | Jr. Emp. |
+-------------+--------------------+--------+----------+
32 rows in set (0.00 sec)
```

#### 11. Display all employees hired during $1983$ and those employees who earn greater than average of their department.

##### Query:
```sql
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
```

##### Output:
```
mysql> SELECT
    ->     E1.E_ID AS "Employee ID",
    ->     E1.ENAME AS "Employee Name",
    ->     E1.SALARY AS "Salary",
    ->     D.DEPT_NAME AS "Department",
    ->     E1.JOB AS "Job"
    -> FROM Employee_0129 E1, Department_0129 D
    -> WHERE
    ->     E1.DEPT_NO = D.DEPT_NO
    ->     AND YEAR(E1.HIREDATE) = 1983
    ->     AND E1.SALARY > (
    ->         SELECT AVG(E2.SALARY)
    ->         FROM Employee_0129 E2
    ->         WHERE E1.DEPT_NO = E2.DEPT_NO
    ->     );
+-------------+-----------------+--------+------------+----------+
| Employee ID | Employee Name   | Salary | Department | Job      |
+-------------+-----------------+--------+------------+----------+
|        3151 | Roger Mccormick |  22000 | Systems    | Manager  |
|        4255 | Wayne Myers     |  24000 | Marketing  | Clerk    |
|        4269 | Henry Barber    |  19000 | Backend    | Jr. Emp. |
|        6514 | Isabel Taylor   |  16000 | Research   | Jr. Emp. |
+-------------+-----------------+--------+------------+----------+
4 rows in set (0.00 sec)
```

#### 12. Update the salaries of all employees in marketing department & hike it by $15\%$.

##### Query:
```sql
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
```

##### Output:
```
mysql> SELECT E.ENAME AS "Employee Name", E.SALARY AS "Salary"
    -> FROM Employee_0129 E, Department_0129 D
    -> WHERE E.DEPT_NO = D.DEPT_NO AND D.DEPT_NAME = "Marketing";
+--------------------+--------+
| Employee Name      | Salary |
+--------------------+--------+
| Jose Santos        |  16000 |
| Wayne Myers        |  24000 |
| Whitney Collier    |  12000 |
| Gloria Peterson    |   8000 |
| Boyd Watkins       |   6000 |
| Lee Robbins        |  19000 |
| Kristopher Douglas |  11000 |
| Lyle Daniel        |  21000 |
| Dean Allen         |  25000 |
| Ellis Brady        |  14000 |
| Tom Morris         |  12000 |
| Vernon Bennett     |  12000 |
| Wilma Wilkins      |  14000 |
+--------------------+--------+
13 rows in set (0.00 sec)

mysql>
mysql> UPDATE Employee_0129 E
    -> SET E.SALARY = E.SALARY * 1.15
    -> WHERE
    ->     E.DEPT_NO = (
    ->         SELECT D.DEPT_NO
    ->         FROM Department_0129 D
    ->         WHERE D.DEPT_NAME = "Marketing"
    ->     );
Query OK, 13 rows affected (0.01 sec)
Rows matched: 13  Changed: 13  Warnings: 0

mysql>
mysql> SELECT E.ENAME AS "Employee Name", E.SALARY AS "Salary"
    -> FROM Employee_0129 E, Department_0129 D
    -> WHERE E.DEPT_NO = D.DEPT_NO AND D.DEPT_NAME = "Marketing";
+--------------------+--------+
| Employee Name      | Salary |
+--------------------+--------+
| Jose Santos        |  18400 |
| Wayne Myers        |  27600 |
| Whitney Collier    |  13800 |
| Gloria Peterson    |   9200 |
| Boyd Watkins       |   6900 |
| Lee Robbins        |  21850 |
| Kristopher Douglas |  12650 |
| Lyle Daniel        |  24150 |
| Dean Allen         |  28750 |
| Ellis Brady        |  16100 |
| Tom Morris         |  13800 |
| Vernon Bennett     |  13800 |
| Wilma Wilkins      |  16100 |
+--------------------+--------+
13 rows in set (0.00 sec)
```

#### 13. Get the gross salaries of all the employees.

##### Query:
```sql
SELECT E.ENAME AS "Employee Name", E.SALARY AS "Salary"
FROM Employee_0129 E;
```

##### Output:
```
mysql> SELECT E.ENAME AS "Employee Name", E.SALARY AS "Salary"
    -> FROM Employee_0129 E;
+--------------------+--------+
| Employee Name      | Salary |
+--------------------+--------+
| Carlos Wise        |  11000 |
| Amber Howard       |  22000 |
| Yvette Mcbride     |  21000 |
| Terry Fleming      |  15000 |
| Stephen Lane       |   7000 |
| Sophia Spencer     |  21000 |
| Alexander Barnes   |  18000 |
| Eddie Greer        |   8000 |
| Jose Santos        |  18400 |
| Roger Mccormick    |  22000 |
| Chad Bowen         |  17000 |
| Bertha Pearson     |   7000 |
| Caroline Evans     |  13000 |
| Wayne Myers        |  27600 |
| Henry Barber       |  19000 |
| Whitney Collier    |  13800 |
| Traci Jones        |  20000 |
| Emanuel Barker     |  10000 |
| Darin Alexander    |  10000 |
| Gloria Peterson    |   9200 |
| Boyd Watkins       |   6900 |
| Lee Robbins        |  21850 |
| Victor Boyd        |   8000 |
| Sonja Bush         |  18000 |
| Angelina Maxwell   |   9000 |
| Kristopher Douglas |  12650 |
| Lyle Daniel        |  24150 |
| Beth Jordan        |  11000 |
| Dean Allen         |  28750 |
| Harvey Klein       |  19000 |
| Donnie Robertson   |  23000 |
| Isabel Taylor      |  16000 |
| Ramon Russell      |  16000 |
| Ellis Brady        |  16100 |
| Bryant Stevens     |  13000 |
| Marta Pierce       |  20000 |
| Adrian Long        |   8000 |
| Beverly Holt       |  22000 |
| Marian Lucas       |  20000 |
| Jill Powers        |  16000 |
| Carolyn Graves     |  16000 |
| Tom Morris         |  13800 |
| Pat Gardner        |  10000 |
| Vernon Bennett     |  13800 |
| Bruce Mitchell     |  14000 |
| Oscar Reid         |  12000 |
| Christina Harmon   |  12000 |
| Wilma Wilkins      |  16100 |
| Clarence Hamilton  |   9000 |
| Cecilia Hammond    |  20000 |
+--------------------+--------+
50 rows in set (0.00 sec)
```

#### 14. Get the names of employees and their manager's name.

##### Query:
```sql
SELECT E.ENAME AS "Employee Name", M.ENAME AS "Manager Name"
FROM Employee_0129 E, Employee_0129 M
WHERE E.MGR_E_ID = M.E_ID;
```

##### Output:
```
mysql> SELECT E.ENAME AS "Employee Name", M.ENAME AS "Manager Name"
    -> FROM Employee_0129 E, Employee_0129 M
    -> WHERE E.MGR_E_ID = M.E_ID;
+--------------------+-----------------+
| Employee Name      | Manager Name    |
+--------------------+-----------------+
| Carlos Wise        | Oscar Reid      |
| Amber Howard       | Marta Pierce    |
| Yvette Mcbride     | Roger Mccormick |
| Terry Fleming      | Oscar Reid      |
| Stephen Lane       | Oscar Reid      |
| Sophia Spencer     | Emanuel Barker  |
| Alexander Barnes   | Marta Pierce    |
| Eddie Greer        | Sonja Bush      |
| Jose Santos        | Dean Allen      |
| Roger Mccormick    | Roger Mccormick |
| Chad Bowen         | Oscar Reid      |
| Bertha Pearson     | Roger Mccormick |
| Caroline Evans     | Sonja Bush      |
| Wayne Myers        | Dean Allen      |
| Henry Barber       | Marta Pierce    |
| Whitney Collier    | Dean Allen      |
| Traci Jones        | Oscar Reid      |
| Emanuel Barker     | Emanuel Barker  |
| Darin Alexander    | Emanuel Barker  |
| Gloria Peterson    | Dean Allen      |
| Boyd Watkins       | Dean Allen      |
| Lee Robbins        | Dean Allen      |
| Victor Boyd        | Oscar Reid      |
| Sonja Bush         | Sonja Bush      |
| Angelina Maxwell   | Sonja Bush      |
| Kristopher Douglas | Dean Allen      |
| Lyle Daniel        | Dean Allen      |
| Beth Jordan        | Sonja Bush      |
| Dean Allen         | Dean Allen      |
| Harvey Klein       | Sonja Bush      |
| Donnie Robertson   | Emanuel Barker  |
| Isabel Taylor      | Sonja Bush      |
| Ramon Russell      | Sonja Bush      |
| Ellis Brady        | Dean Allen      |
| Bryant Stevens     | Roger Mccormick |
| Marta Pierce       | Marta Pierce    |
| Adrian Long        | Marta Pierce    |
| Beverly Holt       | Sonja Bush      |
| Marian Lucas       | Emanuel Barker  |
| Jill Powers        | Roger Mccormick |
| Carolyn Graves     | Marta Pierce    |
| Tom Morris         | Dean Allen      |
| Pat Gardner        | Sonja Bush      |
| Vernon Bennett     | Dean Allen      |
| Bruce Mitchell     | Marta Pierce    |
| Oscar Reid         | Oscar Reid      |
| Christina Harmon   | Oscar Reid      |
| Wilma Wilkins      | Dean Allen      |
| Clarence Hamilton  | Oscar Reid      |
| Cecilia Hammond    | Sonja Bush      |
+--------------------+-----------------+
50 rows in set (0.00 sec)
```

#### 15. Display the name, location and department name of all the employees earning more than $1500$.

##### Query:
```sql
SELECT
    E.ENAME AS "Employee Name",
    E.LOC AS "Location",
    D.DEPT_NAME AS "Department"
FROM Employee_0129 E, Department_0129 D
WHERE E.SALARY > 15000 AND E.DEPT_NO = D.DEPT_NO;
```

##### Output:
```
mysql> SELECT
    ->     E.ENAME AS "Employee Name",
    ->     E.LOC AS "Location",
    ->     D.DEPT_NAME AS "Department"
    -> FROM Employee_0129 E, Department_0129 D
    -> WHERE E.SALARY > 15000 AND E.DEPT_NO = D.DEPT_NO;
+------------------+---------------+------------+
| Employee Name    | Location      | Department |
+------------------+---------------+------------+
| Amber Howard     | San Francisco | Backend    |
| Yvette Mcbride   | New York      | Systems    |
| Sophia Spencer   | Boston        | HR         |
| Alexander Barnes | Boston        | Backend    |
| Jose Santos      | Dallas        | Marketing  |
| Roger Mccormick  | Seattle       | Systems    |
| Chad Bowen       | New Orleans   | Frontend   |
| Wayne Myers      | New Orleans   | Marketing  |
| Henry Barber     | San Francisco | Backend    |
| Traci Jones      | Dallas        | Frontend   |
| Lee Robbins      | Boston        | Marketing  |
| Sonja Bush       | Seattle       | Research   |
| Lyle Daniel      | New York      | Marketing  |
| Dean Allen       | Boston        | Marketing  |
| Harvey Klein     | Dallas        | Research   |
| Donnie Robertson | San Francisco | HR         |
| Isabel Taylor    | New York      | Research   |
| Ramon Russell    | Dallas        | Research   |
| Ellis Brady      | San Francisco | Marketing  |
| Marta Pierce     | Seattle       | Backend    |
| Beverly Holt     | Dallas        | Research   |
| Marian Lucas     | Seattle       | HR         |
| Jill Powers      | New Orleans   | Systems    |
| Carolyn Graves   | Dallas        | Backend    |
| Wilma Wilkins    | New Orleans   | Marketing  |
| Cecilia Hammond  | Seattle       | Research   |
+------------------+---------------+------------+
26 rows in set (0.00 sec)
```

#### 16. Show all the employees in <span style = "font-family:Input">Dallas</span>.

##### Query:
```sql
SELECT
    E.E_ID AS "Employee ID",
    E.ENAME AS "Employee Name",
    E.SALARY AS "Salary",
    E.JOB AS "Job",
    E.LOC AS "Location"
FROM Employee_0129 E
WHERE E.LOC = "Dallas";
```

##### Output:
```
mysql> SELECT
    ->     E.E_ID AS "Employee ID",
    ->     E.ENAME AS "Employee Name",
    ->     E.SALARY AS "Salary",
    ->     E.JOB AS "Job",
    ->     E.LOC AS "Location"
    -> FROM Employee_0129 E
    -> WHERE E.LOC = "Dallas";
+-------------+------------------+--------+----------+----------+
| Employee ID | Employee Name    | Salary | Job      | Location |
+-------------+------------------+--------+----------+----------+
|        1318 | Terry Fleming    |  15000 | Officer  | Dallas   |
|        3074 | Jose Santos      |  18400 | Officer  | Dallas   |
|        4704 | Traci Jones      |  20000 | Officer  | Dallas   |
|        5306 | Boyd Watkins     |   6900 | Officer  | Dallas   |
|        5891 | Angelina Maxwell |   9000 | Officer  | Dallas   |
|        6485 | Harvey Klein     |  19000 | Officer  | Dallas   |
|        6543 | Ramon Russell    |  16000 | Officer  | Dallas   |
|        7655 | Beverly Holt     |  22000 | Officer  | Dallas   |
|        7962 | Carolyn Graves   |  16000 | Officer  | Dallas   |
|        8584 | Vernon Bennett   |  13800 | Clerk    | Dallas   |
|        9488 | Christina Harmon |  12000 | Jr. Emp. | Dallas   |
+-------------+------------------+--------+----------+----------+
11 rows in set (0.00 sec)
```

#### 17. List the employees' name, job, salary, grade, and department for employees in the company except clerks. Sort on employee names.

##### Query:
```sql
SELECT
    E.ENAME AS "Employee Name",
    E.JOB AS "Job",
    E.SALARY AS "Salary",
    E.GRADE AS "Grade",
    D.DEPT_NAME AS "Department"
FROM Employee_0129 E, Department_0129 D
WHERE E.DEPT_NO = D.DEPT_NO AND E.JOB NOT LIKE ("Clerk")
ORDER BY E.ENAME;
```

##### Output:
```
mysql> SELECT
    ->     E.ENAME AS "Employee Name",
    ->     E.JOB AS "Job",
    ->     E.SALARY AS "Salary",
    ->     E.GRADE AS "Grade",
    ->     D.DEPT_NAME AS "Department"
    -> FROM Employee_0129 E, Department_0129 D
    -> WHERE E.DEPT_NO = D.DEPT_NO AND E.JOB NOT LIKE ("Clerk")
    -> ORDER BY E.ENAME;
+--------------------+----------+--------+-------+------------+
| Employee Name      | Job      | Salary | Grade | Department |
+--------------------+----------+--------+-------+------------+
| Adrian Long        | Officer  |   8000 | C     | Backend    |
| Alexander Barnes   | Officer  |  18000 | B     | Backend    |
| Amber Howard       | Officer  |  22000 | B     | Backend    |
| Angelina Maxwell   | Officer  |   9000 | A     | Research   |
| Bertha Pearson     | Jr. Emp. |   7000 | A     | Systems    |
| Beth Jordan        | Jr. Emp. |  11000 | C     | Research   |
| Beverly Holt       | Officer  |  22000 | A     | Research   |
| Boyd Watkins       | Officer  |   6900 | C     | Marketing  |
| Bruce Mitchell     | Jr. Emp. |  14000 | C     | Backend    |
| Carlos Wise        | Jr. Emp. |  11000 | C     | Frontend   |
| Carolyn Graves     | Officer  |  16000 | B     | Backend    |
| Cecilia Hammond    | Jr. Emp. |  20000 | A     | Research   |
| Chad Bowen         | Officer  |  17000 | A     | Frontend   |
| Christina Harmon   | Jr. Emp. |  12000 | A     | Frontend   |
| Clarence Hamilton  | Officer  |   9000 | A     | Frontend   |
| Darin Alexander    | Manager  |  10000 | B     | HR         |
| Dean Allen         | Manager  |  28750 | B     | Marketing  |
| Donnie Robertson   | Jr. Emp. |  23000 | B     | HR         |
| Ellis Brady        | Officer  |  16100 | B     | Marketing  |
| Emanuel Barker     | Manager  |  10000 | B     | HR         |
| Harvey Klein       | Officer  |  19000 | B     | Research   |
| Henry Barber       | Jr. Emp. |  19000 | B     | Backend    |
| Isabel Taylor      | Jr. Emp. |  16000 | B     | Research   |
| Jill Powers        | Jr. Emp. |  16000 | C     | Systems    |
| Jose Santos        | Officer  |  18400 | C     | Marketing  |
| Kristopher Douglas | Jr. Emp. |  12650 | B     | Marketing  |
| Lee Robbins        | Officer  |  21850 | B     | Marketing  |
| Marian Lucas       | Jr. Emp. |  20000 | B     | HR         |
| Marta Pierce       | Manager  |  20000 | B     | Backend    |
| Oscar Reid         | Manager  |  12000 | B     | Frontend   |
| Pat Gardner        | Jr. Emp. |  10000 | B     | Research   |
| Ramon Russell      | Officer  |  16000 | C     | Research   |
| Roger Mccormick    | Manager  |  22000 | C     | Systems    |
| Sonja Bush         | Manager  |  18000 | B     | Research   |
| Stephen Lane       | Jr. Emp. |   7000 | C     | Frontend   |
| Terry Fleming      | Officer  |  15000 | B     | Frontend   |
| Tom Morris         | Officer  |  13800 | B     | Marketing  |
| Traci Jones        | Officer  |  20000 | C     | Frontend   |
| Victor Boyd        | Jr. Emp. |   8000 | A     | Frontend   |
| Whitney Collier    | Officer  |  13800 | C     | Marketing  |
| Wilma Wilkins      | Jr. Emp. |  16100 | B     | Marketing  |
| Yvette Mcbride     | Officer  |  21000 | A     | Systems    |
+--------------------+----------+--------+-------+------------+
42 rows in set (0.00 sec)
```

#### 18. Find the employees who earns the minimum salary for their job. Sort in descending order of salary.

##### Query:
```sql
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
```

##### Output:
```
mysql> SELECT
    ->     MINSAL.ENAME AS "Employee Name",
    ->     MINSAL.MINSALARIES AS "Minimum Salary",
    ->     MINSAL.JOB AS "Job"
    -> FROM (
    ->     SELECT E.ENAME, MIN(E.SALARY) AS MINSALARIES, E.JOB
    ->     FROM Employee_0129 E
    ->     GROUP BY E.JOB
    -> ) MINSAL
    -> ORDER BY MINSAL.MINSALARIES DESC;
+-----------------+----------------+----------+
| Employee Name   | Minimum Salary | Job      |
+-----------------+----------------+----------+
| Roger Mccormick |          10000 | Manager  |
| Sophia Spencer  |           8000 | Clerk    |
| Carlos Wise     |           7000 | Jr. Emp. |
| Amber Howard    |           6900 | Officer  |
+-----------------+----------------+----------+
4 rows in set (0.00 sec)
```

#### 19. Find the most recently hired employees in their department, order by hire date.

##### Query:
```sql
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
```

##### Output:
```
mysql> SELECT
    ->     E1.ENAME AS "Employee Name",
    ->     E1.HIREDATE AS "Hiring Date",
    ->     D.DEPT_NAME AS "Department"
    -> FROM Employee_0129 E1, Department_0129 D
    -> WHERE
    ->     E1.DEPT_NO = D.DEPT_NO
    ->     AND E1.HIREDATE IN (
    ->         SELECT MAX(E2.HIREDATE)
    ->         FROM Employee_0129 E2
    ->         GROUP BY E2.DEPT_NO
    ->     )
    -> ORDER BY E1.HIREDATE;
+------------------+-------------+------------+
| Employee Name    | Hiring Date | Department |
+------------------+-------------+------------+
| Donnie Robertson | 1984-04-05  | HR         |
| Bryant Stevens   | 1984-04-06  | Systems    |
| Ramon Russell    | 1984-09-13  | Research   |
| Alexander Barnes | 1984-10-14  | Backend    |
| Oscar Reid       | 1984-12-01  | Frontend   |
| Jose Santos      | 1984-12-20  | Marketing  |
+------------------+-------------+------------+
6 rows in set (0.00 sec)
```

#### 20. Find out the difference between highest and lowest salaries.

##### Query:
```sql
SELECT
    MAX(E.SALARY) AS "Maximum Salary",
    "-",
    MIN(E.SALARY) AS "Minimum Salary",
    "=",
    MAX(E.SALARY) - MIN(E.SALARY) AS "Difference"
FROM Employee_0129 E;
```

##### Output:
```
mysql> SELECT
    ->     MAX(E.SALARY) AS "Maximum Salary",
    ->     "-",
    ->     MIN(E.SALARY) AS "Minimum Salary",
    ->     "=",
    ->     MAX(E.SALARY) - MIN(E.SALARY) AS "Difference"
    -> FROM Employee_0129 E;
+----------------+---+----------------+---+------------+
| Maximum Salary | - | Minimum Salary | = | Difference |
+----------------+---+----------------+---+------------+
|          28750 | - |           6900 | = |      21850 |
+----------------+---+----------------+---+------------+
1 row in set (0.00 sec)
```

---
</span>
