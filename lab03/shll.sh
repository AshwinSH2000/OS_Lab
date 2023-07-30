#arithmetic operation
#echo "enter any number:"
#read a
#echo "Enter the operator"
#read op
#echo "enter the 2nd number:"
#read b
#m=$((a $op b))
#echo "result of $a $op $b is $m"

#checking if a file is dir or file
#echo "enter any file/directory"
#read a1 
#if [ -f $a1 ]; then
#	echo "it is a regular file"
#else
#	echo "it is a directory"
#fi

#checking equality of numbers
#echo "enter any number"
#read a 
#echo "enter any number"
#read b
#if [ $a == $b ]; then
#	echo "equal"
#else
#	echo "not equal"
#fi

#listing files
#echo "enter any text"
#read pattern
#ls *$pattern*.txt  

#salarycalculation
echo "Enter basic sal:"
read basic
echo "enter TA"
read ta
#ans=$(( basic + ta ))
echo "salary is"
echo "$basic * 1.1 + $ta" | bc 



