-- FACTORIAL

DECLARE
	X INTEGER := 5;
	Y INTEGER;

FUNCTION FACTORIAL ( X IN INTEGER )
RETURN INTEGER
IS
BEGIN
	IF X = 1 THEN
		RETURN 1;
	ELSE
		RETURN X * FACTORIAL ( X - 1 );
	END IF;
END;

BEGIN
	Y := FACTORIAL ( X );
	
	DBMS_OUTPUT.PUT_LINE ( X || '! = ' || Y );
END;
/