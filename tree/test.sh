#!/bin/sh -v
if [ -f "./parent_childs.c" ] ;then
echo "ls is a file "
else 
echo "ls is not a file"
fi

i=10;
while [ $i -gt 0 ];do 
((i--))
echo "test"
done 
