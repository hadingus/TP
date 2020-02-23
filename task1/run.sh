#!/bin/bash

directory=$1
extension=$2
name_dir=$3
name_arch=$4

dir_path="$(pwd)/$name_dir"
mkdir $name_dir
for val in $(find $directory -name "*.$extension")
do
	cp --parents $val $dir_path
done
tar -acf $name_arch $name_dir
echo done