-- FUNCTION AND PROCEDURE TO TEST ODD OR EVEN
DECLARE
    X NUMBER;

FUNCTION ODD_EVEN_FUNC ( X IN NUMBER )
RETURN BOOLEAN
IS
BEGIN
    IF MOD ( X, 2 ) = 0 THEN
        RETURN TRUE;
    ELSE
        RETURN FALSE;
    END IF;
END;

PROCEDURE ODD_EVEN_PROC ( X IN NUMBER )
IS
BEGIN
    IF MOD ( X, 2 ) = 0 THEN
        DBMS_OUTPUT.PUT_LINE ( X || ' is even (procedure)' );
    ELSE
        DBMS_OUTPUT.PUT_LINE ( X || ' is odd (procedure)' );
    END IF;
END;

BEGIN
    X := &X;

    ODD_EVEN_PROC ( X => X );

    IF ODD_EVEN_FUNC ( X => X ) = TRUE THEN
        DBMS_OUTPUT.PUT_LINE ( X || ' is even (function)' );
    ELSE
        DBMS_OUTPUT.PUT_LINE ( X || ' is odd (function)' );
    END IF;
END;

/
