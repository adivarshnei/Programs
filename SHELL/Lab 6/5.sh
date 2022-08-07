# Write a shell script that deletes all lines containing a specific word

if [ $# -ne 2 ]
then
   echo "Wrong number of arguments"
   echo -n "Correct Syntax: "
   echo "$0 (File Name) (Word)"
   exit 1
fi

grep -v $2 $1 > modified.txt

cat modified.txt
