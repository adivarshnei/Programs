# Q1.

## Table Schema
```
Course
  course_no char(4)
  course_name varchar(20)

Course_fee
  course_no char(4)
  full_part char(1) (F/P)
  fees number(10)

  Note: course_no and full_part should be unique.

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

## Table Creation
```sql
CREATE TABLE COURSE(
  COURSENO   CHAR(4)     NOT NULL PRIMARY KEY,
  COURSENAME VARCHAR(30)
);

CREATE TABLE COURSEFEE(
  COURSENO CHAR(4) NOT NULL UNIQUE,
  FULLPART CHAR(1) NOT NULL
  CHECK (
    FULLPART = 'F'
    OR FULLPART = 'P'
  ),
  FEES     NUMBER(10),
  CONSTRAINT FKCOURSEFEE
    FOREIGN KEY(COURSENO)
    REFERENCES COURSE(COURSENO)
    ON DELETE CASCADE
);

CREATE TABLE STUDENT(
  PROSPECTUSNO  NUMBER(10)     NOT NULL PRIMARY KEY,
  NAME          VARCHAR(20)    NOT NULL,
  ADDRESS       VARCHAR(30),
  PHONENO       DECIMAL(11, 0) UNIQUE,
  DOB           DATE           NOT NULL,
  TOTALAMT      DECIMAL(10, 2) NOT NULL,
  AMTPAID       DECIMAL(10, 2) NOT NULL,
  INSTALLMENT   CHAR(1)        NOT NULL
  CHECK (
    INSTALLMENT = 'I'
    OR INSTALLMENT = 'F'
  ),
  CONSTRAINT AMTCHECK CHECK (AMTPAID <= TOTALAMT)
);

CREATE TABLE INSTALLMENT(
  PROSPECTUSNO   NUMBER(10)    NOT NULL UNIQUE,
  INSTALLMENTAMT NUMBER(10, 2) NOT NULL,
  DUEDT          DATE          NOT NULL,
  PAID           CHAR(1)       NOT NULL
  CHECK (
    PAID = 'P'
    OR PAID = 'U'
  ),
  CONSTRAINT FKINSTALLMENT
    FOREIGN KEY(PROSPECTUSNO)
    REFERENCES STUDENT(PROSPECTUSNO)
    ON DELETE CASCADE
);

CREATE TABLE COURSETAKEN(
  PROSPECTUSNO NUMBER(10) NOT NULL UNIQUE,
  COURSENO     CHAR(4)    NOT NULL,
  STARTDT      DATE,
  FULLPART     CHAR(1)    NOT NULL
  CHECK (
    FULLPART = 'F'
    OR FULLPART = 'P'
  ),
  TIMESLOT     CHAR(2),
  PERFORMANCE  VARCHAR(20),
  CONSTRAINT FKPROSPECTUSNO
    FOREIGN KEY(PROSPECTUSNO)
    REFERENCES STUDENT(PROSPECTUSNO)
    ON DELETE CASCADE,
  CONSTRAINT FKCOURSENO
    FOREIGN KEY(COURSENO)
    REFERENCES COURSE(COURSENO)
    ON DELETE CASCADE
);
```

```
SQL> CREATE TABLE COURSE(
  2    COURSENO   CHAR(4)     NOT NULL PRIMARY KEY,
  3    COURSENAME VARCHAR(30)
  4  );

Table created.

SQL> CREATE TABLE COURSEFEE(
  2    COURSENO CHAR(4) NOT NULL UNIQUE,
  3    FULLPART CHAR(1) NOT NULL
  4    CHECK (
  5      FULLPART = 'F'
  6      OR FULLPART = 'P'
  7    ),
  8    FEES     NUMBER(10),
  9    CONSTRAINT FKCOURSEFEE
 10      FOREIGN KEY(COURSENO)
 11      REFERENCES COURSE(COURSENO)
 12      ON DELETE CASCADE
 13  );

Table created.

SQL> CREATE TABLE STUDENT(
  2    PROSPECTUSNO  NUMBER(10)     NOT NULL PRIMARY KEY,
  3    NAME          VARCHAR(20)    NOT NULL,
  4    ADDRESS       VARCHAR(30),
  5    PHONENO       DECIMAL(11, 0) UNIQUE,
  6    DOB           DATE           NOT NULL,
  7    TOTALAMT      DECIMAL(10, 2) NOT NULL,
  8    AMTPAID       DECIMAL(10, 2) NOT NULL,
  9    INSTALLMENT   CHAR(1)        NOT NULL
 10    CHECK (
 11      INSTALLMENT = 'I'
 12      OR INSTALLMENT = 'F'
 13    ),
 14    CONSTRAINT AMTCHECK CHECK (AMTPAID <= TOTALAMT)
 15  );

Table created.

SQL> CREATE TABLE INSTALLMENT(
  2    PROSPECTUSNO   NUMBER(10)    NOT NULL UNIQUE,
  3    INSTALLMENTAMT NUMBER(10, 2) NOT NULL,
  4    DUEDT          DATE          NOT NULL,
  5    PAID           CHAR(1)       NOT NULL
  6    CHECK (
  7      PAID = 'P'
  8      OR PAID = 'U'
  9    ),
 10    CONSTRAINT FKINSTALLMENT
 11      FOREIGN KEY(PROSPECTUSNO)
 12      REFERENCES STUDENT(PROSPECTUSNO)
 13      ON DELETE CASCADE
 14  );

Table created.

SQL> CREATE TABLE COURSETAKEN(
  2    PROSPECTUSNO NUMBER(10) NOT NULL UNIQUE,
  3    COURSENO     CHAR(4)    NOT NULL,
  4    STARTDT      DATE,
  5    FULLPART     CHAR(1)    NOT NULL
  6    CHECK (
  7      FULLPART = 'F'
  8      OR FULLPART = 'P'
  9    ),
 10    TIMESLOT     CHAR(2),
 11    PERFORMANCE  VARCHAR(20),
 12    CONSTRAINT FKPROSPECTUSNO
 13      FOREIGN KEY(PROSPECTUSNO)
 14      REFERENCES STUDENT(PROSPECTUSNO)
 15      ON DELETE CASCADE,
 16    CONSTRAINT FKCOURSENO
 17      FOREIGN KEY(COURSENO)
 18      REFERENCES COURSE(COURSENO)
 19      ON DELETE CASCADE
 20  );

Table created.
```

## Data Entry
```sql
INSERT INTO COURSE (COURSENO, COURSENAME) 
WITH COURSEDATA AS (
  SELECT '2926', 'Cognitive Skills'    FROM DUAL UNION ALL
  SELECT '7612', 'Database Management' FROM DUAL UNION ALL
  SELECT '8098', 'Algorithms'          FROM DUAL UNION ALL
  SELECT '3953', 'R Programming'       FROM DUAL UNION ALL
  SELECT '3494', 'Comm. French-II'     FROM DUAL UNION ALL
  SELECT '8381', 'Networks'            FROM DUAL UNION ALL
  SELECT '9744', 'Aptitude'            FROM DUAL UNION ALL
  SELECT '6005', 'Machine Learning'    FROM DUAL UNION ALL
  SELECT '5839', 'Unix'                FROM DUAL UNION ALL
  SELECT '2938', 'Oracle'              FROM DUAL
)
SELECT * FROM COURSEDATA;

INSERT INTO COURSEFEE (COURSENO, FULLPART, FEES)
WITH COURSEFEEDATA AS (
  SELECT '2926', 'P', 8000 FROM DUAL UNION ALL
  SELECT '7612', 'F', 9000 FROM DUAL UNION ALL
  SELECT '8098', 'P', 9400 FROM DUAL UNION ALL
  SELECT '3953', 'F', 7200 FROM DUAL UNION ALL
  SELECT '3494', 'P', 4000 FROM DUAL UNION ALL
  SELECT '8381', 'P', 4600 FROM DUAL UNION ALL
  SELECT '9744', 'F', 9200 FROM DUAL UNION ALL
  SELECT '6005', 'F', 5500 FROM DUAL UNION ALL
  SELECT '5839', 'P', 8300 FROM DUAL UNION ALL
  SELECT '2938', 'P', 4800 FROM DUAL
)
SELECT * FROM COURSEFEEDATA;

INSERT INTO STUDENT (PROSPECTUSNO, NAME, ADDRESS, PHONENO, DOB, TOTALAMT, AMTPAID, INSTALLMENT)
WITH STUDENTDATA AS (
  SELECT 30336, 'Emílie Shōhei',     'Zimland',  1292801969, TO_DATE('2002-1-8', 'YYYY-MM-DD'),   7200, 0,    'I' FROM DUAL UNION ALL
  SELECT 80652, 'Aleksy Toivo',      'Ontgas',   8365416489, TO_DATE('2001-2-9', 'YYYY-MM-DD'),   9200, 9200, 'F' FROM DUAL UNION ALL
  SELECT 96013, 'Norbert Lailoken',  'Fand',     8176515222, TO_DATE('1998-8-14', 'YYYY-MM-DD'),  9400, 9400, 'F' FROM DUAL UNION ALL
  SELECT 43852, 'Feidlimid Adrijan', 'Zimland',  4889216273, TO_DATE('1999-11-18', 'YYYY-MM-DD'), 4000, 4000, 'F' FROM DUAL UNION ALL
  SELECT 55850, 'Virginia Ríghnach', 'Straford', 5769568428, TO_DATE('2002-6-14', 'YYYY-MM-DD'),  4000, 1000, 'I' FROM DUAL UNION ALL
  SELECT 52238, 'Aamir Jelka',       'Klaxstea', 7289156515, TO_DATE('2000-2-21', 'YYYY-MM-DD'),  4600, 4600, 'F' FROM DUAL UNION ALL
  SELECT 96858, 'Viola Francine',    'Volas',    6526425614, TO_DATE('2002-5-21', 'YYYY-MM-DD'),  7200, 4700, 'I' FROM DUAL UNION ALL
  SELECT 94311, 'Gilles Yusuf',      'Boni',     9564043944, TO_DATE('1998-3-16', 'YYYY-MM-DD'),  7200, 6200, 'I' FROM DUAL UNION ALL
  SELECT 56924, 'Doireann Gaëlle',   'Straford', 6592912808, TO_DATE('1998-11-29', 'YYYY-MM-DD'), 9200, 0,    'I' FROM DUAL UNION ALL
  SELECT 97257, 'Therapon Ayaz',     'Bedtin',   1573206254, TO_DATE('2001-4-26', 'YYYY-MM-DD'),  9200, 9200, 'F' FROM DUAL UNION ALL
  SELECT 15345, 'Quirino Vivek',     'Khora',    4235853677, TO_DATE('2000-10-14', 'YYYY-MM-DD'), 8300, 2700, 'I' FROM DUAL UNION ALL
  SELECT 39524, 'Afi Tessouat',      'Ontgas',   4332954027, TO_DATE('1998-1-21', 'YYYY-MM-DD'),  7200, 2400, 'I' FROM DUAL UNION ALL
  SELECT 40515, 'Susann Chisom',     'Anegan',   9187010108, TO_DATE('1999-11-30', 'YYYY-MM-DD'), 7200, 1700, 'I' FROM DUAL UNION ALL
  SELECT 89292, 'Martialis Hacî',    'Straford', 5301049309, TO_DATE('1999-10-19', 'YYYY-MM-DD'), 9400, 9400, 'F' FROM DUAL UNION ALL
  SELECT 88905, 'Chi Titilayo',      'Volas',    4847733538, TO_DATE('1996-10-19', 'YYYY-MM-DD'), 8300, 8300, 'F' FROM DUAL UNION ALL
  SELECT 11443, 'Nicușor Sultan',    'Ontgas',   6352625141, TO_DATE('2000-10-27', 'YYYY-MM-DD'), 4600, 4600, 'F' FROM DUAL UNION ALL
  SELECT 65459, 'Celyn Hilarion',    'Zimland',  8297094562, TO_DATE('1999-10-2', 'YYYY-MM-DD'),  4600, 0,    'I' FROM DUAL UNION ALL
  SELECT 73579, 'Úrsula Dermid',     'Khora',    5337070977, TO_DATE('2000-1-1', 'YYYY-MM-DD'),   9400, 1800, 'I' FROM DUAL UNION ALL
  SELECT 41867, 'Magni Mehmet',      'Boni',     3759652478, TO_DATE('1999-7-13', 'YYYY-MM-DD'),  9000, 7500, 'I' FROM DUAL UNION ALL
  SELECT 97528, 'Robert Shariah',    'Boni',     5829643889, TO_DATE('2002-1-25', 'YYYY-MM-DD'),  8000, 4400, 'I' FROM DUAL
)
SELECT * FROM STUDENTDATA;

