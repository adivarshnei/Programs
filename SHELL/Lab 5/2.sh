# Write a shell script to find the smallest of two numbers

if [ $# -ne 2 ]
then
   echo "Wrong number of arguments"
   exit 1
fi

if [ $1 -lt $2 ]
then
   echo "$1 is smaller than $2"
else
   echo "$2 is smaller than $1"
fi
