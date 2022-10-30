DECLARE
    A INTEGER := 10;
    B INTEGER := 20;
    C INTEGER;
    F REAL;

BEGIN
    C := A + B;
    DBMS_OUTPUT.PUT_LINE('VALUE OF C: ' || C);
    F := 70.0 / 3.0;
    DBMS_OUTPUT.PUT_LINE('VALUE OF F: ' || F);
END;
/
