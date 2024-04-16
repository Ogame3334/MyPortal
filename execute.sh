#!/bin/bash
 
DIR="build"

cd ~/myportal
 
if [ ! -d $DIR ];then
  mkdir $DIR
fi

cd $DIR
cmake ..
make
./myportal
