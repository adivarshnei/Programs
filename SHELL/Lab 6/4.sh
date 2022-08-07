# Write a shell script that accept a file name starting and ending line numbers
# as arguments and display all the lines between the given line numbers

if [ $# -ne 3 ]
then
   echo "Wrong number of arguments"
   echo -n "Correct Syntax: "
   echo "$0 (File Name) (Starting Line Number) (Ending Line Number)"
fi

sed -n "$2, ${3}p" "$1"
