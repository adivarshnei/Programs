DECLARE
	a NUMBER;
	b NUMBER;
	c NUMBER;
BEGIN
	DBMS_OUTPUT.PUT_LINE('Enter a:');
	a := &a;

    DBMS_OUTPUT.PUT_LINE('Enter b:');
	b := &b;

    DBMS_OUTPUT.PUT_LINE('Enter c:');
	c := &C;

    IF (a > b) AND (a > c)
	THEN
	    DBMS_OUTPUT.PUT_LINE('A is GREATEST' || A);
    ELSIF (b > a) AND (b > c)
	THEN
	    DBMS_OUTPUT.PUT_LINE('B is GREATEST' || B);
    ELSE
	    DBMS_OUTPUT.PUT_LINE('C is GREATEST' || C);
    END IF;
END;
/
