clc
clear all
close all

display('Lab 8')
display('Aim: Writing brief Scripts starting each Script with a request for input (using input) to Evaluate the function h(T) using if-else statement, where h(T) = (T - 10) for 0 < T < 100 = (0.45 T + 900) for T > 100. Exercise: Testing the Scripts written using A). T = 5, h = -5 and B). T = 110, h = 949.5')


display('')

T = input("Enter the value of T: ")

if (T > 0) && (T < 100)
    h = T - 10;
    
    display("h(T) = T - 10")
elseif (T >= 100)
    h = (0.45 * T + 900);
    
    display("h(T) = 0.45 * T + 900")
elseif (T==0)
    h = 0;
    
    display("h(T) = 0")
elseif (T < 0)
    h = (T ^ 3 + 20);
    
    display("h(T) = T ^ 3 + 20")
else
    display("Erroneous Value Entered")
    quit
end

fprintf("T = %.2f\n", T)
fprintf("h(%.2f) = %.2f\n", T, h)