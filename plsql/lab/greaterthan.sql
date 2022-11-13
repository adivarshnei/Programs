-- FUNCTION AND PROCEDURE TO FIND GREATER NUMBER
DECLARE
    X NUMBER;
    Y NUMBER;
    Z NUMBER;

FUNCTION GREATER_FUNC ( X IN NUMBER, Y IN NUMBER )
RETURN NUMBER
IS
BEGIN
    IF X >= Y THEN
        RETURN X;
    ELSE
        RETURN Y;
    END IF;
END;

PROCEDURE GREATER_PROC ( X IN NUMBER, Y IN NUMBER, Z OUT NUMBER )
IS
BEGIN
    IF X >= Y THEN
        Z := X;
    ELSE
        Z := Y;
    END IF;
END;

BEGIN
    X := &X;
    Y := &Y;

    GREATER_PROC ( X => X, Y => Y, Z => Z );

    DBMS_OUTPUT.PUT_LINE (
        GREATER_FUNC ( X => X, Y => Y ) ||
        ' is the greater of ' ||
        X ||
        ' and ' ||
        Y ||
        ' (function)'
    );

    DBMS_OUTPUT.PUT_LINE (
        Z ||
        ' is the greater of ' ||
        X ||
        ' and ' ||
        Y ||
        ' (procedure)'
    );
END;

/
