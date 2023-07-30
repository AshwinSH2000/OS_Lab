echo "HelloWorld"
echo "Enter the value of a:"
read a
echo "The sq of a is" 
a=$(expr $a * $a)
echo $a
