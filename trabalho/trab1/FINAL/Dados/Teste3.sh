#!/bin/bash

#primeiro numero tem que ser o numero de testes
VARIAVEL=$1

for((c=1;c<=$VARIAVEL;c++))
do
    #catando o resultado do a.out
    OUTPUT=$(./a.out bar_13.dat 1 13 >> teste_13.txt)
done

for((c=1;c<=$VARIAVEL;c++))
do
    #catando o resultado do a.out
    OUTPUT=$(./a.out bar_13.dat 2 13 >> teste_13.txt)
done

for((c=1;c<=$VARIAVEL;c++))
do
    #catando o resultado do a.out
    OUTPUT=$(./a.out bar_13.dat 4 13 >> teste_13.txt)
done
