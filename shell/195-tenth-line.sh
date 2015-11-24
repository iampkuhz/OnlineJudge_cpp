# if less than 10 line ,still output last line !!
#head -n 10 file.txt | tail -n 1
sed -n "10p" file.txt
