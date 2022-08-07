CREATE DATABASE p4;
USE p4;

#--------------------------------------------------------------------------------------------------------------------------

CREATE TABLE BOOKS
	(Book_ID		CHAR(3)		NOT NULL,
	BookName		VARCHAR(10),
	AuthorName	VARCHAR(15),
	Publisher		CHAR(3),
	Price		INTEGER		NOT NULL,
	Qty			INTEGER		NOT NULL);

INSERT INTO BOOKS VALUES
	("L01", "Maths", "Raman", "ABC", 70, 20);
INSERT INTO BOOKS VALUES
	("L02", "Science", "Agarkar", "DEF", 90, 15);
INSERT INTO BOOKS VALUES
	("L03", "Social", "Suresh", "XYZ", 85, 30);
INSERT INTO BOOKS VALUES
	("L04", "Computer", "Sumita", "ABC", 75, 7);
INSERT INTO BOOKS VALUES
	("L05", "Telugu", "Nannayya", "DEF", 60, 25);
INSERT INTO BOOKS VALUES
	("L06", "English", "Wordsworth", "DEF", 55, 12);

#--------------------------------------------------------------------------------------------------------------------------

CREATE TABLE ISSUES
	(Book_ID		CHAR(3)	NOT NULL,
	Qty_Issued	INTEGER);

INSERT INTO ISSUES VALUES
	("L01", NULL);
INSERT INTO ISSUES VALUES
	("L02", 13);
INSERT INTO ISSUES VALUES
	("L03", NULL);
INSERT INTO ISSUES VALUES
	("L04", 5);
INSERT INTO ISSUES VALUES
	("L05", 21);

#--------------------------------------------------------------------------------------------------------------------------

#(i)
SELECT 
	BookName, AuthorName, Price
FROM 
	BOOKS
WHERE 
	Publisher = "ABC";

#--------------------------------------------------------------------------------------------------------------------------

#(ii)
SELECT 
	BOOKS.*,
	ISSUES.*
FROM 
	BOOKS, ISSUES
WHERE 
	BOOKS.Book_ID = ISSUES.Book_ID
ORDER BY 
	Price DESC;

#--------------------------------------------------------------------------------------------------------------------------

#(iii)
SELECT 
	Book_ID, Qty_Issued - 3
FROM 
	ISSUES;

#--------------------------------------------------------------------------------------------------------------------------

#(iv)
SELECT
	BOOKS.Book_ID, BOOKS.BookName, BOOKS.Publisher, BOOKS.Price, BOOKS.Qty,
	ISSUES.Qty_Issued
FROM 
	BOOKS, ISSUES
WHERE 
	BOOKS.Book_ID = ISSUES.Book_ID;

#--------------------------------------------------------------------------------------------------------------------------

#(v)
SELECT 
	BOOKS.Price,
	ISSUES.Qty_Issued
FROM 
	BOOKS, ISSUES
WHERE 
	BOOKS.Book_ID = ISSUES.Book_ID
	AND
	ISSUES.Qty_Issued = 5;