INSERT INTO INSTALLMENT (PROSPECTUSNO, INSTALLMENTAMT, DUEDT, PAID)
WITH INSTALLMENTDATA AS (
  SELECT 40515, 340, TO_DATE('2022-09-30', 'YYYY-MM-DD'), 'P' FROM DUAL UNION ALL
  SELECT 30336, 230, TO_DATE('2022-09-30', 'YYYY-MM-DD'), 'P' FROM DUAL UNION ALL
  SELECT 15345, 240, TO_DATE('2022-09-30', 'YYYY-MM-DD'), 'U' FROM DUAL UNION ALL
  SELECT 65459, 670, TO_DATE('2022-09-30', 'YYYY-MM-DD'), 'P' FROM DUAL UNION ALL
  SELECT 97528, 520, TO_DATE('2022-09-30', 'YYYY-MM-DD'), 'P' FROM DUAL UNION ALL
  SELECT 55850, 570, TO_DATE('2022-09-30', 'YYYY-MM-DD'), 'U' FROM DUAL UNION ALL
  SELECT 94311, 530, TO_DATE('2022-09-30', 'YYYY-MM-DD'), 'P' FROM DUAL UNION ALL
  SELECT 96858, 720, TO_DATE('2022-09-30', 'YYYY-MM-DD'), 'P' FROM DUAL UNION ALL
  SELECT 73579, 170, TO_DATE('2022-09-30', 'YYYY-MM-DD'), 'U' FROM DUAL UNION ALL
  SELECT 39524, 290, TO_DATE('2022-09-30', 'YYYY-MM-DD'), 'P' FROM DUAL UNION ALL
  SELECT 56924, 900, TO_DATE('2022-09-30', 'YYYY-MM-DD'), 'P' FROM DUAL UNION ALL
  SELECT 41867, 800, TO_DATE('2022-09-30', 'YYYY-MM-DD'), 'P' FROM DUAL
)
SELECT * FROM INSTALLMENTDATA;

INSERT INTO COURSETAKEN (PROSPECTUSNO, COURSENO, STARTDT, FULLPART, TIMESLOT, PERFORMANCE)
WITH COURSETAKENDATA AS (
  SELECT 55850, '3494', TO_DATE('2022-3-19', 'YYYY-MM-DD'),  'P', '2', 'SATISFACTORY'   FROM DUAL UNION ALL
  SELECT 30336, '2938', TO_DATE('2022-4-1', 'YYYY-MM-DD'),   'P', '2', 'SATISFACTORY'   FROM DUAL UNION ALL
  SELECT 94311, '3953', TO_DATE('2022-3-25', 'YYYY-MM-DD'),  'P', '2', 'EXCELLENT'      FROM DUAL UNION ALL
  SELECT 15345, '5839', TO_DATE('2022-9-5', 'YYYY-MM-DD'),   'P', '2', 'GOOD'           FROM DUAL UNION ALL
  SELECT 65459, '8381', TO_DATE('2022-6-4', 'YYYY-MM-DD'),   'P', '2', 'SATISFACTORY'   FROM DUAL UNION ALL
  SELECT 89292, '8098', TO_DATE('2022-4-12', 'YYYY-MM-DD'),  'F', '3', 'GOOD'           FROM DUAL UNION ALL
  SELECT 56924, '9744', TO_DATE('2022-2-1', 'YYYY-MM-DD'),   'P', '3', 'EXCELLENT'      FROM DUAL UNION ALL
  SELECT 40515, '3953', TO_DATE('2022-9-9', 'YYYY-MM-DD'),   'P', '3', 'EXCELLENT'      FROM DUAL UNION ALL
  SELECT 97257, '9744', TO_DATE('2022-1-17', 'YYYY-MM-DD'),  'F', '2', 'EXCELLENT'      FROM DUAL UNION ALL
  SELECT 43852, '3494', TO_DATE('2022-2-3', 'YYYY-MM-DD'),   'F', '2', 'EXCELLENT'      FROM DUAL UNION ALL
  SELECT 88905, '5839', TO_DATE('2022-9-10', 'YYYY-MM-DD'),  'F', '1', 'SATISFACTORY'   FROM DUAL UNION ALL
  SELECT 52238, '8381', TO_DATE('2022-8-22', 'YYYY-MM-DD'),  'F', '2', 'EXCELLENT'      FROM DUAL UNION ALL
  SELECT 39524, '2938', TO_DATE('2022-9-2', 'YYYY-MM-DD'),   'P', '3', 'GOOD'           FROM DUAL UNION ALL
  SELECT 11443, '8381', TO_DATE('2022-6-19', 'YYYY-MM-DD'),  'F', '3', 'GOOD'           FROM DUAL UNION ALL
  SELECT 73579, '8098', TO_DATE('2021-11-30', 'YYYY-MM-DD'), 'P', '3', 'UNSATISFACTORY' FROM DUAL UNION ALL
  SELECT 97528, '2926', TO_DATE('2022-1-26', 'YYYY-MM-DD'),  'P', '2', 'SATISFACTORY'   FROM DUAL UNION ALL
  SELECT 80652, '9744', TO_DATE('2022-4-29', 'YYYY-MM-DD'),  'F', '2', 'UNSATISFACTORY' FROM DUAL UNION ALL
  SELECT 96858, '3953', TO_DATE('2022-9-5', 'YYYY-MM-DD'),   'P', '1', 'EXCELLENT'      FROM DUAL UNION ALL
  SELECT 41867, '7612', TO_DATE('2022-6-18', 'YYYY-MM-DD'),  'P', '2', 'UNSATISFACTORY' FROM DUAL UNION ALL
  SELECT 96013, '8098', TO_DATE('2021-12-10', 'YYYY-MM-DD'), 'F', '3', 'UNSATISFACTORY' FROM DUAL
)
SELECT * FROM COURSETAKENDATA;
```

```
SQL> INSERT INTO COURSE (COURSENO, COURSENAME)
  2  WITH COURSEDATA AS (
  3    SELECT '2926', 'Cognitive Skills'    FROM DUAL UNION ALL
  4    SELECT '7612', 'Database Management' FROM DUAL UNION ALL
  5    SELECT '8098', 'Algorithms'          FROM DUAL UNION ALL
  6    SELECT '3953', 'R Programming'       FROM DUAL UNION ALL
  7    SELECT '3494', 'Comm. French-II'     FROM DUAL UNION ALL
  8    SELECT '8381', 'Networks'            FROM DUAL UNION ALL
  9    SELECT '9744', 'Aptitude'            FROM DUAL UNION ALL
 10    SELECT '6005', 'Machine Learning'    FROM DUAL UNION ALL
 11    SELECT '5839', 'Unix'                FROM DUAL UNION ALL
 12    SELECT '2938', 'Oracle'              FROM DUAL
 13  )
 14  SELECT * FROM COURSEDATA;

10 rows created.

SQL> INSERT INTO COURSEFEE (COURSENO, FULLPART, FEES)
  2  WITH COURSEFEEDATA AS (
  3    SELECT '2926', 'P', 8000 FROM DUAL UNION ALL
  4    SELECT '7612', 'F', 9000 FROM DUAL UNION ALL
  5    SELECT '8098', 'P', 9400 FROM DUAL UNION ALL
  6    SELECT '3953', 'F', 7200 FROM DUAL UNION ALL
  7    SELECT '3494', 'P', 4000 FROM DUAL UNION ALL
  8    SELECT '8381', 'P', 4600 FROM DUAL UNION ALL
  9    SELECT '9744', 'F', 9200 FROM DUAL UNION ALL
 10    SELECT '6005', 'F', 5500 FROM DUAL UNION ALL
 11    SELECT '5839', 'P', 8300 FROM DUAL UNION ALL
 12    SELECT '2938', 'P', 4800 FROM DUAL
 13  )
 14  SELECT * FROM COURSEFEEDATA;

10 rows created.

