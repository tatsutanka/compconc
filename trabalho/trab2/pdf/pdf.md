 <center><img src="./LogoUFRJ.png" width="300" ></center>

**De**: Lucas Tatsuya Tanaka
**DRE**: 118058149
**Github**: [Link para o github tatsutanka](https://github.com/tatsutanka)
**Prof**: Silvana Rossetto
**Curso:** Computacao Concorrente (MAB-117) 2020.2 REMOTO

## Ganho e Desempenho
Sera avaliado se ouve de ganho e desempenho durante a
resolucao do programa atravez da utilizacao de programcao
concorrente para o problema apresentado de multiplicacao de
matrizes proposto no segundo laboratorio.
Sera utilizado a formula de ganho desenpenho discutida
durante as aulas para arealizacao dos calculos do mesmo

 $$ V = \frac{Tsequencial} {Ts +Tp(p)}$$

* ${V}$ representa o ganho de velocidade de execucao
* ${ Tsequencial}$ representa o o tempo total da execucao
do programa sequencial
* ${Ts}$ tempo sequencial do progrma que nao sera divida
em threads
* ${Tp(p)}$ Tempo total da execucao previsto do programa
usando P processadores ${Ts + Tp(p)}$

## Tabela de ganho e desempenho

### Tabela de medias de tempo
E utilizado uma media de 5 testes para determinar a media utilizada

#### Inicio #####

|Tamanho Matriz|500       | 1000    | 2000     |
|:-------------  |:------------- | :----------: | -----------: |
|Media 1 Thread | 0.0082584 | 0.0104276 | 0.0309208
|Media 2 Threads| 0.0081386 | 0.0060078 | 0.0201120
|Media 4 Threads| 0.0080108 | 0.0061256 | 0.0278586

#### Meio ####

|Tamanho Matriz|500       | 1000    | 2000     |
|:-------------  |:------------- | :----------: | -----------: |
|Media 1 Thread | 0.7069134 | 6.6502740 | 72.0131600
|Media 2 Threads| 0.3719378 | 3.1953142 | 35.2025364
|Media 4 Threads| 0.2209910 | 1.5651380 | 21.7078676

#### Final ####

|Tamanho Matriz|500       | 1000    | 2000     |
|:-------------  |:------------- | :----------: | -----------: |
|Media 1 Thread | 0.0001556 | 0.0005170 | 0.0019996
|Media 2 Threads| 0.0001392 | 0.0005786 | 0.0020532
|Media 4 Threads| 0.0001372 | 0.0005160 | 0.0022436

## Tabela de desempenho estimado
|Tamanho Matriz|500       | 1000    | 2000     |
|:-------------  |:------------- | :----------: | -----------: |
| Desempenho 1 Thread | 1 | 1 | 1
| Desempenho 2 Threads| 1.97 | 1.99 | 1.99
| Desempenho 4 Threads| 3.86|  3.98 | 3.99

## Resultados obtidos
Apos  estimar os resultados de desempenho estimado, e a media
de valores de tempo de processamento, se estima que os resultados
adquiridos sao condizentes com as estimativas previstas pelas
tabelas consolidaando assim um bom desempenho do algoritimo
concorente tendo este desempenho muito aproximado das
previsoes realizadas pelas tabelas.
