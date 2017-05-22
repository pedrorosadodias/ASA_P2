# Proj2_ASA
### Descrição do Problema
O Sr. João Caracol, primeiro-ministro do Bananadistão, resolveu fazer um investimento em infra-estruturas no país por forma a integrar todas as cidades de média e grande dimensão numa rede de ligações aéreas e rodoviárias. O objectivo passa então por construir aeroportos e estradas novas que interliguem todas as cidades. Considerando que a construção de cada estrada e cada aeroporto tem um custo, o Sr. João Caracol pretende obter a solução que minimize o valor total da despesa.

Na construção da rede, considera-se que uma cidade que tenha um aeroporto consegue ligar- se a outras cidades com aeroportos. As cidades sem aeroporto, precisam de estradas para outras cidades por forma a ficarem ligadas. Considera-se que uma estrada liga duas cidades em ambos os sentidos.

O seu programa deverá decidir quais as estradas a construir e onde construir aeroportos de tal forma que todas as cidades fiquem ligadas em rede, e minimizando o custo total das obras.

Havendo soluções óptimas com o mesmo custo total, devem considerar a solução que mini- miza o número de aeroportos a construir.


### Input
O ficheiro de entrada contém a informação do número de cidades e do custo de construção de cada estrada ou aeroporto.
O input é definido da seguinte forma:
 
• Uma linha com o número N (N ≥ 2) de cidades.

• Uma linha com o número A (0 ≤ A ≤ N) de potenciais aeroportos a construir.

• Uma sequência de A linhas, em que cada linha contém dois inteiros a e c (separados por um espaço em branco), onde c denota o custo de construir um aeroporto na cidade a.

• Uma linha com o número E de potenciais estradas a construir.

• Uma sequência de E linhas, em que cada linha contém três inteiros a, b e c (separados por um espaço em branco), onde c denota o custo de construir uma estrada entre as cidades a e b.

Assume-se que a identificação das cidades é um inteiro entre 1 e N. 


### Output
O seu programa deverá escrever no output a seguinte informação:

• Caso não seja possível construir a rede, o output deve consistir de uma única linha com a
palavra Insuficiente.

• Caso seja possível construir a rede, o output deve consistir de duas linhas com a seguinte
informação:

– Uma linha com o custo total.

– Uma linha com dois inteiros (separados por um espaço) indicando o número de aeroportos e o número de estradas a construir.
Todas as linhas do output terminam com o caracter de fim de linha.



### Exemplos 
#### input 1
4

3

1 1

2 5

3 1

4

1 2 1

1 3 6

2 4 2

3 4 3

2

#### output 1
5 

2 2



#### input 2
4

3

1 1

2 5

3 1

2 

1 2 1 

1 3 6

#### output 2
Insuficiente



#### input 3
4

4

1 1 

2 5

3 2

4 

1 0 

2 

1 2 1 

1 3 6

#### output 3
14 

3 1



#### input 4
4 

3

1 1

3

2 5

3 1

4

1 2 1

1 3 6

2 4 2

3 4 2

#### output 4
5 

0 3



#### input 5
4

0

4

1 2 1

2 3 2 

3 4 1

4 1 1

#### output 5
3

0 3
