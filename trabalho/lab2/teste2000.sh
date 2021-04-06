#!/bin/bash

#primeiro numero tem que ser o numero de vezes que foi calculado o numero de threads
variavel=$1

for (( c=1; c<=$variavel; c++ ))
do
    #catando o resultado do a.out
    OUTPUT=$(./a.out 2000 1  >> teste_2000.txt)
done

for (( c=1; c<=$variavel; c++ ))
do
    #catando o resultado do a.out
    OUTPUT=$(./a.out 2000 2  >> teste_2000.txt)
done
for (( c=1; c<=$variavel; c++ ))
do
    #catando o resultado do a.out
    OUTPUT=$(./a.out 2000 4  >> teste_2000.txt)
done
