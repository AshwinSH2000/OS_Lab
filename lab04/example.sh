read -a array1
echo "array1"
for (( i=0; i<${#array1[@]}; i++ ))
do
echo ${array1[$i]}
#echo "$i"
done
echo "execution complete"