SQL> INSERT INTO STUDENT (PROSPECTUSNO, NAME, ADDRESS, PHONENO, DOB, TOTALAMT, AMTPAID, INSTALLMENT)
  2  WITH STUDENTDATA AS (
  3    SELECT 30336, 'Emílie Shōhei',     'Zimland',  1292801969, TO_DATE('2002-1-8', 'YYYY-MM-DD'),   7200, 0,    'I' FROM DUAL UNION ALL
  4    SELECT 80652, 'Aleksy Toivo',      'Ontgas',   8365416489, TO_DATE('2001-2-9', 'YYYY-MM-DD'),   9200, 9200, 'F' FROM DUAL UNION ALL
  5    SELECT 96013, 'Norbert Lailoken',  'Fand',     8176515222, TO_DATE('1998-8-14', 'YYYY-MM-DD'),  9400, 9400, 'F' FROM DUAL UNION ALL
  6    SELECT 43852, 'Feidlimid Adrijan', 'Zimland',  4889216273, TO_DATE('1999-11-18', 'YYYY-MM-DD'), 4000, 4000, 'F' FROM DUAL UNION ALL
  7    SELECT 55850, 'Virginia Ríghnach', 'Straford', 5769568428, TO_DATE('2002-6-14', 'YYYY-MM-DD'),  4000, 1000, 'I' FROM DUAL UNION ALL
  8    SELECT 52238, 'Aamir Jelka',       'Klaxstea', 7289156515, TO_DATE('2000-2-21', 'YYYY-MM-DD'),  4600, 4600, 'F' FROM DUAL UNION ALL
  9    SELECT 96858, 'Viola Francine',    'Volas',    6526425614, TO_DATE('2002-5-21', 'YYYY-MM-DD'),  7200, 4700, 'I' FROM DUAL UNION ALL
 10    SELECT 94311, 'Gilles Yusuf',      'Boni',     9564043944, TO_DATE('1998-3-16', 'YYYY-MM-DD'),  7200, 6200, 'I' FROM DUAL UNION ALL
 11    SELECT 56924, 'Doireann Gaëlle',   'Straford', 6592912808, TO_DATE('1998-11-29', 'YYYY-MM-DD'), 9200, 0,    'I' FROM DUAL UNION ALL
 12    SELECT 97257, 'Therapon Ayaz',     'Bedtin',   1573206254, TO_DATE('2001-4-26', 'YYYY-MM-DD'),  9200, 9200, 'F' FROM DUAL UNION ALL
 13    SELECT 15345, 'Quirino Vivek',     'Khora',    4235853677, TO_DATE('2000-10-14', 'YYYY-MM-DD'), 8300, 2700, 'I' FROM DUAL UNION ALL
 14    SELECT 39524, 'Afi Tessouat',      'Ontgas',   4332954027, TO_DATE('1998-1-21', 'YYYY-MM-DD'),  7200, 2400, 'I' FROM DUAL UNION ALL
 15    SELECT 40515, 'Susann Chisom',     'Anegan',   9187010108, TO_DATE('1999-11-30', 'YYYY-MM-DD'), 7200, 1700, 'I' FROM DUAL UNION ALL
 16    SELECT 89292, 'Martialis Hacî',    'Straford', 5301049309, TO_DATE('1999-10-19', 'YYYY-MM-DD'), 9400, 9400, 'F' FROM DUAL UNION ALL
 17    SELECT 88905, 'Chi Titilayo',      'Volas',    4847733538, TO_DATE('1996-10-19', 'YYYY-MM-DD'), 8300, 8300, 'F' FROM DUAL UNION ALL
 18    SELECT 11443, 'Nicușor Sultan',    'Ontgas',   6352625141, TO_DATE('2000-10-27', 'YYYY-MM-DD'), 4600, 4600, 'F' FROM DUAL UNION ALL
 19    SELECT 65459, 'Celyn Hilarion',    'Zimland',  8297094562, TO_DATE('1999-10-2', 'YYYY-MM-DD'),  4600, 0,    'I' FROM DUAL UNION ALL
 20    SELECT 73579, 'Úrsula Dermid',     'Khora',    5337070977, TO_DATE('2000-1-1', 'YYYY-MM-DD'),   9400, 1800, 'I' FROM DUAL UNION ALL
 21    SELECT 41867, 'Magni Mehmet',      'Boni',     3759652478, TO_DATE('1999-7-13', 'YYYY-MM-DD'),  9000, 7500, 'I' FROM DUAL UNION ALL
 22    SELECT 97528, 'Robert Shariah',    'Boni',     5829643889, TO_DATE('2002-1-25', 'YYYY-MM-DD'),  8000, 4400, 'I' FROM DUAL
 23  )
 24  SELECT * FROM STUDENTDATA;

20 rows created.

SQL> INSERT INTO INSTALLMENT (PROSPECTUSNO, INSTALLMENTAMT, DUEDT, PAID)
  2  WITH INSTALLMENTDATA AS (
  3    SELECT 40515, 340, TO_DATE('2022-09-30', 'YYYY-MM-DD'), 'P' FROM DUAL UNION ALL
  4    SELECT 30336, 230, TO_DATE('2022-09-30', 'YYYY-MM-DD'), 'P' FROM DUAL UNION ALL
  5    SELECT 15345, 240, TO_DATE('2022-09-30', 'YYYY-MM-DD'), 'U' FROM DUAL UNION ALL
  6    SELECT 65459, 670, TO_DATE('2022-09-30', 'YYYY-MM-DD'), 'P' FROM DUAL UNION ALL
  7    SELECT 97528, 520, TO_DATE('2022-09-30', 'YYYY-MM-DD'), 'P' FROM DUAL UNION ALL
  8    SELECT 55850, 570, TO_DATE('2022-09-30', 'YYYY-MM-DD'), 'U' FROM DUAL UNION ALL
  9    SELECT 94311, 530, TO_DATE('2022-09-30', 'YYYY-MM-DD'), 'P' FROM DUAL UNION ALL
 10    SELECT 96858, 720, TO_DATE('2022-09-30', 'YYYY-MM-DD'), 'P' FROM DUAL UNION ALL
 11    SELECT 73579, 170, TO_DATE('2022-09-30', 'YYYY-MM-DD'), 'U' FROM DUAL UNION ALL
 12    SELECT 39524, 290, TO_DATE('2022-09-30', 'YYYY-MM-DD'), 'P' FROM DUAL UNION ALL
 13    SELECT 56924, 900, TO_DATE('2022-09-30', 'YYYY-MM-DD'), 'P' FROM DUAL UNION ALL
 14    SELECT 41867, 800, TO_DATE('2022-09-30', 'YYYY-MM-DD'), 'P' FROM DUAL
 15  )
 16  SELECT * FROM INSTALLMENTDATA;

12 rows created.

SQL> INSERT INTO COURSETAKEN (PROSPECTUSNO, COURSENO, STARTDT, FULLPART, TIMESLOT, PERFORMANCE)
  2  WITH COURSETAKENDATA AS (
  3    SELECT 55850, '3494', TO_DATE('2022-3-19', 'YYYY-MM-DD'),  'P', '2', 'SATISFACTORY'   FROM DUAL UNION ALL
  4    SELECT 30336, '2938', TO_DATE('2022-4-1', 'YYYY-MM-DD'),   'P', '2', 'SATISFACTORY'   FROM DUAL UNION ALL
  5    SELECT 94311, '3953', TO_DATE('2022-3-25', 'YYYY-MM-DD'),  'P', '2', 'EXCELLENT'      FROM DUAL UNION ALL
  6    SELECT 15345, '5839', TO_DATE('2022-9-5', 'YYYY-MM-DD'),   'P', '2', 'GOOD'           FROM DUAL UNION ALL
  7    SELECT 65459, '8381', TO_DATE('2022-6-4', 'YYYY-MM-DD'),   'P', '2', 'SATISFACTORY'   FROM DUAL UNION ALL
  8    SELECT 89292, '8098', TO_DATE('2022-4-12', 'YYYY-MM-DD'),  'F', '3', 'GOOD'           FROM DUAL UNION ALL
  9    SELECT 56924, '9744', TO_DATE('2022-2-1', 'YYYY-MM-DD'),   'P', '3', 'EXCELLENT'      FROM DUAL UNION ALL
 10    SELECT 40515, '3953', TO_DATE('2022-9-9', 'YYYY-MM-DD'),   'P', '3', 'EXCELLENT'      FROM DUAL UNION ALL
 11    SELECT 97257, '9744', TO_DATE('2022-1-17', 'YYYY-MM-DD'),  'F', '2', 'EXCELLENT'      FROM DUAL UNION ALL
 12    SELECT 43852, '3494', TO_DATE('2022-2-3', 'YYYY-MM-DD'),   'F', '2', 'EXCELLENT'      FROM DUAL UNION ALL
 13    SELECT 88905, '5839', TO_DATE('2022-9-10', 'YYYY-MM-DD'),  'F', '1', 'SATISFACTORY'   FROM DUAL UNION ALL
 14    SELECT 52238, '8381', TO_DATE('2022-8-22', 'YYYY-MM-DD'),  'F', '2', 'EXCELLENT'      FROM DUAL UNION ALL
 15    SELECT 39524, '2938', TO_DATE('2022-9-2', 'YYYY-MM-DD'),   'P', '3', 'GOOD'           FROM DUAL UNION ALL
 16    SELECT 11443, '8381', TO_DATE('2022-6-19', 'YYYY-MM-DD'),  'F', '3', 'GOOD'           FROM DUAL UNION ALL
 17    SELECT 73579, '8098', TO_DATE('2021-11-30', 'YYYY-MM-DD'), 'P', '3', 'UNSATISFACTORY' FROM DUAL UNION ALL
 18    SELECT 97528, '2926', TO_DATE('2022-1-26', 'YYYY-MM-DD'),  'P', '2', 'SATISFACTORY'   FROM DUAL UNION ALL
 19    SELECT 80652, '9744', TO_DATE('2022-4-29', 'YYYY-MM-DD'),  'F', '2', 'UNSATISFACTORY' FROM DUAL UNION ALL
 20    SELECT 96858, '3953', TO_DATE('2022-9-5', 'YYYY-MM-DD'),   'P', '1', 'EXCELLENT'      FROM DUAL UNION ALL
 21    SELECT 41867, '7612', TO_DATE('2022-6-18', 'YYYY-MM-DD'),  'P', '2', 'UNSATISFACTORY' FROM DUAL UNION ALL
 22    SELECT 96013, '8098', TO_DATE('2021-12-10', 'YYYY-MM-DD'), 'F', '3', 'UNSATISFACTORY' FROM DUAL
 23  )
 24  SELECT * FROM COURSETAKENDATA;

20 rows created.
```

## Queries
1. Retrieve name and course number of all students.
```sql
SELECT S.NAME, CT.COURSENO
FROM STUDENT S, COURSETAKEN CT
WHERE S.PROSPECTUSNO = CT.PROSPECTUSNO;
```

```
SQL> SELECT S.NAME, CT.COURSENO
  2  FROM STUDENT S, COURSETAKEN CT
  3  WHERE S.PROSPECTUSNO = CT.PROSPECTUSNO;

NAME                 | COUR
-------------------- | ----
Virginia Ríghnach    | 3494
Emílie Shohei        | 2938
Gilles Yusuf         | 3953
Quirino Vivek        | 5839
Celyn Hilarion       | 8381
Martialis Hacî       | 8098
Doireann Gaëlle      | 9744
Susann Chisom        | 3953
Therapon Ayaz        | 9744
Feidlimid Adrijan    | 3494
Chi Titilayo         | 5839
Aamir Jelka          | 8381
Afi Tessouat         | 2938
Nicu?or Sultan       | 8381
Ursula Dermid        | 8098
Robert Shariah       | 2926
Aleksy Toivo         | 9744
Viola Francine       | 3953
Magni Mehmet         | 7612
Norbert Lailoken     | 8098

20 rows selected.
```

2. List the names of students who have paid the full amount at the time of admission.
```sql
SELECT S.NAME
FROM STUDENT S
WHERE S.TOTALAMT = S.AMTPAID;
```

```
SQL> SELECT S.NAME
  2  FROM STUDENT S
  3  WHERE S.TOTALAMT = S.AMTPAID;

