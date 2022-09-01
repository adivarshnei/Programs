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

INSERT INTO Student(S_ADM_NO, S_NAME, S_FEE_STATUS) VALUES
    (3988, "TOR", "PAID"),
	(6937, "KVI", "NOT PAID"),
	(5713, "XJH", "NOT PAID"),
	(1209, "WHE", "PAID"),
	(3244, "VTV", "PAID"),
	(2112, "QFJ", "PAID"),
	(5755, "RTL", "PAID"),
	(7531, "FTQ", "PAID"),
	(5579, "DPO", "PAID"),
	(8200, "UBH", "NOT PAID");

CREATE TABLE Test(
    S_ADM_NO            INTEGER,
    S_NAME              VARCHAR(20) NOT NULL,
    S_ADMIT_CARD_ID     INTEGER     NOT NULL    UNIQUE  PRIMARY KEY,
    S_MARKS             INTEGER     DEFAULT 0   CHECK (S_MARKS <= 100)
    -- CONSTRAINT FOREIGN KEY(S_ADM_NO) REFERENCES Student(S_ADM_NO)
);

DESC Test;

INSERT INTO Test(S_ADM_NO, S_NAME, S_ADMIT_CARD_ID, S_MARKS) VALUES
    (3988, "TOR", 8119, 03.69),
	(6937, "KVI", 8120, 68.44),
	(5713, "XJH", 8121, 48.53),
	(1209, "WHE", 8122, 48.08),
	(3244, "VTV", 8123, 79.82),
	(2112, "QFJ", 8124, 35.43),
	(5755, "RTL", 8125, 51.97),
	(7531, "FTQ", 8126, 42.90),
	(5579, "DPO", 8127, 48.83),
	(8201, "UBG", 8128, 52.25);

-- Cartesian Product
SELECT
    Student.S_ADM_NO,
    Student.S_NAME,
    Student.S_FEE_STATUS,
    Test.S_ADMIT_CARD_ID,
    Test.S_MARKS
FROM Student CROSS JOIN Test;

-- Equi Join
SELECT
    Student.S_ADM_NO,
    Student.S_NAME,
    Student.S_FEE_STATUS,
    Test.S_ADMIT_CARD_ID,
    Test.S_MARKS
FROM Student JOIN Test
ON Student.S_ADM_NO = Test.S_ADM_NO;

-- Inner Join
SELECT
    Student.S_ADM_NO,
    Student.S_NAME,
    Student.S_FEE_STATUS,
    Test.S_ADMIT_CARD_ID,
    Test.S_MARKS
FROM Student INNER JOIN Test
ON Student.S_ADM_NO = Test.S_ADM_NO;

-- Outer Left Join
SELECT
    Student.S_ADM_NO,
    Student.S_NAME,
    Student.S_FEE_STATUS,
    Test.S_ADMIT_CARD_ID,
    Test.S_MARKS
FROM Student LEFT JOIN Test
ON Student.S_ADM_NO = Test.S_ADM_NO;

-- Outer Right Join
SELECT
    Student.S_ADM_NO,
    Student.S_NAME,
    Student.S_FEE_STATUS,
    Test.S_ADMIT_CARD_ID,
    Test.S_MARKS
FROM Student RIGHT JOIN Test
ON Student.S_ADM_NO = Test.S_ADM_NO;

-- Self Join
SELECT S1.S_NAME, S2.S_NAME, S1.S_FEE_STATUS
FROM Student S1, Student S2
WHERE S1.S_ADM_NO <> S2.S_ADM_NO AND S1.S_FEE_STATUS = S2.S_FEE_STATUS
ORDER BY S1.S_FEE_STATUS;

-- Non-Equi Join
SELECT
    Student.S_ADM_NO AS "Student.S_ADM_NO",
    Test.S_ADM_NO AS "Test.S_ADM_NO"
FROM Student JOIN Test
ON Student.S_ADM_NO < Test.S_ADM_NO;

-- Natural Join
SELECT
    Student.S_ADM_NO,
    Student.S_NAME,
    Student.S_FEE_STATUS,
    Test.S_ADMIT_CARD_ID,
    Test.S_MARKS
FROM Student NATURAL JOIN Test;