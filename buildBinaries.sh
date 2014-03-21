#!/bin/bash

export LC_ALL=C
#export DISTCC_FALLBACK=0

for example in $( ls . )
do
	if [ -d "${example}" ]; then
		cd $example
		echo -e "\nBUILDING " $example " \n"
		make
		ret=$?
		if [ $ret -ne 0 ]; 
		then
			echo -e "\n" $example " compile FAILED \n" 
		else
			echo -e "\n" $example "compile SUCCESS \n" 
			mv ./bin/$example ./bin/$example"_IFDEF_.bin"
		fi
		cd ../
	fi
done
