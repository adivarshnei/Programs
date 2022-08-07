# Script for swapping two numbers without using third variable

echo Enter two numbers:
read num1
read num2

echo Numbers before swapping: $num1, $num2

num1=`expr $num1 + $num2`
num2=`expr $num1 - $num2`
num1=`expr $num1 - $num2`

echo Numbers after swapping: $num1, $num2
