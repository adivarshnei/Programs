-- FUNCTION TO FIND FACTORIAL
DECLARE
    X INTEGER;
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
    X := &X;
    Y := FACTORIAL( X );

    DBMS_OUTPUT.PUT_LINE ( X || '! = ' || Y );
END;

/
