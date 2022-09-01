\! cls
DROP DATABASE p4;

CREATE DATABASE p4;

USE p4;

CREATE TABLE Customer(
    C_ID			CHAR(4) 	NOT NULL	UNIQUE	PRIMARY KEY,
    C_AMOUNT_DUE	INTEGER(4)	NOT NULL,
    C_MOBILE		INTEGER(10),
    C_COUNTRY		VARCHAR(20)
);

DESC Customer;

INSERT INTO Customer(C_ID, C_AMOUNT_DUE, C_MOBILE, C_COUNTRY) VALUES
    ("BJUD", 3033, 315495114, "India"),
    ("HUMH", 1012, 842450106, "Australia"),
    ("KXXL", 0303, 119465940, "India"),
    ("WBAB", 3033, 727948025, "India"),
    ("HNCO", 1323, 859882122, "Germany"),
    ("BYVX", 3312, 404183479, "Australia"),
    ("AGAE", 2033, 838295185, "South Africa"),
    ("PJUK", 0331, 165202543, "India"),
    ("MDUE", 1301, 392628461, "Germany"),
    ("EQEG", 1310, 739828670, "South Africa");

-- GROUP BY
SELECT COUNT(*) AS "Number of Customers", "from", C_COUNTRY AS "Country"
FROM Customer
GROUP BY C_COUNTRY;

-- GROUP BY...HAVING
SELECT
    COUNT(*) AS "Number of Customers",
    "from",
    C_COUNTRY AS "Country",
    "with average dues greater than 1500"
FROM Customer
GROUP BY C_COUNTRY
HAVING AVG(C_AMOUNT_DUE) > 1500;

CREATE TABLE Student(
    S_ADM_NO        INTEGER     NOT NULL    UNIQUE  PRIMARY KEY,
    S_NAME          VARCHAR(20) NOT NULL,
    S_FEE_STATUS    CHAR(8)     CHECK (
        S_FEE_STATUS = 'PAID' OR S_FEE_STATUS = 'NOT PAID'
    )
);

DESC Student;

CREATE TABLE Test(
    S_ADM_NO            INTEGER,
    S_NAME              VARCHAR(20) NOT NULL,
    S_ADMIT_CARD_ID     INTEGER     NOT NULL    UNIQUE  PRIMARY KEY,
    S_MARKS             INTEGER     DEFAULT 0   CHECK (S_MARKS <= 100),
    CONSTRAINT FOREIGN KEY(S_ADM_NO) REFERENCES Student(S_ADM_NO)
);

DESC Test;

-- Cartesian Product
-- Equi Join
--  Inner Join
--  Outer Join
--      Left Join
--      Right Join
-- Self Join
-- Non-Equi Join
-- Natural Join
