-- FUNCTION AND PROCEDURE TO GET CUBE
DECLARE
    X NUMBER;
    Y NUMBER;

FUNCTION CUBE_FUNC ( X IN NUMBER )
RETURN INTEGER
IS
BEGIN
    RETURN X * X * X;
END;

PROCEDURE CUBE_PROC ( X IN OUT NUMBER )
IS
BEGIN
    X := X * X * X;
END;

BEGIN
    X := &X;
    Y := X;

    DBMS_OUTPUT.PUT_LINE (
        X ||
        ' ^ 3 = ' ||
        CUBE_FUNC ( X => X ) ||
        ' (function)'
    );

    CUBE_PROC ( X => Y );

    DBMS_OUTPUT.PUT_LINE ( X || ' ^ 3 = ' || Y || ' (procedure)' );
END;

/
