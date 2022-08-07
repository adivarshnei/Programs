CREATE DATABASE p2;
USE p2;

#--------------------------------------------------------------------------------------------------------------------------

CREATE TABLE ACTIVITY
	(ACode			INTEGER		NOT NULL,
	ActivityName		VARCHAR(20),
	ParticipantsNum	INTEGER		NOT NULL,
	PrizeMoney		INTEGER		NOT NULL,
	ScheduleDate		DATE			NOT NULL);

INSERT INTO ACTIVITY VALUES
	(1001, "Relay 100x4", 16, 10000, "2004-01-22");
INSERT INTO ACTIVITY VALUES
	(1002, "High Jump", 10, 12000, "2003-12-12");
INSERT INTO ACTIVITY VALUES
	(1003, "Shot Put", 12, 8000, "2004-02-14");
INSERT INTO ACTIVITY VALUES
	(1005, "Long Jump", 12, 9000, "2004-01-01");
INSERT INTO ACTIVITY VALUES
	(1008, "Discuss Throw", 10, 15000, "2004-03-19");

#--------------------------------------------------------------------------------------------------------------------------

CREATE TABLE COACH
	(PCode	INTEGER	NOT NULL,
	Name		VARCHAR(15),
	ACode	INTEGER	NOT NULL);

INSERT INTO COACH VALUES
	(1, "Ahmad Hussain", 1001);
INSERT INTO COACH VALUES
	(2, "Ravinder", 1008);
INSERT INTO COACH VALUES
	(3, "Janila", 1001);
INSERT INTO COACH VALUES
	(4, "Naaz", 1003);

#--------------------------------------------------------------------------------------------------------------------------

# (i)
SELECT
	ActivityName, ACode
FROM
	ACTIVITY
ORDER BY
	ACode DESC;

#--------------------------------------------------------------------------------------------------------------------------

# (ii)
SELECT
	SUM(PrizeMoney), ParticipantsNum
FROM
	ACTIVITY
GROUP BY
	ParticipantsNum
ORDER BY
	ParticipantsNum ASC;

#--------------------------------------------------------------------------------------------------------------------------

# (iii)
SELECT
	Name, ACode
FROM
	COACH
ORDER BY
	ACode ASC;

#--------------------------------------------------------------------------------------------------------------------------

#(iv)
SELECT
	*
FROM
	ACTIVITY
WHERE
	ScheduleDate < "2004-01-01"
ORDER BY
	ParticipantsNum ASC;

#--------------------------------------------------------------------------------------------------------------------------

#(v)
SELECT
	MAX(ScheduleDate) AS "Max Date",
	MIN(ScheduleDate) AS "Min Date"
FROM
	ACTIVITY;
