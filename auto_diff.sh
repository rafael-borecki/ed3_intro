#! /bin/bash
make all
cat ./entradas/1.in | make run
cat ./entradas/1_2.in | make run > /tmp/dbg1
cat ./entradas/1_3.in | make run > /tmp/dbg2

diff /tmp/dbg1 /tmp/dbg2