NAME
--------------------
Aleksy Toivo
Norbert Lailoken
Feidlimid Adrijan
Aamir Jelka
Therapon Ayaz
Martialis Hacî
Chi Titilayo
Nicu?or Sultan

8 rows selected.
```

3. Find the names of students starting with `A`.
```sql
SELECT S.NAME
FROM STUDENT S
WHERE S.NAME LIKE 'A%';
```

```
SQL> SELECT S.NAME
  2  FROM STUDENT S
  3  WHERE S.NAME LIKE 'A%';

NAME
--------------------
Aleksy Toivo
Aamir Jelka
Afi Tessouat
```

4. Print the names of students whose total amount is not equal to amount due.
```sql
SELECT S.NAME
FROM STUDENT S
WHERE S.TOTALAMT <> (S.TOTALAMT - S.AMTPAID);
```

```
SQL> SELECT S.NAME
  2  FROM STUDENT S
  3  WHERE S.TOTALAMT <> (S.TOTALAMT - S.AMTPAID);

NAME
--------------------
Aleksy Toivo
Norbert Lailoken
Feidlimid Adrijan
Virginia Ríghnach
Aamir Jelka
Viola Francine
Gilles Yusuf
Therapon Ayaz
Quirino Vivek
Afi Tessouat
Susann Chisom
Martialis Hacî
Chi Titilayo
Nicu?or Sultan
Ursula Dermid
Magni Mehmet
Robert Shariah

17 rows selected.
```

5. Count the number of students who have joined in the current year, current month.
```sql
-- ASSUME THAT CURRENT DATE IS SEPTEMBER 15TH, 2022. TODAY'S DATE IS STORED IN THE SYSDATE VARIABLE IN ORACLE
SELECT COUNT(*)
FROM COURSETAKEN CT
WHERE TO_CHAR(CT.STARTDT, 'MONTH') = TO_CHAR(TO_DATE('2022-09-15', 'YYYY-MM-DD'), 'MONTH');
```

```
SQL> -- ASSUME THAT CURRENT DATE IS SEPTEMBER 15TH, 2022. TODAY'S DATE IS STORED IN THE SYSDATE VARIABLE IN ORACLE
SQL> SELECT COUNT(*)
  2  FROM COURSETAKEN CT
  3  WHERE TO_CHAR(CT.STARTDT, 'MONTH') = TO_CHAR(TO_DATE('2022-09-15', 'YYYY-MM-DD'), 'MONTH');

  COUNT(*)
----------
         5
```
6. Determine the maximum and minimum course fees.
```sql
SELECT C.COURSENO, C.COURSENAME, CF.FEES
FROM COURSE C, COURSEFEE CF
WHERE C.COURSENO = CF.COURSENO AND (
  CF.FEES = (
    SELECT MAX(CF.FEES) FROM COURSEFEE CF
  ) OR CF.FEES = (
    SELECT MIN(CF.FEES) FROM COURSEFEE CF
  )
);
```

```
SQL> SELECT C.COURSENO, C.COURSENAME, CF.FEES
  2  FROM COURSE C, COURSEFEE CF
  3  WHERE C.COURSENO = CF.COURSENO AND (
  4    CF.FEES = (
  5      SELECT MAX(CF.FEES) FROM COURSEFEE CF
  6    ) OR CF.FEES = (
  7      SELECT MIN(CF.FEES) FROM COURSEFEE CF
  8    )
  9  );

COUR | COURSENAME                     |       FEES
---- | ------------------------------ | ----------
8098 | Algorithms                     |       9400
3494 | Comm. French-II                |       4000
```

7. Increase the fee of `oracle` by $50\%$.
```sql
SELECT C.COURSENO, C.COURSENAME, CF.FEES
FROM COURSE C, COURSEFEE CF
WHERE C.COURSENO = CF.COURSENO AND C.COURSENAME = 'Oracle';

UPDATE COURSEFEE CF
SET CF.FEES = CF.FEES * 1.5
WHERE CF.COURSENO = (
  SELECT C.COURSENO
  FROM COURSE C
  WHERE C.COURSENAME = 'Oracle'
);

SELECT C.COURSENO, C.COURSENAME, CF.FEES
FROM COURSE C, COURSEFEE CF
WHERE C.COURSENO = CF.COURSENO AND C.COURSENAME = 'Oracle';
```

```
SQL> SELECT C.COURSENO, C.COURSENAME, CF.FEES
  2  FROM COURSE C, COURSEFEE CF
  3  WHERE C.COURSENO = CF.COURSENO AND C.COURSENAME = 'Oracle';

COUR | COURSENAME                     |       FEES
---- | ------------------------------ | ----------
2938 | Oracle                         |       4800

SQL> UPDATE COURSEFEE CF
  2  SET CF.FEES = CF.FEES * 1.5
  3  WHERE CF.COURSENO = (
  4    SELECT C.COURSENO
  5    FROM COURSE C
  6    WHERE C.COURSENAME = 'Oracle'
  7  );

1 row updated.

SQL> SELECT C.COURSENO, C.COURSENAME, CF.FEES
  2  FROM COURSE C, COURSEFEE CF
  3  WHERE C.COURSENO = CF.COURSENO AND C.COURSENAME = 'Oracle';

COUR | COURSENAME                     |       FEES
---- | ------------------------------ | ----------
2938 | Oracle                         |       7200
```

8. Print the details of courses whose fees are between $5000$ and $10000$.
```sql
SELECT C.COURSENO, C.COURSENAME, CF.FEES
FROM COURSE C, COURSEFEE CF
WHERE C.COURSENO = CF.COURSENO AND CF.FEES BETWEEN 5000 AND 10000;
```

```
SQL> SELECT C.COURSENO, C.COURSENAME, CF.FEES
  2  FROM COURSE C, COURSEFEE CF
  3  WHERE C.COURSENO = CF.COURSENO AND CF.FEES BETWEEN 5000 AND 10000;

COUR | COURSENAME                     |       FEES
---- | ------------------------------ | ----------
2926 | Cognitive Skills               |       8000
7612 | Database Management            |       9000
8098 | Algorithms                     |       9400
3953 | R Programming                  |       7200
9744 | Aptitude                       |       9200
6005 | Machine Learning               |       5500
5839 | Unix                           |       8300
2938 | Oracle                         |       7200

8 rows selected.
```

9. Display the admission date in `Date, Month, Year` format.
```sql
SELECT S.PROSPECTUSNO, S.NAME, CT.COURSENO, TO_CHAR(CT.STARTDT, 'DD Month, YYYY') AS LONGDATE
FROM STUDENT S, COURSETAKEN CT
WHERE S.PROSPECTUSNO = CT.PROSPECTUSNO;
```

```
SQL> SELECT S.PROSPECTUSNO, S.NAME, CT.COURSENO, TO_CHAR(CT.STARTDT, 'DD Month, YYYY') AS LONGDATE
  2  FROM STUDENT S, COURSETAKEN CT
  3  WHERE S.PROSPECTUSNO = CT.PROSPECTUSNO;

PROSPECTUSNO | NAME                 | COUR | LONGDATE
------------ | -------------------- | ---- | ---------------------------------------------
       55850 | Virginia Ríghnach    | 3494 | 19 March    , 2022
       30336 | Emílie Shohei        | 2938 | 01 April    , 2022
       94311 | Gilles Yusuf         | 3953 | 25 March    , 2022
       15345 | Quirino Vivek        | 5839 | 05 September, 2022
       65459 | Celyn Hilarion       | 8381 | 04 June     , 2022
       89292 | Martialis Hacî       | 8098 | 12 April    , 2022
       56924 | Doireann Gaëlle      | 9744 | 01 February , 2022
       40515 | Susann Chisom        | 3953 | 09 September, 2022
       97257 | Therapon Ayaz        | 9744 | 17 January  , 2022
       43852 | Feidlimid Adrijan    | 3494 | 03 February , 2022
       88905 | Chi Titilayo         | 5839 | 10 September, 2022
       52238 | Aamir Jelka          | 8381 | 22 August   , 2022
       39524 | Afi Tessouat         | 2938 | 02 September, 2022
       11443 | Nicu?or Sultan       | 8381 | 19 June     , 2022
       73579 | Ursula Dermid        | 8098 | 30 November , 2021
       97528 | Robert Shariah       | 2926 | 26 January  , 2022
       80652 | Aleksy Toivo         | 9744 | 29 April    , 2022
       96858 | Viola Francine       | 3953 | 05 September, 2022
       41867 | Magni Mehmet         | 7612 | 18 June     , 2022
       96013 | Norbert Lailoken     | 8098 | 10 December , 2021

20 rows selected.
```

10. Find out in which course maximum number of students have taken admission.
```sql
SELECT COURSENO, COURSENAME, COUNT(*) AS STUDENTCOUNT
FROM COURSE JOIN COURSETAKEN USING(COURSENO)
GROUP BY COURSENO, COURSENAME
HAVING COUNT(*) = (
  SELECT MAX(COUNT(*))
  FROM COURSE JOIN COURSETAKEN USING(COURSENO)
  GROUP BY COURSENO
);
```

```
SQL> SELECT COURSENO, COURSENAME, COUNT(*) AS STUDENTCOUNT
  2  FROM COURSE JOIN COURSETAKEN USING(COURSENO)
  3  GROUP BY COURSENO, COURSENAME
  4  HAVING COUNT(*) = (
  5    SELECT MAX(COUNT(*))
  6    FROM COURSE JOIN COURSETAKEN USING(COURSENO)
  7    GROUP BY COURSENO
  8  );

COUR | COURSENAME                     | STUDENTCOUNT
---- | ------------------------------ | ------------
3953 | R Programming                  |            3
8381 | Networks                       |            3
8098 | Algorithms                     |            3
9744 | Aptitude                       |            3
```

11. Change the `course_name` from `Unix` to `Unix Operating System`.
```sql
SELECT C.COURSENAME
FROM COURSE C;

UPDATE COURSE
SET COURSENAME = 'Unix Operating System'
WHERE COURSENAME = 'Unix';

SELECT C.COURSENAME
FROM COURSE C;
```

```
SQL> SELECT C.COURSENAME
  2  FROM COURSE C;

COURSENAME
------------------------------
Cognitive Skills
Database Management
Algorithms
R Programming
Comm. French-II
Networks
Aptitude
Machine Learning
Unix
Oracle

10 rows selected.

SQL> UPDATE COURSE
  2  SET COURSENAME = 'Unix Operating System'
  3  WHERE COURSENAME = 'Unix';

1 row updated.

SQL> SELECT C.COURSENAME
  2  FROM COURSE C;

COURSENAME
------------------------------
Cognitive Skills
Database Management
Algorithms
R Programming
Comm. French-II
Networks
Aptitude
Machine Learning
Unix Operating System
Oracle

