DECLARE
    TEST INTEGER DEFAULT 100;
    TESTCHAR CHAR DEFAULT 'D';

BEGIN
    IF ( TEST > 100 ) THEN
        DBMS_OUTPUT.PUT_LINE('1, ' || TEST || ' > 100');
    ELSIF (TEST < 100) THEN
        DBMS_OUTPUT.PUT_LINE('2, ' || TEST || ' < 100');
    ELSE
        DBMS_OUTPUT.PUT_LINE('3, ' || TEST || ' = 100');
    END IF;

    CASE TESTCHAR
        WHEN 'A' THEN
            DBMS_OUTPUT.PUT_LINE('1');
        WHEN 'B' THEN
            DBMS_OUTPUT.PUT_LINE('2');
        WHEN 'C' THEN
            DBMS_OUTPUT.PUT_LINE('3');
        WHEN 'D' THEN
            DBMS_OUTPUT.PUT_LINE('4');
        WHEN 'E' THEN
            DBMS_OUTPUT.PUT_LINE('5');
        ELSE
            DBMS_OUTPUT.PUT_LINE('0');
    END CASE;

    CASE
        WHEN TESTCHAR = 'A' THEN
            DBMS_OUTPUT.PUT_LINE('1');
        WHEN TESTCHAR = 'B' THEN
            DBMS_OUTPUT.PUT_LINE('2');
        WHEN TESTCHAR = 'C' THEN
            DBMS_OUTPUT.PUT_LINE('3');
        WHEN TESTCHAR = 'D' THEN
            DBMS_OUTPUT.PUT_LINE('4');
        WHEN TESTCHAR = 'E' THEN
            DBMS_OUTPUT.PUT_LINE('5');
        ELSE
            DBMS_OUTPUT.PUT_LINE('0');
    END CASE;
END;
/
