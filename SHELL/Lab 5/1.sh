# Write a shell script to find whether a number is odd or even

if [ $# -ne 1 ]
then
   echo "Wrong number of arguments"
   exit 1
fi

if [ `echo "$1 % 2" | bc` -eq 0 ]
then
   echo "$1 is even"
else
   echo "$1 is odd"
fi
