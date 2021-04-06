#Estrategia:
cada Thread soma o valor pulando os resultados e no final todos somam os resultados juntos 
exemplo :

2 Threads a soma do for comeca  em i = numero da thread e a soma vai ser de nthreads em nthread

Os resultados coincidem? Nao 
Por que? Isso ocorre devido a divisão de blocos e pelo tamanho dos cálculos, como a quantidade de números eh muito grande ocorre o corte de números para poder ser acomodado o numero em uma variável para a realização das operações, isso ocorrendo devido ao truncamento de variáveis para a realização de operações
Qual solução se aproxima mais rapidamente do valor de π? O valor que se aproxima mais rapidamente do pi no caso seria o concorrente porem com relação a corretude o programa concorrente acaba acumulando maior numero de erros muitas vezes tornando o resultado difuso devido ao truncamento de variáveis para a realização de operações