10 rows selected.
```

12. Display the admission style in `DD-MONTH-YYYY` format.
```sql
SELECT CT.PROSPECTUSNO, CT.COURSENO, TO_CHAR(CT.STARTDT, 'DD-MONTH-YYYY')
FROM COURSETAKEN CT;
```

```
SQL> SELECT CT.PROSPECTUSNO, CT.COURSENO, TO_CHAR(CT.STARTDT, 'DD-MONTH-YYYY')
  2  FROM COURSETAKEN CT;

PROSPECTUSNO | COUR | TO_CHAR(CT.STARTDT,'DD-MONTH-YYYY')
------------ | ---- | --------------------------------------------
       55850 | 3494 | 19-MARCH    -2022
       30336 | 2938 | 01-APRIL    -2022
       94311 | 3953 | 25-MARCH    -2022
       15345 | 5839 | 05-SEPTEMBER-2022
       65459 | 8381 | 04-JUNE     -2022
       89292 | 8098 | 12-APRIL    -2022
       56924 | 9744 | 01-FEBRUARY -2022
       40515 | 3953 | 09-SEPTEMBER-2022
       97257 | 9744 | 17-JANUARY  -2022
       43852 | 3494 | 03-FEBRUARY -2022
       88905 | 5839 | 10-SEPTEMBER-2022
       52238 | 8381 | 22-AUGUST   -2022
       39524 | 2938 | 02-SEPTEMBER-2022
       11443 | 8381 | 19-JUNE     -2022
       73579 | 8098 | 30-NOVEMBER -2021
       97528 | 2926 | 26-JANUARY  -2022
       80652 | 9744 | 29-APRIL    -2022
       96858 | 3953 | 05-SEPTEMBER-2022
       41867 | 7612 | 18-JUNE     -2022
       96013 | 8098 | 10-DECEMBER -2021

20 rows selected.
```

13. Get the sum of amount to be collected from students in this month.
```sql
-- ASSUMING THAT THE CURRENT MONTH IS SEPTEMBER
SELECT SUM(I.INSTALLMENTAMT) AS AMOUNT
FROM INSTALLMENT I
WHERE TO_CHAR(I.DUEDT, 'MONTH') = 'SEPTEMBER';
```

```
SQL> -- ASSUMING THAT THE CURRENT MONTH IS SEPTEMBER
SQL> SELECT SUM(I.INSTALLMENTAMT) AS AMOUNT
  2  FROM INSTALLMENT I
  3  WHERE TO_CHAR(I.DUEDT, 'MONTH') = 'SEPTEMBER';

    AMOUNT
----------
      5980
```

14. Find out in which course the maximum number of studenta have taken admission in the current month.
```sql
-- ASSUMING THAT THE CURRENT MONTH IS SEPTEMBER
SELECT COURSENO, COURSENAME, COUNT(*) AS COURSECOUNT
FROM COURSETAKEN JOIN COURSE USING(COURSENO)
GROUP BY COURSENO, COURSENAME
HAVING COUNT(*) = (
  SELECT MAX(COUNT(*))
  FROM COURSETAKEN CT
  WHERE TO_CHAR(CT.STARTDT, 'MONTH') = 'SEPTEMBER'
  GROUP BY CT.COURSENO
);
```

```
SQL> -- ASSUMING THAT THE CURRENT MONTH IS SEPTEMBER
SQL> SELECT COURSENO, COURSENAME, COUNT(*) AS COURSECOUNT
  2  FROM COURSETAKEN JOIN COURSE USING(COURSENO)
  3  GROUP BY COURSENO, COURSENAME
  4  HAVING COUNT(*) = (
  5    SELECT MAX(COUNT(*))
  6    FROM COURSETAKEN CT
  7    WHERE TO_CHAR(CT.STARTDT, 'MONTH') = 'SEPTEMBER'
  8    GROUP BY CT.COURSENO
  9  );

COUR | COURSENAME                     | COURSECOUNT
---- | ------------------------------ | -----------
3494 | Comm. French-II                |           2
2938 | Oracle                         |           2
5839 | Unix Operating System          |           2
```

15. Select the students who have not yet paid full amount of fees.
```sql
SELECT S.PROSPECTUSNO, S.NAME, (S.TOTALAMT - S.AMTPAID) AS AMTDUE
FROM STUDENT S
WHERE S.TOTALAMT - S.AMTPAID > 0;
```

```
SQL> SELECT S.PROSPECTUSNO, S.NAME, (S.TOTALAMT - S.AMTPAID) AS AMTDUE
  2  FROM STUDENT S
  3  WHERE S.TOTALAMT - S.AMTPAID > 0;

PROSPECTUSNO | NAME                 |     AMTDUE
------------ | -------------------- | ----------
       30336 | Emílie Shohei        |       7200
       55850 | Virginia Ríghnach    |       3000
       96858 | Viola Francine       |       2500
       94311 | Gilles Yusuf         |       1000
       56924 | Doireann Gaëlle      |       9200
       15345 | Quirino Vivek        |       5600
       39524 | Afi Tessouat         |       4800
       40515 | Susann Chisom        |       5500
       65459 | Celyn Hilarion       |       4600
       73579 | Ursula Dermid        |       7600
       41867 | Magni Mehmet         |       1500
       97528 | Robert Shariah       |       3600

12 rows selected.
```

# Q2.
## Table Schema
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
  PRNO
  JNO
  QTY
```

## Table Creation
```sql
CREATE TABLE SUPPLIER (
  SNO    NUMBER(5)   NOT NULL PRIMARY KEY,
  SNAME  VARCHAR(10) NOT NULL UNIQUE,
  STATUS CHAR(11)
  CHECK (
    STATUS = 'WORKING'
    OR STATUS = 'NOT WORKING'
  ),
  CITY   VARCHAR(10)
);

CREATE TABLE PARTS (
  PNO    NUMBER(5)   NOT NULL PRIMARY KEY,
  PNAME  VARCHAR(10) NOT NULL UNIQUE,
  COLOR  VARCHAR(10) NOT NULL,
  WEIGHT NUMBER(5),
  CITY   VARCHAR(10)
);

CREATE TABLE PROJECT (
  JNO   NUMBER(5)  NOT NULL PRIMARY KEY,
  JNAME VARCHAR(10) NOT NULL UNIQUE,
  CITY  VARCHAR(10)
);

CREATE TABLE SPJ (
  SNO NUMBER(5) NOT NULL,
  PNO NUMBER(5) NOT NULL,
  JNO NUMBER(5) NOT NULL,
  QTY NUMBER(5) NOT NULL,
  CONSTRAINT FKSNO
    FOREIGN KEY(SNO)
    REFERENCES SUPPLIER(SNO)
    ON DELETE CASCADE,
  CONSTRAINT FKPNO
    FOREIGN KEY(PNO)
    REFERENCES PARTS(PNO)
    ON DELETE CASCADE,
  CONSTRAINT FKJNO
    FOREIGN KEY(JNO)
    REFERENCES PROJECT(JNO)
    ON DELETE CASCADE
);
```

```
SQL> CREATE TABLE SUPPLIER (
  2    SNO    NUMBER(5)   NOT NULL PRIMARY KEY,
  3    SNAME  VARCHAR(10) NOT NULL UNIQUE,
  4    STATUS CHAR(11)
  5    CHECK (
  6      STATUS = 'WORKING'
  7      OR STATUS = 'NOT WORKING'
  8    ),
  9    CITY   VARCHAR(10)
 10  );

Table created.

SQL> CREATE TABLE PARTS (
  2    PNO    NUMBER(5)   NOT NULL PRIMARY KEY,
  3    PNAME  VARCHAR(10) NOT NULL UNIQUE,
  
```sql
  INSERT INTO SUPPLIER(SNO, SNAME, STATUS, CITY)
  WITH SUPPLIERDATA AS (
    
  )
  ```
  4    COLOR  VARCHAR(10) NOT NULL,
  
```sql
  INSERT INTO SUPPLIER(SNO, SNAME, STATUS, CITY)
  WITH SUPPLIERDATA AS (
    
  )
  ```
  5    WEIGHT NUMBER(5),
  
```sql
  INSERT INTO SUPPLIER(SNO, SNAME, STATUS, CITY)
  WITH SUPPLIERDATA AS (
    
  )
  ```
  6    CITY   VARCHAR(10)
  
```sql
  INSERT INTO SUPPLIER(SNO, SNAME, STATUS, CITY)
  WITH SUPPLIERDATA AS (
    
  )
  ```
  7  );
  
```sql
  INSERT INTO SUPPLIER(SNO, SNAME, STATUS, CITY)
  WITH SUPPLIERDATA AS (
    
  )
  ```

```sql
INSERT INTO SUPPLIER(SNO, SNAME, STATUS, CITY)
WITH SUPPLIERDATA AS (
  
)
```
Table created.
```sql
INSERT INTO SUPPLIER(SNO, SNAME, STATUS, CITY)
WITH SUPPLIERDATA AS (
  
)
```

```sql
INSERT INTO SUPPLIER(SNO, SNAME, STATUS, CITY)
WITH SUPPLIERDATA AS (
  
)
```

```
SQL> CREATE TABLE PROJECT (
  2    JNO   NUMBER(5)  NOT NULL PRIMARY KEY,
  3    JNAME VARCHAR(10) NOT NULL UNIQUE,
  4    CITY  VARCHAR(10)
  5  );

Table created.

SQL> CREATE TABLE SPJ (
  2    SNO NUMBER(5) NOT NULL,
  3    PNO NUMBER(5) NOT NULL,
  4    JNO NUMBER(5) NOT NULL,
  5    QTY NUMBER(5) NOT NULL,
  6    CONSTRAINT FKSNO
  7      FOREIGN KEY(SNO)
  8      REFERENCES SUPPLIER(SNO)
  9      ON DELETE CASCADE,
 10    CONSTRAINT FKPNO
 11      FOREIGN KEY(PNO)
 12      REFERENCES PARTS(PNO)
 13      ON DELETE CASCADE,
 14    CONSTRAINT FKJNO
 15      FOREIGN KEY(JNO)
 16      REFERENCES PROJECT(JNO)
 17      ON DELETE CASCADE
 18  );

