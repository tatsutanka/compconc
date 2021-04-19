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

# Questão 5
## A 
As palavras escritas pelos progrmas no arquivo bar seriam 
"Ola mundo!" e "foo nao existe".

## B

Não, pois mesmo com o uso da biblioteca pthread.h no codigo,
apenas foi utilizado uma Thread para realizar o processamento
da tarefa, gerando assim nenhuma disputa pelo mesma variavel
durante a relização da função tarefa no programa.

