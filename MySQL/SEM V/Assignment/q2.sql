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
SELECT J.JNAME
FROM SUPPLIER_0129 S, PROJECT_0129 J, SPJ_0129 SPJ
WHERE S.SNAME = "s1" AND SPJ.SNO = S.SNO AND SPJ.JNO = J.JNO;

-- 4. Get COLOR values for parts supplied by supplier s1.
SELECT P.COLOR
FROM SUPPLIER_0129 S, PARTS_0129 P, SPJ_0129 SPJ
WHERE S.SNAME = "s1" AND SPJ.PNO = P.PNO AND SPJ.SNO = S.SNO;

-- 5. Get PNO values for parts supplied to any project in London.
SELECT SPJ.PNO
FROM PROJECT_0129 J, SPJ_0129 SPJ
WHERE J.CITY = "London" AND SPJ.JNO = J.JNO;

-- 6. Get SNO values for supply project j1 with a Red part.
SELECT SPJ.SNO
FROM PARTS_0129 P, PROJECT_0129 J, SPJ_0129 SPJ
WHERE
    P.COLOR = "Red"
    AND J.JNAME = "j1"
    AND SPJ.PNO = P.PNO
    AND SPJ.JNO = J.JNO;

-- 7. Get SNO values for suppliers who supply a London or Paris project with a
-- Red part.
SELECT SPJ.SNO
FROM PARTS_0129 P, PROJECT_0129 J, SPJ_0129 SPJ
WHERE
    P.COLOR = "Red"
    AND (J.CITY = "London" OR J.CITY = "Paris")
    AND SPJ.PNO = P.PNO
    AND SPJ.JNO = J.JNO;

-- 8. Get PNO values for parts supplied to any project by a supplier in the same
-- city.
SELECT P.PNO
FROM SUPPLIER_0129 S, PARTS_0129 P, PROJECT_0129 J, SPJ_0129 SPJ
WHERE
    S.CITY = J.CITY
    AND SPJ.SNO = S.SNO
    AND SPJ.PNO = P.PNO
    AND SPJ.JNO = J.JNO;

-- 9. Get PNO values for parts supplied to any project in London by a supplier
-- in London.
SELECT P.PNO
FROM SUPPLIER_0129 S, PARTS_0129 P, PROJECT_0129 J, SPJ_0129 SPJ
WHERE
    S.CITY = J.CITY
    AND S.CITY = "London"
    AND SPJ.SNO = S.SNO
    AND SPJ.PNO = P.PNO
    AND SPJ.JNO = J.JNO;

-- 10. Get JNO values for projects supplied by at least one supplier not in the
-- same city.
SELECT DISTINCT J.JNO
FROM SUPPLIER_0129 S, PROJECT_0129 J, SPJ_0129 SPJ
WHERE
    S.CITY <> J.CITY
    AND SPJ.SNO = S.SNO
    AND SPJ.JNO = J.JNO
ORDER BY J.JNAME;

-- 11. Get all pairs of CITY values such that a supplier in the first city
-- supplies a project in the second city.
SELECT S.CITY, J.CITY
FROM SUPPLIER_0129 S, PROJECT_0129 J, SPJ_0129 SPJ
WHERE
    SPJ.SNO = S.SNO
    AND SPJ.JNO = J.JNO
GROUP BY S.CITY, J.CITY;

-- 12. Get SNO values for suppliers who supply the same part to all projects.


-- 13. Get PNO values for parts supplied to all projects in London.
-- SELECT *
-- FROM PARTS_0129 P, PROJECT_0129 J, SPJ_0129 SPJ
-- WHERE P.CITY = "London" AND SPJ.PNO = P.PNO AND SPJ.JNO = J.JNO;

-- 14. Get SNAME values for suppliers who supply at least one Red part to any
-- project.
SELECT S.SNAME, P.COLOR, SPJ.*
FROM SUPPLIER_0129 S, PARTS_0129 P, SPJ_0129 SPJ
WHERE P.COLOR = "Red" AND SPJ.SNO = S.SNO AND SPJ.PNO = P.PNO;

-- 15. Get total quantity of part p1 supplied by supplier s1.
SELECT SUM(QTY)
FROM (
    SELECT QTY
    FROM SUPPLIER_0129 S, PARTS_0129 P, SPJ_0129 SPJ
    WHERE
        S.SNAME = "s1"
        AND P.PNAME = "p1"
        AND SPJ.SNO = S.SNO
        AND SPJ.PNO = P.PNO
) S1P1;

-- 16. Get the total number of projects supplied by supplier s3.
SELECT COUNT(*)
FROM (
    SELECT S.SNAME, P.PNAME
    FROM SUPPLIER_0129 S, PARTS_0129 P, SPJ_0129 SPJ
    WHERE
        S.SNAME = "s3"
        AND SPJ.SNO = S.SNO
        AND SPJ.PNO = P.PNO
) S3;

-- 17. Change color of all Red parts to Orange.
SELECT P.*
FROM PARTS_0129 P;

UPDATE PARTS_0129 P
SET P.COLOR = "Orange"
WHERE P.COLOR = "Red";

SELECT P.*
FROM PARTS_0129 P;

-- 18. Get SNAME values for suppliers who supply to both projects j1 and j2
SELECT S1.SNAME
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


-- 19. Get all CITY, PNO, CITY triples such that a supplier in the first city
-- supplies the specified part to a project in the second city.
SELECT S.CITY, P.PNO, J.CITY
FROM SUPPLIER_0129 S, PARTS_0129 P, PROJECT_0129 J, SPJ_0129 SPJ
WHERE SPJ.SNO = S.SNO AND SPJ.PNO = P.PNO AND SPJ.JNO = J.JNO;

-- 20. Get JNAMES for those projects which are supplied by supplier XYZ.
DELIMITER &&
CREATE PROCEDURE JNAMES_GEN (IN SUPPLIER_NAME CHAR(2))
BEGIN
    SELECT J.JNAME
    FROM SUPPLIER_0129 S, PROJECT_0129 J, SPJ_0129 SPJ
    WHERE S.SNAME = SUPPLIER_NAME AND SPJ.SNO = S.SNO AND SPJ.JNO = J.JNO;
END &&
DELIMITER ;

CALL JNAMES_GEN("s1");
CALL JNAMES_GEN("s2");
CALL JNAMES_GEN("s3");