Table created.
```

## Data Entry

```sql
INSERT INTO SUPPLIER(SNO, SNAME, STATUS, CITY)
WITH SUPPLIERDATA AS (
  SELECT 12579, 's1',  'NOT WORKING', 'Paris'  FROM DUAL UNION ALL
  SELECT 14677, 's2',  'WORKING',     'Berlin' FROM DUAL UNION ALL
  SELECT 19187, 's3',  'WORKING',     'Paris'  FROM DUAL UNION ALL
  SELECT 19379, 's4',  'WORKING',     'Vienna' FROM DUAL UNION ALL
  SELECT 17967, 's5',  'WORKING',     'Madrid' FROM DUAL UNION ALL
  SELECT 11048, 's6',  'WORKING',     'London' FROM DUAL UNION ALL
  SELECT 19690, 's7',  'NOT WORKING', 'Madrid' FROM DUAL UNION ALL
  SELECT 11859, 's8',  'WORKING',     'London' FROM DUAL UNION ALL
  SELECT 16240, 's9',  'WORKING',     'Madrid' FROM DUAL UNION ALL
  SELECT 15525, 's10', 'NOT WORKING', 'Madrid' FROM DUAL UNION ALL
  SELECT 10070, 's11', 'WORKING',     'Paris'  FROM DUAL UNION ALL
  SELECT 17100, 's12', 'WORKING',     'Madrid' FROM DUAL UNION ALL
  SELECT 11500, 's13', 'WORKING',     'Paris'  FROM DUAL UNION ALL
  SELECT 16518, 's14', 'WORKING',     'London' FROM DUAL UNION ALL
  SELECT 11230, 's15', 'WORKING',     'Vienna' FROM DUAL UNION ALL
  SELECT 18900, 's16', 'WORKING',     'Madrid' FROM DUAL UNION ALL
  SELECT 18643, 's17', 'WORKING',     'Vienna' FROM DUAL UNION ALL
  SELECT 19568, 's18', 'WORKING',     'Madrid' FROM DUAL UNION ALL
  SELECT 15739, 's19', 'WORKING',     'Madrid' FROM DUAL UNION ALL
  SELECT 18021, 's20', 'NOT WORKING', 'Berlin' FROM DUAL
)
SELECT * FROM SUPPLIERDATA;

INSERT INTO PARTS(PNO, PNAME, COLOR, WEIGHT, CITY)
WITH PARTSDATA AS (
  SELECT 25203, 'p1',  'Blue',   150, 'London' FROM DUAL UNION ALL
  SELECT 28326, 'p2',  'Red',    140, 'Paris'  FROM DUAL UNION ALL
  SELECT 21837, 'p3',  'Blue',   150, 'Paris'  FROM DUAL UNION ALL
  SELECT 21435, 'p4',  'Black',  110, 'London' FROM DUAL UNION ALL
  SELECT 26383, 'p5',  'Yellow', 190, 'Madrid' FROM DUAL UNION ALL
  SELECT 27083, 'p6',  'Green',  180, 'Vienna' FROM DUAL UNION ALL
  SELECT 28631, 'p7',  'Green',  190, 'Vienna' FROM DUAL UNION ALL
  SELECT 25212, 'p8',  'Blue',   200, 'Paris'  FROM DUAL UNION ALL
  SELECT 29445, 'p9',  'Black',  120, 'London' FROM DUAL UNION ALL
  SELECT 23187, 'p10', 'Red',    170, 'Berlin' FROM DUAL UNION ALL
  SELECT 29609, 'p11', 'Blue',   150, 'Paris'  FROM DUAL UNION ALL
  SELECT 25025, 'p12', 'Red',    170, 'Paris'  FROM DUAL UNION ALL
  SELECT 28842, 'p13', 'Black',  100, 'Paris'  FROM DUAL UNION ALL
  SELECT 24396, 'p14', 'Black',  150, 'Berlin' FROM DUAL UNION ALL
  SELECT 28173, 'p15', 'Blue',   160, 'Vienna' FROM DUAL UNION ALL
  SELECT 29457, 'p16', 'Yellow', 110, 'Vienna' FROM DUAL UNION ALL
  SELECT 20876, 'p17', 'Red',    150, 'Berlin' FROM DUAL UNION ALL
  SELECT 26749, 'p18', 'Green',  160, 'Berlin' FROM DUAL UNION ALL
  SELECT 26188, 'p19', 'Red',    100, 'London' FROM DUAL UNION ALL
  SELECT 29224, 'p20', 'Green',  120, 'Vienna' FROM DUAL
)
SELECT * FROM PARTSDATA;

INSERT INTO PROJECT (JNO, JNAME, CITY)
WITH PROJECTDATA AS (
  SELECT 35986, 'j1',  'Paris'  FROM DUAL UNION ALL
  SELECT 31438, 'j2',  'London' FROM DUAL UNION ALL
  SELECT 39299, 'j3',  'Berlin' FROM DUAL UNION ALL
  SELECT 37650, 'j4',  'Paris'  FROM DUAL UNION ALL
  SELECT 35151, 'j5',  'Berlin' FROM DUAL UNION ALL
  SELECT 37114, 'j6',  'London' FROM DUAL UNION ALL
  SELECT 37474, 'j7',  'Vienna' FROM DUAL UNION ALL
  SELECT 34872, 'j8',  'Madrid' FROM DUAL UNION ALL
  SELECT 33604, 'j9',  'London' FROM DUAL UNION ALL
  SELECT 33104, 'j10', 'Vienna' FROM DUAL
)
SELECT * FROM PROJECTDATA;

INSERT INTO SPJ (SNO, PNO, JNO, QTY)
WITH SPJDATA AS (
  SELECT 14677, 26188, 39299, 11 FROM DUAL UNION ALL
  SELECT 16518, 28326, 35986, 14 FROM DUAL UNION ALL
  SELECT 11230, 21837, 33604, 20 FROM DUAL UNION ALL
  SELECT 18643, 29609, 33604, 2  FROM DUAL UNION ALL
  SELECT 19690, 29224, 37650, 19 FROM DUAL UNION ALL
  SELECT 19568, 24396, 33604, 11 FROM DUAL UNION ALL
  SELECT 12579, 25203, 35151, 8  FROM DUAL UNION ALL
  SELECT 18900, 21435, 37650, 2  FROM DUAL UNION ALL
  SELECT 11500, 25025, 37474, 7  FROM DUAL UNION ALL
  SELECT 16240, 29445, 37114, 7  FROM DUAL UNION ALL
  SELECT 19379, 25203, 35986, 4  FROM DUAL UNION ALL
  SELECT 17967, 27083, 33104, 1  FROM DUAL UNION ALL
  SELECT 10070, 25212, 35986, 12 FROM DUAL UNION ALL
  SELECT 11859, 28842, 34872, 6  FROM DUAL UNION ALL
  SELECT 18021, 25203, 34872, 9  FROM DUAL UNION ALL
  SELECT 16518, 28631, 31438, 12 FROM DUAL UNION ALL
  SELECT 17100, 26749, 37650, 16 FROM DUAL UNION ALL
  SELECT 15739, 23187, 35151, 7  FROM DUAL UNION ALL
  SELECT 15525, 26383, 37114, 17 FROM DUAL UNION ALL
  SELECT 19187, 20876, 33604, 9  FROM DUAL UNION ALL
  SELECT 18900, 26383, 35986, 13 FROM DUAL UNION ALL
  SELECT 18900, 26383, 31438, 1  FROM DUAL UNION ALL
  SELECT 18900, 26383, 39299, 18 FROM DUAL UNION ALL
  SELECT 18900, 26383, 37650, 1  FROM DUAL UNION ALL
  SELECT 18900, 26383, 35151, 19 FROM DUAL UNION ALL
  SELECT 18900, 26383, 37114, 11 FROM DUAL UNION ALL
  SELECT 18900, 26383, 37474, 7  FROM DUAL UNION ALL
  SELECT 18900, 26383, 34872, 1  FROM DUAL UNION ALL
  SELECT 18900, 26383, 33604, 9  FROM DUAL UNION ALL
  SELECT 18900, 26383, 33104, 16 FROM DUAL
)
SELECT * FROM SPJDATA;
```

```
SQL> INSERT INTO SUPPLIER(SNO, SNAME, STATUS, CITY)
  2  WITH SUPPLIERDATA AS (
  3    SELECT 12579, 's1',  'NOT WORKING', 'Paris'  FROM DUAL UNION ALL
  4    SELECT 14677, 's2',  'WORKING',     'Berlin' FROM DUAL UNION ALL
  5    SELECT 19187, 's3',  'WORKING',     'Paris'  FROM DUAL UNION ALL
  6    SELECT 19379, 's4',  'WORKING',     'Vienna' FROM DUAL UNION ALL
  7    SELECT 17967, 's5',  'WORKING',     'Madrid' FROM DUAL UNION ALL
  8    SELECT 11048, 's6',  'WORKING',     'London' FROM DUAL UNION ALL
  9    SELECT 19690, 's7',  'NOT WORKING', 'Madrid' FROM DUAL UNION ALL
 10    SELECT 11859, 's8',  'WORKING',     'London' FROM DUAL UNION ALL
 11    SELECT 16240, 's9',  'WORKING',     'Madrid' FROM DUAL UNION ALL
 12    SELECT 15525, 's10', 'NOT WORKING', 'Madrid' FROM DUAL UNION ALL
 13    SELECT 10070, 's11', 'WORKING',     'Paris'  FROM DUAL UNION ALL
 14    SELECT 17100, 's12', 'WORKING',     'Madrid' FROM DUAL UNION ALL
 15    SELECT 11500, 's13', 'WORKING',     'Paris'  FROM DUAL UNION ALL
 16    SELECT 16518, 's14', 'WORKING',     'London' FROM DUAL UNION ALL
 17    SELECT 11230, 's15', 'WORKING',     'Vienna' FROM DUAL UNION ALL
 18    SELECT 18900, 's16', 'WORKING',     'Madrid' FROM DUAL UNION ALL
 19    SELECT 18643, 's17', 'WORKING',     'Vienna' FROM DUAL UNION ALL
 20    SELECT 19568, 's18', 'WORKING',     'Madrid' FROM DUAL UNION ALL
 21    SELECT 15739, 's19', 'WORKING',     'Madrid' FROM DUAL UNION ALL
 22    SELECT 18021, 's20', 'NOT WORKING', 'Berlin' FROM DUAL
 23  )
 24  SELECT * FROM SUPPLIERDATA;

20 rows created.

SQL> INSERT INTO PARTS(PNO, PNAME, COLOR, WEIGHT, CITY)
  2  WITH PARTSDATA AS (
  3    SELECT 25203, 'p1',  'Blue',   150, 'London' FROM DUAL UNION ALL
  4    SELECT 28326, 'p2',  'Red',    140, 'Paris'  FROM DUAL UNION ALL
  5    SELECT 21837, 'p3',  'Blue',   150, 'Paris'  FROM DUAL UNION ALL
  6    SELECT 21435, 'p4',  'Black',  110, 'London' FROM DUAL UNION ALL
  7    SELECT 26383, 'p5',  'Yellow', 190, 'Madrid' FROM DUAL UNION ALL
  8    SELECT 27083, 'p6',  'Green',  180, 'Vienna' FROM DUAL UNION ALL
  9    SELECT 28631, 'p7',  'Green',  190, 'Vienna' FROM DUAL UNION ALL
 10    SELECT 25212, 'p8',  'Blue',   200, 'Paris'  FROM DUAL UNION ALL
 11    SELECT 29445, 'p9',  'Black',  120, 'London' FROM DUAL UNION ALL
 12    SELECT 23187, 'p10', 'Red',    170, 'Berlin' FROM DUAL UNION ALL
 13    SELECT 29609, 'p11', 'Blue',   150, 'Paris'  FROM DUAL UNION ALL
 14    SELECT 25025, 'p12', 'Red',    170, 'Paris'  FROM DUAL UNION ALL
 15    SELECT 28842, 'p13', 'Black',  100, 'Paris'  FROM DUAL UNION ALL
 16    SELECT 24396, 'p14', 'Black',  150, 'Berlin' FROM DUAL UNION ALL
 17    SELECT 28173, 'p15', 'Blue',   160, 'Vienna' FROM DUAL UNION ALL
 18    SELECT 29457, 'p16', 'Yellow', 110, 'Vienna' FROM DUAL UNION ALL
 19    SELECT 20876, 'p17', 'Red',    150, 'Berlin' FROM DUAL UNION ALL
 20    SELECT 26749, 'p18', 'Green',  160, 'Berlin' FROM DUAL UNION ALL
 21    SELECT 26188, 'p19', 'Red',    100, 'London' FROM DUAL UNION ALL
 22    SELECT 29224, 'p20', 'Green',  120, 'Vienna' FROM DUAL
 23  )
 24  SELECT * FROM PARTSDATA;

