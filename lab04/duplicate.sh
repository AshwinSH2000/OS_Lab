read -a txt
echo "$txt"
if [ -f $txt ]; then
	cp "$txt" "$txt(duplicate)"
fi
 
