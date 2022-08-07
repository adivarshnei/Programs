# Write a shell script for simple calculator

if [ $# -ne 3 ]
then
   echo "Wrong number of arguments"
   echo -n "Correct Syntax: "
   echo "$0 (Operand 1) (Operator (+, -, x, /, %)) (Operand 2)"
   exit 1
fi

result=0

if [ $2 = "+" ]
then
   result=$(echo "scale=3; $1 + $3" | bc)
elif [ $2 = "-" ]
then
   result=$(echo "scale=3; $1 - $3" | bc)
elif [ $2 = "x" ]
then
   result=$(echo "scale=3; $1 * $3" | bc)
elif [ $2 = "/" ]
then
   if [ $3 -eq 0 ]
   then
      echo "Cannot Divide by Zero"
      exit 1
   else
      result=$(echo "scale=3; $1 / $3" | bc)
   fi
elif [ $2 = "%" ]
then
   result=$(echo "scale=3; $1 % $3" | bc)
else
   echo "Invalid Operator"
   echo "Valid Operators are: +, -, x, /, %"
   exit 1
fi

echo "$1 $2 $3 = $result"
