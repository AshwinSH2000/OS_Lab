#echo "Enter file name: "
#read fname
len=`wc -l temp.txt`
echo $len
for((i=1;i<=len;i++))
do
if [`expr $i % 2 == 0`] ; then
sed -n $i\p temp.txt >even.txt
else
sed -n $i\p temp.txt >odd.txt
fi 
done

