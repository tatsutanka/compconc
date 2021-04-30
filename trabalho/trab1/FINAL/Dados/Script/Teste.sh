#!/bin/bash

#primeiro numero tem que ser o numero de testes
VARIAVEL=$1

for((c=1;c<=$VARIAVEL;c++))
do
    #catando o resultado do a.out
    OUTPUT=$(./a.out bar_11.dat 1 11 >> teste_11.txt)
done

for((c=1;c<=$VARIAVEL;c++))
do
    #catando o resultado do a.out
    OUTPUT=$(./a.out bar_11.dat 2 11 >> teste_11.txt)
done

for((c=1;c<=$VARIAVEL;c++))
do
    #catando o resultado do a.out
    OUTPUT=$(./a.out bar_11.dat 4 11 >> teste_11.txt)
done
