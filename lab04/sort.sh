read -a stringarray
for i in ${stringarray[@]}
do
	echo "$i"
done

for (( i=0; i<${#stringarray[@]}-1; i++))
do
	for (( j=i+1; j<${#stringarray[@]}; j++))
	do
		if [ "$stringarray[$i]" > "$stringarray[$j]" ]; then
		temp=${stringarray[$i]}
		stringarray[$i]=${stringarray[$j]}
		stringarray[$j]=$temp
		fi
	done
done
for i in ${stringarray[@]}
do
	echo "$i"
done
