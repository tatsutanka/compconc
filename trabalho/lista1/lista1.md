# Questao 1
## A
A principal caracteristica de um programa concorrente 
seria a mudança de paradigma de programação, na qual ocorre 
a troca do ideario da utilizacao apenas de uma Thread
para a troca do uso de multiplas Threads no progrma 
visando o aproveitamento da arquitetura moderna de 
processadores.
## B
A acelaração maxima sera de 2,5 caso sejam utilizados 4 
Threads para o processamento da tarefa, caso sejam utilizado
mais Threads o tempo proposto de aceleração sera maior 
de acordo com a lei de Amdhal.
## C
Seção critica seria o trecho do codigo concorrente na qual 
deve ser impedido o surgimento de resultados indesejaveis 
devido ao acesso de multiplas Threads a mesma parte do codigo.
## D
A sincronização por exclusão mutua seria um dos diversos
mecanismos de programação concorrente na qual tem por 
objetivo controlar a ordem de execução sob a cessão 
critica do codigo.

# Questão 2

Para -3 não é possivel pois mesmo com a falta de 
sincronização por exclusão mutua os valores das Threads 
nao conseguiram chegar nesses valores pois seria necessario
que as 3 operacoes de x-- fosem realizados uma em seguida 
da outra porem isso nao é possivel fazendo sempre o menor  
resultado ser -2


Para -1 é possivel atraves das operaçoes descritas
*  T2(1) o valor de x se torna -1
*  T2(2) o valor se torna -2 
*  T2(3) O if aceita o valor de x
*  T1(1) o valor de x se torna -1 
*  T2(4) o valor printado sera -1 

Para 1 é possivel atraves das operaçoes descritas
*  T3(1) o valor se torna 1 
*  T3(2) o valor se torna 2
*  T3(3) o if aceita o valor de x
*  T2(1) o valor x se torna 1
*  T3(4) o valor printado sera 1

Para 3 é possivel atraves das operaçoes descritas
* T3(1) o valor se torna 1 
* T3(2) o valor se torna 2
* T3(3) o if aceita o valor de x
* T1(1) o valor x se torna 3
* T3(4) o valor printado sera 3

# Questão 3

## A
A seguinte implementação não garante exclusão mutua pois 
pode ocorrer de ser executado da seguinte maneira:

* T1(1) a aplicação é rejeitada de entrar 
* T0(1) se adentra no secao critica
* T1(2)
* T1(3) se troca o valor de TURN para 0
* T0(2) se executa a secao critica do programa mesmo com 
as varivel TURN não sendo consistente com o loop While 

Logo com o termino do processamento se indentifica que a 
garantia de exclusão mutua nao existe.

## B
Nao essa solução nao atende os requisitos de implementação 
propostos, pois acaba por não apresentar a seção de entrada
e a seção de saida propostas.

# Questao 4
```c
int x=0, y=0; //variaveis globais

//-----------------------------Thread 1
void *T1(void *id){   
 int a=0;             
 while(a<2) {         
  mutex_lock          
 if(x==0)             
 {printf("x=%d\n",x);}
 a++;                 
 printf("a=%d\n", a); 
        }                  
    mutex unlock
    }

//-----------------------------Thread 2
 void *T2(void *id){       
 int a=2;                  
 while(a>0) {             
   mutex_lock             
 if(x==0)                 
 {printf("x=%d\n",x);}    
 a--;                     
 fprintf(file,"a=%d\n", a)
   mutex_unclock          
  }  }                     

//-----------------------------Thread 3

void *T3(void *id){
  mutex_lock
y++;
  mutex_unlock
}

```
Foram retirados os x++ e x-- pois em sua execução
havia uma redundancia, pois caso seja usado exclusão mutua
as operacoes de sobre o x resultariam sempre em x=0. Já 
os locks foram posicionados entre a seção critica com 
o objetivo de gerar a exclusão mutua.

# Questão 5:

##  A
As palavras escritas pelos programas no arquivo bar seriam 
"Ola mundo!" e "foo nao existe".

##  B
Não, pois mesmo com o uso da biblioteca pthread.h no código,
apenas foi utilizado uma Thread para realizar o processamento
da tarefa, gerando assim nenhuma disputa pelo mesma variável
durante a realização da função tarefa no programa.


