#!/bin/bash

directory=$1
extension=$2
name_dir=$3
name_arch=$4

dir_path="$(pwd)/$name_dir"
mkdir -p $name_dir
for file in $(find $directory -name "*.$extension")
do
	name=${file##*/}
	name=${name%.*}
	cnt=0
	for count in $(find $dir_path -name "$name*.$extension")
	do
		((cnt++))
	done
	if [ "$cnt" -eq 0 ]
	then 
		cp $file $dir_path/$name.$extension
	else
		cp $file $dir_path/$name\_$cnt.$extension
	fi
done
tar -acf $name_arch $name_dir
echo done