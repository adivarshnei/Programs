DECLARE
    a NUMBER := 0;
    b NUMBER := 1;
    temp NUMBER;
    n NUMBER := 10;
    i NUMBER;
BEGIN
    DBMS_OUTPUT.PUT_LINE('fibonacci series is :');
    DBMS_OUTPUT.PUT_LINE(a);
    DBMS_OUTPUT.PUT_LINE(b);

    FOR i IN 2..n
    LOOP
       temp:= a + b;
       a := b;
       b := temp;
       DBMS_OUTPUT.PUT_LINE(temp);
    END LOOP;
END;
/
