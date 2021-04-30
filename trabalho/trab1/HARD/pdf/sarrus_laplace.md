# Sarrus e Laplace (descobrindo o determinante)

## Descricao do Problema
*  Do que se trata e como deve funcionar
    
    ->utilizar o metodo proposto por laplace de maneira concorrente
    para o calculo do determinante

* quais sao os dados de entrada e qual a saıda que deve ser gerada.
    ->A entrada deve ser um arquivo de que contenha o sistema em forma de 
    matriz e a saida deve ser um determiante

## Projeto da Solucao concorrenteo

Descrever o projeto da solução concorrente para o problema:

* listar as estrategias que podem ser usadas para dividir a tarefa principal entre 
 fluxos de execução independentes;

    -> As pkrincipais estrategias para a divisao da terefa seria deichar 
    cada Thread responsavel por um bloco da Matriz 

    -> contra dividir cada linha e coluna para cada Thread

* apontar qual estrategia foi escolhida e por qual motivo;  ́

    -> foi escolhida a estrategia de dividir linha e coluna para 
    cada Thread (Pq?)

* descrever as estruturas de dados principais que serao usadas e em qual escopo 
(global ou local);

    -> sera prinipalmente usado uma Matriz,Ntrheads,tThreads(complemento)

* descrever quais argumentos serao passados para as threads e quais valores ser  ̃ ao ̃
retornados por elas.

    -> devera ser passado em ordem o arquivo que contenha a uma representacao de uma Matriz 
    separada por espaços, o numero de Threads que serao Utilizados e o tamanho da Matriz passada 


## Casos de Teste
Descrever como o programa sera testado:
* descrever o conjunto de casos de teste para avaliação da corretude da solução
proposta;

* descrever os testes que foram realizados e seus resultados.
Nao mostrar as telas de execução, o objetivo aqui é descrever como os testes foram
feitos e os resultados obtidos.
## Avaliacao de desempenho
Descrever como o ganho de desempenho sera avaliado:
* descrever o conjunto de casos de teste para avaliação do desempenho da solução
proposta (variar a dimensao dos dados de entrada e o numero de threads usadas);

* descrever a configuração da maquina onde os testes foram realizados (identificação
do processador, quantidade de nucleos de execução, sistema operacional);

* descrever quantas vezes o mesmo caso de teste foi executado e qual medida de
tempo foi escolhida (repetir a execuc ̧ao ao menos 5 vezes, tomando o menor tempo  ̃
ou o tempo medio);  ́

* mostrar o calculo da acelarac ̧  ́ ao;  ̃

* apresentar os resultados obtidos condensados na forma de tabela ou grafico.  ́
Nao mostrar as telas de execuc ̧  ̃ ao, o objetivo aqui  ̃ e apresentar os resultados finais  ́
obtidos (tempo de execuc ̧ao e acelerac ̧  ̃ ao).
## Discussao
Apresentar uma analise dos resultados obtidos:  ́
* discutir se o ganho de desempenho alcanc ̧ado foi o esperado ou nao ̃ e por quais
motivos;
* apresentar poss ́ıveis melhorias do programa, se for o caso;
* discutir outras questoes que forem pertinentes;  ̃
* descrever dificuldades encontradas para a realizac ̧ao do trabalho, se for o caso.
## Referencia bibliografica

