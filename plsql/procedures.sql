DECLARE
    A NUMBER;
    B NUMBER;
    C NUMBER;
    X NUMBER;
    Y NUMBER;

PROCEDURE HELLO_WORLD
IS
BEGIN
    DBMS_OUTPUT.PUT_LINE('HELLO WORLD!');
END;

PROCEDURE FIND_MIN(X IN NUMBER, Y IN NUMBER, Z OUT NUMBER)
IS
BEGIN
    IF X < Y THEN
        Z := X;
    ELSE
        Z := Y;
    END IF;
END;

PROCEDURE CUBE(X IN OUT NUMBER)
IS
BEGIN
    X := X * X * X;
END;

BEGIN
    A := 5;
    B := 10;
    X := 2;
    Y := X;

    HELLO_WORLD;
    FIND_MIN(X => A, Y => B, Z => C);
    CUBE(X => Y);

    DBMS_OUTPUT.PUT_LINE('FIND_MIN(' || A || ', ' || B || ', ' || C || ')');
    DBMS_OUTPUT.PUT_LINE(X || ' ^ 3 = ' || Y);
END;
/