20 rows created.

SQL> INSERT INTO PROJECT (JNO, JNAME, CITY)
  2  WITH PROJECTDATA AS (
  3    SELECT 35986, 'j1',  'Paris'  FROM DUAL UNION ALL
  4    SELECT 31438, 'j2',  'London' FROM DUAL UNION ALL
  5    SELECT 39299, 'j3',  'Berlin' FROM DUAL UNION ALL
  6    SELECT 37650, 'j4',  'Paris'  FROM DUAL UNION ALL
  7    SELECT 35151, 'j5',  'Berlin' FROM DUAL UNION ALL
  8    SELECT 37114, 'j6',  'London' FROM DUAL UNION ALL
  9    SELECT 37474, 'j7',  'Vienna' FROM DUAL UNION ALL
 10    SELECT 34872, 'j8',  'Madrid' FROM DUAL UNION ALL
 11    SELECT 33604, 'j9',  'London' FROM DUAL UNION ALL
 12    SELECT 33104, 'j10', 'Vienna' FROM DUAL
 13  )
 14  SELECT * FROM PROJECTDATA;

10 rows created.

SQL> INSERT INTO SPJ (SNO, PNO, JNO, QTY)
  2  WITH SPJDATA AS (
  3    SELECT 14677, 26188, 39299, 11 FROM DUAL UNION ALL
  4    SELECT 16518, 28326, 35986, 14 FROM DUAL UNION ALL
  5    SELECT 11230, 21837, 33604, 20 FROM DUAL UNION ALL
  6    SELECT 18643, 29609, 33604, 2  FROM DUAL UNION ALL
  7    SELECT 19690, 29224, 37650, 19 FROM DUAL UNION ALL
  8    SELECT 19568, 24396, 33604, 11 FROM DUAL UNION ALL
  9    SELECT 12579, 25203, 35151, 8  FROM DUAL UNION ALL
 10    SELECT 18900, 21435, 37650, 2  FROM DUAL UNION ALL
 11    SELECT 11500, 25025, 37474, 7  FROM DUAL UNION ALL
 12    SELECT 16240, 29445, 37114, 7  FROM DUAL UNION ALL
 13    SELECT 19379, 25203, 35986, 4  FROM DUAL UNION ALL
 14    SELECT 17967, 27083, 33104, 1  FROM DUAL UNION ALL
 15    SELECT 10070, 25212, 35986, 12 FROM DUAL UNION ALL
 16    SELECT 11859, 28842, 34872, 6  FROM DUAL UNION ALL
 17    SELECT 18021, 25203, 34872, 9  FROM DUAL UNION ALL
 18    SELECT 16518, 28631, 31438, 12 FROM DUAL UNION ALL
 19    SELECT 17100, 26749, 37650, 16 FROM DUAL UNION ALL
 20    SELECT 15739, 23187, 35151, 7  FROM DUAL UNION ALL
 21    SELECT 15525, 26383, 37114, 17 FROM DUAL UNION ALL
 22    SELECT 19187, 20876, 33604, 9  FROM DUAL UNION ALL
 23    SELECT 18900, 26383, 35986, 13 FROM DUAL UNION ALL
 24    SELECT 18900, 26383, 31438, 1  FROM DUAL UNION ALL
 25    SELECT 18900, 26383, 39299, 18 FROM DUAL UNION ALL
 26    SELECT 18900, 26383, 37650, 1  FROM DUAL UNION ALL
 27    SELECT 18900, 26383, 35151, 19 FROM DUAL UNION ALL
 28    SELECT 18900, 26383, 37114, 11 FROM DUAL UNION ALL
 29    SELECT 18900, 26383, 37474, 7  FROM DUAL UNION ALL
 30    SELECT 18900, 26383, 34872, 1  FROM DUAL UNION ALL
 31    SELECT 18900, 26383, 33604, 9  FROM DUAL UNION ALL
 32    SELECT 18900, 26383, 33104, 16 FROM DUAL
 33  )
 34  SELECT * FROM SPJDATA;

30 rows created.
```

## Queries
1. Get `SNO` values for suppliers who supply project `j1`.
```sql
SELECT SPJ.SNO
FROM PROJECT J, SPJ
WHERE SPJ.JNO = J.JNO AND J.JNAME = 'j1';
```

```
SQL> SELECT SPJ.SNO
  2  FROM PROJECT J, SPJ
  3  WHERE SPJ.JNO = J.JNO AND J.JNAME = 'j1';

       SNO
----------
     16518
     19379
     10070
     18900
```

2. Get `SNO` values for suppliers who supply project `j1` with part `p1`.
```sql
SELECT SPJ.SNO
FROM PROJECT J, PARTS P, SPJ
WHERE SPJ.PNO = P.PNO AND SPJ.JNO = J.JNO AND J.JNAME = 'j1' AND P.PNAME = 'p1';
```

```
SQL> SELECT SPJ.SNO
  2  FROM PROJECT J, PARTS P, SPJ
  3  WHERE SPJ.PNO = P.PNO AND SPJ.JNO = J.JNO AND J.JNAME = 'j1' AND P.PNAME = 'p1';

       SNO
----------
     19379
```

3. Get `JNAME` values for projects supplied by supplier `s1`.
```sql
SELECT J.JNAME
FROM SUPPLIER S, PROJECT J, SPJ
WHERE SPJ.SNO = S.SNO AND SPJ.JNO = J.JNO AND S.SNAME = 's1';
```

```
SQL> SELECT J.JNAME
  2  FROM SUPPLIER S, PROJECT J, SPJ
  3  WHERE SPJ.SNO = S.SNO AND SPJ.JNO = J.JNO AND S.SNAME = 's1';

JNAME
----------
j5
```

4. Get `COLOR` values for parts supplied by supplier `s1`.
```sql
SELECT P.COLOR
FROM SUPPLIER S, PARTS P, SPJ
WHERE SPJ.SNO = S.SNO AND SPJ.PNO = P.PNO AND S.SNAME = 's1';
```

```
SQL> SELECT P.COLOR
  2  FROM SUPPLIER S, PARTS P, SPJ
  3  WHERE SPJ.SNO = S.SNO AND SPJ.PNO = P.PNO AND S.SNAME = 's1';

COLOR
----------
Blue
```

5. Get `PNO` values for parts supplied to any project in `London`.
```sql
SELECT SPJ.PNO
FROM PROJECT J, SPJ
WHERE SPJ.JNO = J.JNO AND J.CITY = 'London';
```

```
SQL> SELECT SPJ.PNO
  2  FROM PROJECT J, SPJ
  3  WHERE SPJ.JNO = J.JNO AND J.CITY = 'London';

       PNO
----------
     21837
     29609
     24396
     29445
     28631
     26383
     20876
     26383
     26383
     26383

10 rows selected.
```

6. Get `SNO` values for suppliers who supply project `j1` with a `Red` part.
```sql
SELECT SPJ.SNO
FROM PARTS P, PROJECT J, SPJ
WHERE SPJ.PNO = P.PNO AND SPJ.JNO = J.JNO AND J.JNAME = 'j1' AND P.COLOR = 'Red';
```

```
SQL> SELECT SPJ.SNO
  2  FROM PARTS P, PROJECT J, SPJ
  3  WHERE SPJ.PNO = P.PNO AND SPJ.JNO = J.JNO AND J.JNAME = 'j1' AND P.COLOR = 'Red';

       SNO
----------
     16518
```

7. Get `SNO` values for suppliers who supply a `London` or `Paris` project with a `Red` part.
```sql
SELECT SPJ.SNO
FROM PARTS P, PROJECT J, SPJ
WHERE SPJ.PNO = P.PNO AND SPJ.JNO = J.JNO AND (J.CITY = 'London' OR J.CITY = 'Paris') AND P.COLOR = 'Red';
```

```
SQL> SELECT SPJ.SNO
  2  FROM PARTS P, PROJECT J, SPJ
  3  WHERE SPJ.PNO = P.PNO AND SPJ.JNO = J.JNO AND (J.CITY = 'London' OR J.CITY = 'Paris') AND P.COLOR = 'Red';

       SNO
----------
     16518
     19187
```

8. Get `PNO` values for parts supplied to any project by a supplier in the same city.
```sql
SELECT SPJ.PNO
FROM SUPPLIER S, PROJECT J, SPJ
WHERE SPJ.SNO = S.SNO AND SPJ.JNO = J.JNO AND S.CITY = J.CITY;
```

```
SQL> SELECT SPJ.PNO
  2  FROM SUPPLIER S, PROJECT J, SPJ
  3  WHERE SPJ.SNO = S.SNO AND SPJ.JNO = J.JNO AND S.CITY = J.CITY;

       PNO
----------
     26188
     25212
     28631
     26383
```

9. Get `PNO` values for parts supplied to any project in `London` by a supplier in `London`.
```sql
SELECT SPJ.PNO
FROM SUPPLIER S, PROJECT J, SPJ
WHERE SPJ.SNO = S.SNO AND SPJ.JNO = J.JNO AND S.CITY = J.CITY AND S.CITY = 'London';
```

```
SQL> SELECT SPJ.PNO
  2  FROM SUPPLIER S, PROJECT J, SPJ
  3  WHERE SPJ.SNO = S.SNO AND SPJ.JNO = J.JNO AND S.CITY = J.CITY AND S.CITY = 'London';

       PNO
----------
     28631
```

10. Get `JNO` values for projects supplied by at least one supplier not in the same city.
```sql
SELECT DISTINCT J.JNO
FROM SUPPLIER S, PROJECT J, SPJ
WHERE SPJ.SNO = S.SNO AND SPJ.JNO = J.JNO AND S.CITY <> J.CITY;
```

```
SQL> SELECT DISTINCT J.JNO
  2  FROM SUPPLIER S, PROJECT J, SPJ
  3  WHERE SPJ.SNO = S.SNO AND SPJ.JNO = J.JNO AND S.CITY <> J.CITY;

       JNO
