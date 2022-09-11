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

    CONSTRAINT FOREIGN KEY(PROSPECTUS_NO) REFERENCES Student_0129(PROSPECTUS_NO)
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
```

##### Output:
```
mysql> -- Table Creation
mysql> CREATE TABLE Course_0129(
    ->     COURSE_NO   CHAR(4)     NOT NULL    UNIQUE  PRIMARY KEY,
    ->     COURSE_NAME VARCHAR(30)
    -> );
Query OK, 0 rows affected (0.04 sec)

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
    ->     CONSTRAINT FOREIGN KEY(COURSE_NO) REFERENCES Course_0129(COURSE_NO)
    -> );
Query OK, 0 rows affected, 1 warning (0.05 sec)

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
Query OK, 0 rows affected, 1 warning (0.08 sec)

mysql>
mysql> CREATE TABLE Installment_0129 (
    ->     PROSPECTUS_NO   INTEGER(10)     NOT NULL    UNIQUE,
    ->     INSTALLMENT_AMT DECIMAL(10, 2)  NOT NULL,
    ->     DUE_DT          DATE            NOT NULL,
    ->     PAID            CHAR(1)         NOT NULL    CHECK(PAID = "P" OR PAID = "U"),
    ->
    ->     CONSTRAINT FOREIGN KEY(PROSPECTUS_NO) REFERENCES Student_0129(PROSPECTUS_NO)
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
    ->         FOREIGN KEY(PROSPECTUS_NO) REFERENCES Student_0129(PROSPECTUS_NO),
    ->     CONSTRAINT FOREIGN KEY(COURSE_NO) REFERENCES Course_0129(COURSE_NO)
    -> );
Query OK, 0 rows affected, 1 warning (0.08 sec)

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
Query OK, 20 rows affected (0.02 sec)
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
Query OK, 1 row affected (0.01 sec)
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
| 3953       | R Programming       | F                |        7200 |
| 5839       | Unix                | P                |        8300 |
| 6005       | Machine Learning    | F                |        5500 |
| 7612       | Database Management | F                |        9000 |
| 8098       | Algorithms          | P                |        9400 |
| 9744       | Aptitude            | F                |        9200 |
+------------+---------------------+------------------+-------------+
7 rows in set (0.00 sec)
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
Query OK, 1 row affected (0.01 sec)
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
+------------+-----------------+--------------+
| Course No. | Course Name     | Course Count |
+------------+-----------------+--------------+
| 2938       | Oracle          |            2 |
| 3494       | Comm. French-II |            2 |
| 5839       | Unix            |            2 |
+------------+-----------------+--------------+
3 rows in set (0.00 sec)
```

#### 15. Select the students who have not yet paid full amount of fees.

##### Query:
```sql
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
```

##### Output:
```
mysql> SELECT
    ->     S.PROSPECTUS_NO AS "Prospectus No.",
    ->     S.NAME AS "Name",
    ->     S.ADDRESS AS "Address",
    ->     S.PHONE_NO AS "Phone No.",
    ->     S.D_O_B AS "Date of Birth",
    ->     S.TOTAL_AMT AS "Total Amount to Pay",
    ->     S.AMT_PAID AS "Amount Paid",
    ->     S.INSTALLMENT AS "Installment Status"
    -> FROM Student_0129 S
    -> WHERE S.TOTAL_AMT > S.AMT_PAID;
+----------------+--------------------+----------+------------+---------------+---------------------+-------------+--------------------+
| Prospectus No. | Name               | Address  | Phone No.  | Date of Birth | Total Amount to Pay | Amount Paid | Installment Status |
+----------------+--------------------+----------+------------+---------------+---------------------+-------------+--------------------+
|          15345 | Quirino Vivek      | Khora    | 4235853677 | 2000-10-14    |             8300.00 |     2700.00 | I                  |
|          30336 | Emílie Shōhei      | Zimland  | 1292801969 | 2002-01-08    |             7200.00 |        0.00 | I                  |
|          39524 | Afi Tessouat       | Ontgas   | 4332954027 | 1998-01-21    |             7200.00 |     2400.00 | I                  |
|          40515 | Susann Chisom      | Anegan   | 9187010108 | 1999-11-30    |             7200.00 |     1700.00 | I                  |
|          41867 | Magni Mehmet       | Boni     | 3759652478 | 1999-07-13    |             9000.00 |     7500.00 | I                  |
|          55850 | Virginia Ríghnach  | Straford | 5769568428 | 2002-06-14    |             4000.00 |     1000.00 | I                  |
|          56924 | Doireann Gaëlle    | Straford | 6592912808 | 1998-11-29    |             9200.00 |        0.00 | I                  |
|          65459 | Celyn Hilarion     | Zimland  | 8297094562 | 1999-10-02    |             4600.00 |        0.00 | I                  |
|          73579 | Úrsula Dermid      | Khora    | 5337070977 | 2000-01-01    |             9400.00 |     1800.00 | I                  |
|          94311 | Gilles Yusuf       | Boni     | 9564043944 | 1998-03-16    |             7200.00 |  
   6200.00 | I                  |
|          96858 | Viola Francine     | Volas    | 6526425614 | 2002-05-21    |             7200.00 |     4700.00 | I                  |
|          97528 | Robert Shariah     | Boni     | 5829643889 | 2002-01-25    |             8000.00 |     4400.00 | I                  |
+----------------+--------------------+----------+------------+---------------+---------------------+-------------+--------------------+
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

#### 4. Get <span style = "font-family:Input">COLOR</span> values for parts supplied by suppler <span style = "font-family:Input">s1</span>.

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
