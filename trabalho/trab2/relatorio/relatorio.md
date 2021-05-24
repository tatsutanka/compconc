
#Leitores e escritores com prioridade para escrita
* descrever os requisitos basicos do problema, e como 
funciona a prioridade para escrita;

Os requisitos necessarios para a eleaboracao do problema seria 
um progrma concorrenete ao qual obedece o padrao leitor escritor
com prioridade para escritored basseando se principalmentes em um 
formato de atuadores e sensores na 
qual a principal funcao dos sensores seria a captaçâo dos dados de 
temperatura que variam de 25 a 40 graus, ja os atuadores sendo responsavel
por emanar sinais vermelho caso a temperatura captada nas ultimas 5 medidas 
for maior que 35, amarelo caso nas ultimas 15 medidas tenha se medido 
5 vezes temperatura maior do que 35, e verde caso nenhuma das possibilidades 
seja correspondida.
Com relacao a prioridade para a escrita o principal funcionamento seria o 
acesso sendo garantido para leitores a qualquer momento ao recurso compartilhado
porem com a excessao de tempos quando o escritor utiliza o espaco compartilhado 
os leitores sao bloqueados e dao prioridade para os escritores estes que 
escrevem um de cada vez no espacao compartilhado tendo prioridade para os 
escritores na qual quando durante fila de execução aparecer um escritor este 
ganha preferencia para a execução da escrita na varivel compartilhada 
este sendo feitto atravez do formato FIFO(file in file out).
O padrao adaptado no programa apresenta possibilidade de starvation 
para as Threads leitoras na qual estas tem grande difuculdade para ganhar 
execucao durante o processamneto do programa possibilitando assim um constante 
bloqueio das Threads e impossibilidade do acesso da mesma.

* descrever as decisoes principais do projeto da solução;

As principais decisoes tomadas foram a divisao do projeto em dois 
principais arquivos de TAD sendo eles Queue.h e Thread.h
na qual Queue.h fica responsavel pelas funcoes utilizadas para 
atender o padrao FIFO requisitado pelo problema, e Thread.h contendo
as funcoes responsaveis por controlar os fluxos de execusao do progrma 
e as proprias Threads Leitora e Escritora.

* descrever as decisoes principais de implementação da solução

Para que fosse possivel a implementacao de Threads junto a 
TAD é necessario a utilizacao de funcoes inicializadoras para que 
as variaveis globais pudessem ser acessadas por todas as Threads
respeitandando as particularidades da implementacao de TAD alem disso 


* descrever as estruturas de dados utilizadas e as funçoes 
implementadas;

As principais duas estruturas de dados utilizadas sao Queue e 
Estrutura na qual Queue e composto por 4 inteiros e um ponteiro de inteiro 
na qual os 4 inteiros servem como indentificadores de tamando posicao,
da frente, e posicao de tras e o ponteiro representando um array
a estrutura Estrutura e composto por 3 Queue cada uma representando 
os valores de temperatura captado os ids e a quantidade de vezes 
em que o valor foi lido.
Se apresenta funcoes responsaveis pelo controle da estrura Queue 
como isFull que mede quando uma fila se encontra cheia, isEmpty para 
quando uma fila se encontra vazia, front que mostra a posicao do 
valor que esta a frente da fila, rear que mostra a posicao do valor 
que esta no final da fila, dequeue que retira o primeiro valor da fila,
enqueue que colocal o valor no final da fila e createQueue que
inicializa a estrutura de fila.
Em seguida as principais funcoes responsaveis pelo controle de Threads 
no padrao leitor escritor com prioridade para escritores 
sao apresentadas como entLeitor, saiLeitor, entEscritor, saiEscritor
que garantem a execucao das Threads na ordem especificada pelo padrao,
alem disso se encontra as funcoes Leitor e Escritor que realizam as 
Threads leitoras e escritoras respectivamente.
Sao apresentadas 2 principais funcoes responsaveis pela inicializacao 
de estrutras e variaveis de controle de processo, createEstrutura é 
responsavel pela inicializacao da estrutura Estrutura e thread_lock_init 
sendo responsavel por inicializar as variaveis de semaforo responsaveis 
pelos bloqueios e exclusao mutua das Threads.

* descrever os testes realizados: como foram planejados e como garantem que 
todos os requisitos do padrao foram atendidos.



#Aplicação de monitoramento de temperatura
Descrever o projeto da soluc ̧ao concorrente para o problema:  ̃
* descrever as estruturas de dados principais e seu escopo 
(global ou local);

Podemos descrever como sendo as principais estruturas de dados 
utilizados sendo Estrutura e Queue,ambos estando em escopo global 

* descrever quais argumentos sao passados para as threads e 
quais valores são retornados por elas;

Sao pasados os Ids atraves do pthread_create como argumento 
nao sao retornados os valores atravez dos pthread_exit
porem sao printados os requisitos do programa 

* descrever o algoritmo executado por cada tipo de thread;

Os algoritmos utilizados pelas Threads Leitor podem ser descrito 
pela execusao de entLeitor que fica junto com saiLeitor responsavel
pelas ordem de execusao das Threads leitoras, em seguida e 
armazenado os 15 primeiros valores em um array caso este valor lido 
seja igual ao id da Thread e para cado valor que seja do mesmo
id tambem se almenta o numero de leituras na Queue reponsavel 
pela leitura, em seguida os 15 valores sao relidos e caso 
os valores sejam maior que 35 se aumenta o valor das variveis
responsaveis e caso seja menor que 35 o valor responsavel pelo
disparo do alerta vermelho zera, em seguida é verificado se 
é atendido os valores maiores que 5 e caso sim, é disparado 
os alertas vermelho e amarelo caso nenhuma das condicoes 
sejam atendidas sera dispara o alerta verde em seguida
é calculado a media dos numeros presentes dentro do array 
principal de valores. As Threads Escritoras podem ser descritas 
pela utilizacao de entEscritor que junto a saiEscritor sao
responsaveis pelo controle da ordem de execusao em seguida 
se utiliza a funcao sleep para simular o tempo de captacao de
temapratura por sensores em seguida se calcula um numero
aleatorio que varia entre 25 a 40 caso o numero seja maior que 
30 ele sera armazenado a Queue de valores, em seguida é captado
e armazenado na mesma posicao na fila de id o prorio indentificador 
da Thread 

* descrever a interface com o usuario da aplicação; 
(Não mostrar o codigo fonte, ele sera visto diretamente. 
O objetivo aqui  ́ e descrever e justificar as decisoes de
projeto e implementac ̧ao tomadas.)

* descrever os testes realizados: como foram planejados e como garantem que
todos os requisitos da aplicac ̧ao foram atendidos. (  ̃ Nao mostrar as telas de  ̃
execuc ̧ao, o objetivo aqui  ̃ e descrever como os testes foram feitos e os resulta-  ́
dos obtidos.)

#Discussao
Apresentar uma analise dos resultados obtidos:  ́
* discutir questoes que forem pertinentes;  ̃
* descrever dificuldades encontradas para a realizac ̧ao do trabalho, se for o caso.  ̃
Nao ser  ̃ a necess  ́ ario fazer avaliac ̧  ́ ao de desempenho da aplicac ̧  ̃ ao.  ̃

Os resultados apresentados condizem com o definido pelo 
trabalho 
As principais dificultades apresentadas foram principalmente 
a interpretacao dos requisitos dos problemas 

#Referencias bibliograficas
Listar as referencias bibliograficas utilizadas.