----------
     35151
     33604
     35986
     33104
     37650
     34872
     37114
     37474
     31438
     39299

10 rows selected.
```

11. Get all pairs of `CITY` values such that a supplier in the first city supplies a project in the second city.
```sql
SELECT S.CITY AS SCITY, J.CITY AS JCITY
FROM SUPPLIER S, PROJECT J, SPJ
WHERE SPJ.SNO = S.SNO AND SPJ.JNO = J.JNO
GROUP BY S.CITY, J.CITY
ORDER BY S.CITY;
```

```
SQL> SELECT S.CITY AS SCITY, J.CITY AS JCITY
  2  FROM SUPPLIER S, PROJECT J, SPJ
  3  WHERE SPJ.SNO = S.SNO AND SPJ.JNO = J.JNO
  4  GROUP BY S.CITY, J.CITY
  5  ORDER BY S.CITY;

SCITY      | JCITY
---------- | ----------
Berlin     | Berlin
Berlin     | Madrid
London     | London
London     | Madrid
London     | Paris
Madrid     | Berlin
Madrid     | London
Madrid     | Madrid
Madrid     | Paris
Madrid     | Vienna
Paris      | Berlin
Paris      | London
Paris      | Paris
Paris      | Vienna
Vienna     | London
Vienna     | Paris

16 rows selected.
```

12. Get `SNO` values for suppliers who supply the same part to all projects.
```sql
SELECT S.SNO
FROM SUPPLIER S
WHERE EXISTS (
  SELECT P.*
  FROM PARTS P
  WHERE NOT EXISTS (
    SELECT J.*
    FROM PROJECT J
    WHERE NOT EXISTS (
      SELECT SPJ.*
      FROM SPJ
      WHERE SPJ.SNO = S.SNO AND SPJ.PNO = P.PNO AND SPJ.JNO = J.JNO
    )
  )
);
```

```
SQL> SELECT S.SNO
  2  FROM SUPPLIER S
  3  WHERE EXISTS (
  4    SELECT P.*
  5    FROM PARTS P
  6    WHERE NOT EXISTS (
  7      SELECT J.*
  8      FROM PROJECT J
  9      WHERE NOT EXISTS (
 10        SELECT SPJ.*
 11        FROM SPJ
 12        WHERE SPJ.SNO = S.SNO AND SPJ.PNO = P.PNO AND SPJ.JNO = J.JNO
 13      )
 14    )
 15  );

       SNO
----------
     18900
```

13. Get `PNO` values for parts supplied to all projects in `London`.
```sql
SELECT SPJ.PNO
FROM PROJECT J, SPJ
WHERE SPJ.JNO = J.JNO AND J.CITY = 'London';
```

```
SQL> SELECT SPJ.PNO
  2  FROM PROJECT J, SPJ
  3  WHERE SPJ.JNO = J.JNO AND J.CITY = 'London';

       PNO
----------
     21837
     29609
     24396
     29445
     28631
     26383
     20876
     26383
     26383
     26383

10 rows selected.
```

14. Get `SNAME` values for suppliers who supply at least one `Red` part to any project.
```sql
SELECT S.SNAME, P.COLOR, SPJ.JNO
FROM SUPPLIER S, PARTS P, SPJ
WHERE SPJ.SNO = S.SNO AND SPJ.PNO = P.PNO AND P.COLOR = 'Red';
```

```
SQL> SELECT S.SNAME, P.COLOR, SPJ.JNO
  2  FROM SUPPLIER S, PARTS P, SPJ
  3  WHERE SPJ.SNO = S.SNO AND SPJ.PNO = P.PNO AND P.COLOR = 'Red';

SNAME      | COLOR      |        JNO
---------- | ---------- | ----------
s2         | Red        |      39299
s3         | Red        |      33604
s13        | Red        |      37474
s14        | Red        |      35986
s19        | Red        |      35151
```

15. Get total quantity of part `p1` supplied by supplier `s1`.
```sql
SELECT COUNT(*)
FROM SUPPLIER S, PARTS P, SPJ
WHERE SPJ.SNO = S.SNO AND SPJ.PNO = P.PNO AND S.SNAME = 's1' AND P.PNAME = 'p1';
```

```
SQL> SELECT COUNT(*)
  2  FROM SUPPLIER S, PARTS P, SPJ
  3  WHERE SPJ.SNO = S.SNO AND SPJ.PNO = P.PNO AND S.SNAME = 's1' AND P.PNAME = 'p1';

  COUNT(*)
----------
         1
```

16. Get the total number of projects supplied by supplier `s3`.
```sql
SELECT COUNT(*)
FROM SUPPLIER S, SPJ
WHERE SPJ.SNO = S.SNO AND S.SNAME = 's3';
```

```
SQL> SELECT COUNT(*)
  2  FROM SUPPLIER S, SPJ
  3  WHERE SPJ.SNO = S.SNO AND S.SNAME = 's3';

  COUNT(*)
----------
         1
```

17. Change color of all `Red` parts to `Orange`.
```sql
SELECT P.PNO, P.PNAME, P.COLOR
FROM PARTS P;

UPDATE PARTS P
SET P.COLOR = 'Orange'
WHERE P.COLOR = 'Red';

SELECT P.PNO, P.PNAME, P.COLOR
FROM PARTS P;
```

```
SQL> SELECT P.PNO, P.PNAME, P.COLOR
  2  FROM PARTS P;

       PNO | PNAME      | COLOR
---------- | ---------- | ----------
     25203 | p1         | Blue
     28326 | p2         | Red
     21837 | p3         | Blue
     21435 | p4         | Black
     26383 | p5         | Yellow
     27083 | p6         | Green
     28631 | p7         | Green
     25212 | p8         | Blue
     29445 | p9         | Black
     23187 | p10        | Red
     29609 | p11        | Blue
     25025 | p12        | Red
     28842 | p13        | Black
     24396 | p14        | Black
     28173 | p15        | Blue
     29457 | p16        | Yellow
     20876 | p17        | Red
     26749 | p18        | Green
     26188 | p19        | Red
     29224 | p20        | Green

20 rows selected.

SQL> UPDATE PARTS P
  2  SET P.COLOR = 'Orange'
  3  WHERE P.COLOR = 'Red';

5 rows updated.

SQL> SELECT P.PNO, P.PNAME, P.COLOR
  2  FROM PARTS P;

       PNO | PNAME      | COLOR
---------- | ---------- | ----------
     25203 | p1         | Blue
     28326 | p2         | Orange
     21837 | p3         | Blue
     21435 | p4         | Black
     26383 | p5         | Yellow
     27083 | p6         | Green
     28631 | p7         | Green
     25212 | p8         | Blue
     29445 | p9         | Black
     23187 | p10        | Orange
     29609 | p11        | Blue
     25025 | p12        | Orange
     28842 | p13        | Black
     24396 | p14        | Black
     28173 | p15        | Blue
     29457 | p16        | Yellow
     20876 | p17        | Orange
     26749 | p18        | Green
     26188 | p19        | Orange
     29224 | p20        | Green

20 rows selected.
```

18. Get `SNAME` values for suppliers who supply to both projects `j1` and `j2`.
```sql
SELECT S1.SNAME
FROM SUPPLIER S1, PROJECT J1, SPJ SPJ1
WHERE S1.SNAME IN (
  SELECT S2.SNAME
  FROM SUPPLIER S2, PROJECT J2, SPJ SPJ2
  WHERE J2.JNAME = 'j1' AND S2.SNAME = S2.SNAME AND SPJ2.SNO = S2.SNO AND SPJ2.JNO = J2.JNO
) AND J1.JNAME = 'j2' AND SPJ1.SNO = S1.SNO AND SPJ1.JNO = J1.JNO;
```

```
SQL> SELECT S1.SNAME
  2  FROM SUPPLIER S1, PROJECT J1, SPJ SPJ1
  3  WHERE S1.SNAME IN (
  4    SELECT S2.SNAME
  5    FROM SUPPLIER S2, PROJECT J2, SPJ SPJ2
  6    WHERE J2.JNAME = 'j1' AND S2.SNAME = S2.SNAME AND SPJ2.SNO = S2.SNO AND SPJ2.JNO = J2.JNO
  7  ) AND J1.JNAME = 'j2' AND SPJ1.SNO = S1.SNO AND SPJ1.JNO = J1.JNO;

SNAME
----------
s14
s16
```

19. Get all `CITY`, `PNO`, `CITY` triples such that a supplier in the first city supplies the specified part to a project in the second city.
```sql
SELECT S.CITY AS SCITY, P.PNO AS PNO, J.CITY AS JCITY
FROM SUPPLIER S, PARTS P, PROJECT J, SPJ SPJ
WHERE SPJ.SNO = S.SNO AND SPJ.PNO = P.PNO AND SPJ.JNO = J.JNO;
```

```
SQL> SELECT S.CITY AS SCITY, P.PNO AS PNO, J.CITY AS JCITY
  2  FROM SUPPLIER S, PARTS P, PROJECT J, SPJ SPJ
  3  WHERE SPJ.SNO = S.SNO AND SPJ.PNO = P.PNO AND SPJ.JNO = J.JNO;

SCITY      |        PNO | JCITY
---------- | ---------- | ----------
Paris      |      25203 | Berlin
Berlin     |      26188 | Berlin
Paris      |      20876 | London
Vienna     |      25203 | Paris
Madrid     |      27083 | Vienna
Madrid     |      29224 | Paris
London     |      28842 | Madrid
Madrid     |      29445 | London
Madrid     |      26383 | London
Paris      |      25212 | Paris
Madrid     |      26749 | Paris
Paris      |      25025 | Vienna
London     |      28326 | Paris
London     |      28631 | London
Vienna     |      21837 | London
Madrid     |      21435 | Paris
Madrid     |      26383 | Paris
Madrid     |      26383 | London
Madrid     |      26383 | Berlin
Madrid     |      26383 | Paris
Madrid     |      26383 | Berlin
Madrid     |      26383 | London
Madrid     |      26383 | Vienna
Madrid     |      26383 | Madrid
Madrid     |      26383 | London
Madrid     |      26383 | Vienna
Vienna     |      29609 | London
Madrid     |      24396 | London
Madrid     |      23187 | Berlin
Berlin     |      25203 | Madrid

30 rows selected.
```

20. Get `JNAMES` for those projects which are supplied by supplier `XYZ`.
```sql
SELECT J.JNAME, S.SNAME
FROM SUPPLIER S, PROJECT J, SPJ
WHERE SPJ.SNO = S.SNO AND SPJ.JNO = J.JNO AND S.SNAME = 's1';
```

```
SQL> SELECT J.JNAME, S.SNAME
  2  FROM SUPPLIER S, PROJECT J, SPJ
  3  WHERE SPJ.SNO = S.SNO AND SPJ.JNO = J.JNO AND S.SNAME = 's1';

JNAME      | SNAME
---------- | ----------
j5         | s1
```
