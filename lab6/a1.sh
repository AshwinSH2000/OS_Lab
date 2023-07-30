#to check whether a given number is prime or not

echo "Enter the number: "
read num
c=0
b=`expr $num`
for ((i=2; i<b/2;i++))
do
	if test `expr $b % $i` -eq 0 
	 then
	c=1
	fi
done
if test $c -eq 0 
then
echo "Prime"
else
echo "Not prime"
fi 
