# Write a shell script to find the largest of three numbers

if [ $# -ne 3 ]
then
   echo "Wrong number of arguments"
   exit 1
fi

if [ $1 -gt $2 -a $1 -gt $3 ]
then
	echo "$1 is greater than $2 and $3"
elif [ $2 -gt $1 -a $2 -gt $3 ]
then
   echo "$2 is greater than $1 and $3"
else
   echo "$3 is greater than $1 and $2"
fi
