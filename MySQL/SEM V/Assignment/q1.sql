-- Initializaiton
\! cls
DROP DATABASE q1_0129;

CREATE DATABASE q1_0129;

USE q1_0129;

-- Table Creation
CREATE TABLE Course_0129(
    COURSE_NO   CHAR(4)     NOT NULL    UNIQUE  PRIMARY KEY,
    COURSE_NAME VARCHAR(20)
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
    PHONE_NO        INTEGER(11)     UNIQUE,
    D_O_B           DATE            NOT NULL,
    TOTAL_AMT       DECIMAL(10, 2)  NOT NULL,
    AMT_PAID        DECIMAL(10, 2)  NOT NULL,
    INSTALLMENT     CHAR(1)         NOT NULL
    CHECK (
        INSTALLMENT = "I"
        OR INSTALLMENT = "F"
    )
);

CREATE TABLE Installment_0129 (
    PROSPECTUS_NO   INTEGER(10)     NOT NULL    UNIQUE,
    INSTALLMENT_AMT DECIMAL(10, 2)  NOT NULL,
    DUE_DT          DATE            NOT NULL    UNIQUE,
    PAID            CHAR(1)         NOT NULL    CHECK(PAID = "P" OR PAID = "U"),

    CONSTRAINT FOREIGN KEY(PROSPECTUS_NO) REFERENCES Student_0129(PROSPECTUS_NO)
);

CREATE TABLE Course_Taken_0129 (
    PROSPECTUS_NO   INTEGER(10) NOT NULL    UNIQUE,
    COURSE_NO       CHAR(4)     NOT NULL    UNIQUE,
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

SHOW TABLES;

DESC Course_0129;
DESC Course_Fee_0129;
DESC Student_0129;
DESC Installment_0129;
DESC Course_Taken_0129;

-- Data Entry
INSERT INTO Course_0129 (COURSE_NO, COURSE_NAME) VALUES
    ("5451", "Technical Comms.-I"),
    ("6197", "Eng. Mechanics"),
    ("2470", "Workshop Practices"),
    ("4887", "Programming in C"),
    ("5876", "Intro to French"),
    ("5359", "Applied Math-I"),
    ("5374", "Eng. Physics"),
    ("3280", "Technical Comms.-II"),
    ("8701", "Eng. Chemistry"),
    ("0150", "Basic Electrical"),
    ("5164", "Eng. Graphics"),
    ("7828", "Env. Sciences"),
    ("3981", "French Grammar-I"),
    ("4416", "Applied Math-II"),
    ("1633", "Computer Org."),
    ("5144", "Data Structures"),
    ("4722", "Basic Electronics"),
    ("5709", "Programming in C++"),
    ("8402", "Basic Simulation Lab"),
    ("0161", "Written French-I"),
    ("3628", "Applied Math-III"),
    ("1738", "Self Reliance"),
    ("6016", "Operating System"),
    ("6698", "Computation Theory"),
    ("7366", "Discrete Math"),
    ("8495", "Data Science"),
    ("9345", "Comm. French-I"),
    ("8349", "Programming in Java"),
    ("3626", "Applied Math-IV"),
    ("3663", "Material Science"),
    ("2926", "Cognitive Skills"),
    ("7612", "Database Management"),
    ("8098", "Algorithms"),
    ("3953", "R Programming"),
    ("3494", "Comm. French-II"),
    ("8381", "Networks"),
    ("9744", "Aptitude"),
    ("6005", "Machine Learning");

INSERT INTO Course_Fee_0129 (
    COURSE_NO,
    FULL_PART,
    FEES
)
VALUES
    ("5451", "F", 84000),
    ("6197", "F", 53000),
    ("2470", "P", 24000),
    ("4887", "P", 11000),
    ("5876", "F", 20000),
    ("5359", "F", 19000),
    ("5374", "F", 57000),
    ("3280", "P", 53000),
    ("8701", "F", 79000),
    ("0150", "P", 15000),
    ("5164", "F", 37000),
    ("7828", "F", 49000),
    ("3981", "P", 32000),
    ("4416", "F", 66000),
    ("1633", "P", 79000),
    ("5144", "F", 54000),
    ("4722", "P", 51000),
    ("5709", "F", 71000),
    ("8402", "F", 23000),
    ("0161", "P", 62000),
    ("3628", "P", 98000),
    ("1738", "F", 44000),
    ("6016", "P", 40000),
    ("6698", "F", 51000),
    ("7366", "P", 30000),
    ("8495", "P", 36000),
    ("9345", "P", 77000),
    ("8349", "P", 85000),
    ("3626", "P", 28000),
    ("3663", "F", 11000),
    ("2926", "P", 80000),
    ("7612", "F", 90000),
    ("8098", "P", 94000),
    ("3953", "F", 72000),
    ("3494", "P", 40000),
    ("8381", "P", 46000),
    ("9744", "F", 92000),
    ("6005", "F", 55000);

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

SELECT *
FROM Course_0129;

SELECT *
FROM Course_Fee_0129;
