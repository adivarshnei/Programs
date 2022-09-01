-- Initialization
\! cls
DROP DATABASE q2;
CREATE DATABASE q2;
USE q2;

-- Table Creation
CREATE TABLE SUPPLIER (
    SNO     INTEGER(5)      NOT NULL    UNIQUE  PRIMARY KEY,
    SNAME   VARCHAR(10)     NOT NULL    UNIQUE,
    STATUS  CHAR(11)
    CHECK (
        STATUS = "WORKING" OR STATUS = "NOT WORKING"
    ),
    CITY    VARCHAR(10)
);

CREATE TABLE PARTS (
    PNO     INTEGER(5)      NOT NULL    UNIQUE  PRIMARY KEY,
    PNAME   VARCHAR(10)     NOT NULL    UNIQUE,
    COLOR   VARCHAR(10)     NOT NULL,
    WEIGHT  INTEGER(5),
    CITY    VARCHAR(10)
);

CREATE TABLE PROJECT (
    JNO     INTEGER(5)      NOT NULL    UNIQUE  PRIMARY KEY,
    JNAME   VARCHAR(10)     NOT NULL    UNIQUE,
    CITY    VARCHAR(10)
);

CREATE TABLE SPJ (
    SNO INTEGER(5)  NOT NULL    UNIQUE,
    PNO INTEGER(5)  NOT NULL    UNIQUE,
    JNO INTEGER(5)  NOT NULL    UNIQUE,
    QTY INTEGER(5)  NOT NULL    UNIQUE,

    CONSTRAINT FOREIGN KEY(SNO) REFERENCES SUPPLIER(SNO),
    CONSTRAINT FOREIGN KEY(PNO) REFERENCES PARTS(PNO),
    CONSTRAINT FOREIGN KEY(JNO) REFERENCES PROJECT(JNO)
);

SHOW TABLES;
DESC SUPPLIER;
DESC PARTS;
DESC PROJECT;
DESC SPJ;

-- Data Entry

-- Queries