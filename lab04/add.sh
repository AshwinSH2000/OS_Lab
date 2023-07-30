add() {
a=$1
b=$2
c=`echo $a+$b | bc`
return "$c"
}
###main script starts here
echo "start of scrpit"
add $1 $2
x=$?
echo "The sum is $x"
echo "end of script"

