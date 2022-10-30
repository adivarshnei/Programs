DECLARE
    I NUMBER(1);
    J NUMBER(1);

BEGIN
    << OUTER_LOOP >>
    FOR I IN 1..3 LOOP
        << INNER_LOOP >>
        FOR J IN 1..3 LOOP
            DBMS_OUTPUT.PUT_LINE('I: ' || I || ' J: ' || J);
        END LOOP INNER_LOOP;
    END LOOP OUTER_LOOP;
END;
/
