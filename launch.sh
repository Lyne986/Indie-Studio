#!/bin/bash

version=$1

export return_code=0

if [ $1 = "build" ] ; then
    echo "<-- using build command of the cmake -->"
    cd build 
    cmake .. -G "Unix Makefiles" -DCMAKE_MODULE_PATH=/usr/local/bugs/run/cmake_modules/ -DCMAKE_BUILD_TYPE=Release -DCMAKE_RUNTIME_OUTPUT_DIRECTORY=.
    cmake --build .
    return_code=$?
    cp ./bomberman ../
    cd ../
    if [ $return_code != 0 ] ; then
        echo "--> build failed: make do not compil"
    fi
    exit $return_code
fi
if [ $1 = "make" ] ; then
    echo "<-- using make command of the makefile -->"
    cd build;
    make
    return_code=$?
    cp ./bomberman ../
    cd ../
    if [ $return_code != 0 ] ; then
        echo "--> build failed: make do not compil"
    fi
    exit $return_code
fi

if [ $1 = "clear" ] ; then
    echo "<-- clearing project -->"
    rm -rf build/* ; touch build/.gitkeep ; rm bomberman
    exit 0
fi
