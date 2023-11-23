#!/bin/bash
 
DIR="build"

cd ~/myportal
cp -r ./static_contents/ ./build/static_contents/
 
if [ ! -d $DIR ];then
  mkdir $DIR
fi

cd $DIR
cmake ..
make
./myportal