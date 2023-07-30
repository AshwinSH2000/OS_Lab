read -a table
for i in ${table[@]}
do
	for ((j = 1 ; j<10 ; j++))
	do
		c='expr $i \* $j'
		echo "$i * $j = $c"
	done
done

