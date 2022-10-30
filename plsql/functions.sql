DECLARE
    A NUMBER;
    B NUMBER;
    C NUMBER;

FUNCTION FIND_MIN(X IN NUMBER, Y IN NUMBER)
RETURN NUMBER
IS
    Z NUMBER;
BEGIN
    IF X < Y THEN
        Z := X;
    ELSE
        Z := Y;
    END IF;

    RETURN Z;
END;

FUNCTION TEST
RETURN NUMBER
IS
BEGIN
    RETURN 10;
END;

BEGIN
    A := 23;
    B := 45;
    C := TEST;

    DBMS_OUTPUT.PUT_LINE('MIN(' || A || ', ' || B || ') = ' || C);
END;
/
