# Lista de Exercício 1

Deixamos aqui a teoria por tras dos exercícios.

## Ordenação

### ShellSort

1- Motivação: O algoritmo insertion sort tem um ponto fraco que é -> Dependendo 
do valor da chave, a posição de inserção pode ficar muito distante da posição atual do elemento
resultando em uma grande quantidade de deslocamento. 

2- A idéia do shellSort é aproximar  o local de inserção da posição atual
do elemento. Como isso é feito? Dividindo a lista em sublistas (gaps) onde os elementos
ficarão relativamente mais perto das posições de inserção adequadas. Assim, o algoritmo insertion sort
irá percorrer o vetor ja quase ordenado, fazendo com que sua enficiência seja de O(n). 



