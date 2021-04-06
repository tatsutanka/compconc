#!/bin/bash

#primeiro numero tem que ser o numero de vezes que foi calculado o numero de threads
variavel=$1

for (( c=1; c<=$variavel; c++ ))
do
    #catando o resultado do a.out
    OUTPUT=$(./a.out 500 1  >> teste_500.txt)
done

for (( c=1; c<=$variavel; c++ ))
do
    #catando o resultado do a.out
    OUTPUT=$(./a.out 500 2  >> teste_500.txt)
done
for (( c=1; c<=$variavel; c++ ))
do
    #catando o resultado do a.out
    OUTPUT=$(./a.out 500 4  >> teste_500.txt)
done
