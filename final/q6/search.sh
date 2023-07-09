#!/bin/bash

grep $* directory

if [ $? -eq 0 ];
then
    echo There is a match 
else
    echo no such department found 
fi


