-- Initialization
\! cls
DROP DATABASE q2_0129;

CREATE DATABASE q2_0129;

USE q2_0129;

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
    CONSTRAINT FOREIGN KEY(SNO) REFERENCES SUPPLIER_0129(SNO),
    CONSTRAINT FOREIGN KEY(PNO) REFERENCES PARTS_0129(PNO),
    CONSTRAINT FOREIGN KEY(JNO) REFERENCES PROJECT_0129(JNO)
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
	(29445, "p9", "Black", 120, "Paris"),
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
	(31438, "j2", "Paris"),
	(39299, "j3", "Berlin"),
	(37650, "j4", "Paris"),
	(35151, "j5", "Berlin"),
	(37114, "j6", "Berlin"),
	(37474, "j7", "Vienna"),
	(34872, "j8", "Madrid"),
	(33604, "j9", "Paris"),
	(33104, "j10", "Vienna");

INSERT INTO SPJ_0129 (SNO, PNO, JNO, QTY) VALUES
    (14677, 26188, 39299, 11),
	(16518, 28326, 33604, 14),
	(11230, 21837, 33604, 20),
	(18643, 29609, 33604, 2),
	(19690, 29224, 37650, 19),
	(19568, 24396, 33604, 11),
	(12579, 29457, 35151, 8),
	(18900, 21435, 37650, 2),
	(11500, 25025, 37474, 7),
	(16240, 29445, 37114, 7),
	(19379, 25203, 35986, 4),
	(17967, 27083, 33104, 1),
	(10070, 25212, 35986, 12),
	(11859, 28842, 34872, 6),
	(18021, 25203, 34872, 9),
	(11048, 28631, 31438, 12),
	(17100, 26749, 37650, 16),
	(15739, 23187, 35151, 7),
	(15525, 26383, 37114, 17),
	(19187, 20876, 33604, 9);

-- Queries
-- 1. Get SNO values for suppliers who supply project j1.
SELECT SPJ.SNO
FROM PROJECT_0129 J, SPJ_0129 SPJ
WHERE SPJ.JNO = J.JNO AND J.JNAME="j1";

-- 2. Get SNO values for suppliers who supply project j1 with part p1.
SELECT SPJ.SNO
FROM PARTS_0129 P, PROJECT_0129 J, SPJ_0129 SPJ
WHERE SPJ.PNO = P.PNO AND SPJ.JNO = J.JNO AND P.PNAME = "p1" AND J.JNAME = "j1";

-- 3. Get JNAME values for projects supplied by supplier s1.


-- 4. Get COLOR values for parts supplied by supplier s1.


-- 5. Get PNO values for parts supplied to any project in London.


-- 6. Get SNO values for supply project j1 with a Red part.


-- 7. Get SNO values for suppliers who supply a London or Paris project with a Red part.


-- 8. Get PNO values for parts supplied to any project by a supplier in the same city.


-- 9. Get PNO values for parts supplied to any project in London by a supplier in London.


-- 10. Get JNO values for projects supplied by at least one supplier not in the same city.


-- 11. Get all pairs of CITY values such that a supplier in the first city supplies a project in the second city.


-- 12. Get SNO values for suppliers who supply the same part to all projects.


-- 13. Get PNO values for parts supplied to all projects in London.


-- 14. Get SNAME values for suppliers who supply at least one Red part to any project.


-- 15. Get total quantity of part p1 supplied by supplier s1.


-- 16. Get the total number of projects supplied by supplier s3.


-- 17. Change color of all Red parts to Orange.


-- 18. Get SNAME values for suppliers who supply to both projects j1 and j2


-- 19. Get all CITY, PNO, CITY triples such that a supplier in the first city supplies the specified part to a project in the second city.


-- 20. Get JNAMES for those projects which are supplied by supplier XYZ.
