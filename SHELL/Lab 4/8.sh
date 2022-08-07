# Script for swapping two numbers using third variable

echo Enter two numbers:
read num1
read num2

echo Numbers before swap: $num1, $num2

temp=$num1
num1=$num2
num2=$temp

echo Numbers after swap: $num1, $num2
