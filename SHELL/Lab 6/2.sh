# Write a shell script to print the Fibonacci series of 'n' elements and print
# the sum of the given series

if [ $# -ne 3 ]
then
   echo "Wrong number of arguments"
   echo -n "Correct Syntax: "
   echo "$0 (First Starting Value) (Second Starting Value) (Number of Elements)"
   exit 1
fi

a1=$1
a2=$2
a3=`expr $1 + $2`
n=$3

sum=0
sum=`expr $sum + $a1 + $a2`

echo -n "$a1, $a2"

for((i = 3; i <= n; i++))
do
   echo -n ", $a3"

   sum=`expr $sum + $a3`

   a1=$a2
   a2=$a3
   a3=`expr $a1 + $a2`
done

echo ""
echo "Sum: $sum"
