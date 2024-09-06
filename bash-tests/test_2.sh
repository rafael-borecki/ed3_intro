#! /bin/bash

 make all
 cat ../entradas/2_1.in | make run > /tmp/dbg1
 cat ../entradas/2.out > /tmp/dbg2
 
 diff /tmp/dbg1 /tmp/dbg2
