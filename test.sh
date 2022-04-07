#!/bin/bash
assert(){
    expected = "$1"
    input = "$2"

    ./mcc "$imput" > tmp.s
    cc -o tmp tmp.s
    ./tmp
    actual = "$?"

    if [ "$actual" = "$expected" ]; then
        echo "$input => $actual"
    else 
        echo "$imput => $expected expected, but got $actual"
        exit 1
    fi
}