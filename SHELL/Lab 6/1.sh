# Write a shell script to find the factorial of any number

if [ $# -ne 1 ]
then
   echo "Wrong number of arguments"
   echo "Correct Syntax: $0 (Number)"
   exit 1
fi

fact=$1

for ((i = $1 - 1; i >= 2; i--))
do
   fact=`expr $fact \* $i`
done

echo "$1! = $fact"

