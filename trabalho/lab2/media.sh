#!/bin/bash

contador=1
nTestes=0
nThread=1
iMedia=0
mMedia=0
fMedia=0

while read y
do
   if[$contador%$nThread+2==0]; then
        iMedia=${awk {print $4}<<<"${NUM} ${MEGA}"}+iMedia
        echo $iMedia
   fi

   if[$contador%$nThread+3==0]; then
        mMedia=mMedia #o numero do etxtp
   fi
   if[$contador%$nThread+4==0]; then
        fMedia=fMedia #o numero do etxtp
   fi
    contador=contador+1
    testes=testes+1
    if[$testes%5]; then
        nThread=nthread+1
        echo "$iMedia"
        echo "$mMedia"
        echo "$fMedia"
        $iMedia=0
        $mMedia=0
        $fMedia=0
    fi
done < $1
