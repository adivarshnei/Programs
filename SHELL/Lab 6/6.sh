# Write a shell script that displays a list of all the files in the current
# directory

if [ $# -eq 0 ]
then
   ls -1 -A --color -F
elif [ $# -eq 1 ]
then
   ls -1 -A --color -F $1
else
   echo "Wrong number of arguments"
   echo -n "Correct syntax: "
   echo "$0 (File: Optional)"
   exit 1
fi
