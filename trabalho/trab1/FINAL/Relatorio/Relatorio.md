# Sarrus E Laplace

## Descrição do Problema
    O problema que sera abordado no trabalho é o calculo do 
    determinante proporcionada pela expansao de Laplace
    
### Expansao de Laplace 
    Como discutido na matematica a expansao de Laplace ou
    expansao dos cofatores seria um metodo utilizado para 
    o calculo do determinante de uma matriz nxn 
    (explicao de expansao de Laplace ...)

# Projeto da Solucao concorrente 
    
    Dentro do algoritimo concorrente utilizado este 
    pode ser dividido entre duas principais estrategias 
    para a resolucao do algoritimo concorrente.
        A primeira seria sua divisao em blocos ao qual 
    cada Thread seria responsavel pelo calculo deste bloco
        A segunda seria a utilizacao de calculo intercalado 
    entre as matrizes 
        O optado foi a utlizacao de calculo intercalado
    devido sua facilitacao em relacao sua implementacao e 
    pela grande independencia presente no problema fazendo 
    irrelevanete a constante troca entre ambos
        As principail estrutura de dado utilizado no
    algoritimo seria apresenca de Matriz que esta presente
    tanto de maneira local quando global no programa
        Os argumentos que serao passados para o progrma serao
    um caminho para um arquivo com a representacao de uma 
    matriz dentro, alem do numero de Threads e o tamanho da 
    matriz fazendo esse retornar o determinante da 
    matriz representado no arquivo

# Casos de Teste 
    
    O programa sera testado atraves de arquivos pre 
    selecionados com a representacao de matrizes com 
    resultados previamente calculados 

# Avaliacao de Desempenho 

    O sistema operacianl utilizado foi o Arch linux x86_64
    no kernel 5.11.16-arch-1 no window menager awesomewm
    cpu Intel i5-8265U (8) @ 3.9000GHz
    GPU NVIDIA GeForce MX130
    GPU Intel UHD Graphics 620
    Memory 3504Mib / 7804Mib

    Tabela de calculo dos tempos realizar 5 testes 

    Tabela utlizando o ganho de aceleracao atravez de abdhal 
    usando a media da aceleracao


