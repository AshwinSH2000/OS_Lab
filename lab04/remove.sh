read -a file
for i in ${file[@]}
do
	if [ -f $i ]; then
		rm -i $i
	else
		echo "File not found"
	fi
done

