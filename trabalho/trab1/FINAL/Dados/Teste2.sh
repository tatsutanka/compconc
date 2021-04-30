#!/bin/bash

#primeiro numero tem que ser o numero de testes
VARIAVEL=$1

for((c=1;c<=$VARIAVEL;c++))
do
    #catando o resultado do a.out
    OUTPUT=$(./a.out bar_12.dat 1 12 >> teste_12.txt)
done

for((c=1;c<=$VARIAVEL;c++))
do
    #catando o resultado do a.out
    OUTPUT=$(./a.out bar_12.dat 2 12 >> teste_12.txt)
done

for((c=1;c<=$VARIAVEL;c++))
do
    #catando o resultado do a.out
    OUTPUT=$(./a.out bar_12.dat 4 12 >> teste_12.txt)
done
