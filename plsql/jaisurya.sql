DECLARE
    n INTEGER;
    A BOOLEAN;

FUNCTION check_oe (num IN INTEGER)
RETURN BOOLEAN
IS
BEGIN
	a := TRUE;
	IF n = 0 THEN
		DBMS_OUTPUT.PUT_LINE('The number is Even.');
	ELSE
		DBMS_OUTPUT.PUT_LINE('The number is Odd.');
	END IF;
    
    RETURN A;
END;

BEGIN
	n := &n;
	check_oe(n);
END;
/
