CREATE DATABASE p5;
USE p5;

#--------------------------------------------------------------------------------------------------------------------------

CREATE TABLE Client
	(Cust_ID	CHAR(4)		NOT NULL,
	Cust_Name	VARCHAR(20),
	Address	VARCHAR(20),
	Phone_no	INTEGER,
	City		VARCHAR(15));

INSERT INTO Client VALUES
	("C007", "Pritam Sharma", "12, M.G Road", 71274250, "Bangalore");
INSERT INTO Client VALUES
	("C008", "Sutopa", "14/1 Pritam Pura", 41206819, "Delhi");
INSERT INTO Client VALUES
	("C010", "Anurag Basu", "15A, Park Road", 61281921, "Kolkata");
INSERT INTO Client VALUES
	("C012", "Hrithik", "7/2 Vasant Kunj", 26121949, "Delhi");
INSERT INTO Client VALUES
	("C013", "Firoz Shah", "2, Servamali Road", 25014192, "Bangalore");
INSERT INTO Client VALUES
	("C025", "Vinod Nagpal", "46-a Navi Mumbai", 64104944, "Mumbai");
INSERT INTO Client VALUES
	("C027", "Sameer", "41, Dwarka", 42101619, "Delhi");
INSERT INTO Client VALUES
	("C002", "Pasunjit Bose", "16/A K.G Marg", 27220012, "Bangalore");
INSERT INTO Client VALUES
	("C035", "Aamina Begum", "13/a Versova", 41612181, "Mumbai");

#--------------------------------------------------------------------------------------------------------------------------

CREATE TABLE BILL
	(Ord_id	INTEGER		NOT NULL,
	Cust_ID	CHAR(4)		NOT NULL,
	Item		VARCHAR(15),
	Ord_date	DATE			NOT NULL,
	Qty		INTEGER		NOT NULL,
	Price	DECIMAL(8,2)	NOT NULL);

INSERT INTO BILL VALUES
	(7002, "C007", "Pizza", "2007-11-20", 1, 249.50);
INSERT INTO BILL VALUES
	(7003, "C013", "Garlic Bread", "2005-10-24", 3, 75.75);
INSERT INTO BILL VALUES
	(7004, "C012", "Pasta", "2007-03-03", 4, 173.00);
INSERT INTO BILL VALUES
	(7005, "C010", "Ice Cream", "2008-01-01", 30, 195.75);
INSERT INTO BILL VALUES
	(7006, "C035", "Pizza", "2006-03-02", 4, 249.50);
INSERT INTO BILL VALUES
	(7009, "C035", "Garlic Bread", "2008-03-02", 2, 75.75);
INSERT INTO BILL VALUES
	(7010, "C013", "Brownie", "2007-05-04", 4, 40.50);
INSERT INTO BILL VALUES
	(7011, "C014", "Ice Cream", "2008-06-02", 5, 195.75);
INSERT INTO BILL VALUES
	(7012, "C002", "Pizza", "2008-02-01", 7, 249.50);

#--------------------------------------------------------------------------------------------------------------------------

# (i)
SELECT 
	Client.Cust_ID, Client.Cust_Name, 
	BILL.Item, BILL.Qty, BILL.Price,
	BILL.Qty * BILL.Price AS "Bill Amount"
FROM 
	Client, BILL
WHERE 
	Client.Cust_ID = BILL.Cust_ID;

#--------------------------------------------------------------------------------------------------------------------------

# (ii)
SELECT
	COUNT(Item)
FROM
	BILL
WHERE
	Item = "Pizza"
	AND
	Ord_date BETWEEN 
		"2005-08-01" AND "2005-08-30"
	AND
	Ord_date BETWEEN 
		"2006-08-01" AND "2006-08-30"
	AND
	Ord_date BETWEEN 
		"2007-08-01" AND "2007-08-30"
	AND
	Ord_date BETWEEN 
		"2008-08-01" AND "2008-08-30";

#--------------------------------------------------------------------------------------------------------------------------

# (iii)
SELECT
	COUNT(Ord_date)
FROM
	BILL
WHERE
	Price * Qty > 1700
	AND
	Ord_date BETWEEN 
		"2019-04-16" AND "2019-05-16";

#--------------------------------------------------------------------------------------------------------------------------

# (iv)
SELECT 
	Cust_Name, City
FROM 
	Client
ORDER BY 
	City;

#--------------------------------------------------------------------------------------------------------------------------

# (v)
SELECT 
	Client.Cust_Name,
	BILL.Ord_date
FROM 
	Client, BILL
WHERE 
	Client.Cust_ID = BILL.Cust_ID 
	AND 
	BILL.Ord_date BETWEEN 
		"2003-01-01" AND "2003-12-31";

#--------------------------------------------------------------------------------------------------------------------------

# (vi)
SELECT
	COUNT(City), City
FROM
	Client
GROUP BY
	City;