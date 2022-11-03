DECLARE
    v_no  NUMBER := &no;
    f NUMBER := 1;
    n_temp NUMBER;

BEGIN
    n_temp := v_no;
    WHILE v_no > 0
    LOOP
        f := f * v_no;
        v_no := v_no - 1;
    END LOOP;

    DBMS_OUTPUT.PUT_LINE('factorial of ' || n_temp ||' is ' || f);
END;
/
