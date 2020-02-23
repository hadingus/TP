#!/bin/bash

directory=$1
extension=$2
name_dir=$3
name_arch=$4

dir_path="$(pwd)/$name_dir"
mkdir $name_dir
for val in $(find $directory -name "*.$extension")
do
	name=${val##*/}
	name=${name%.*}
	i=0
	for upd in $(find $dir_path -name "$name*.$extension")
	do
		((i++))
	done
	cp $val $dir_path/$name\_$i.$extension
done
tar -cf $name_arch.tar.gz $name_dir
echo done