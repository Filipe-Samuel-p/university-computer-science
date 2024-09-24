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




## Heap e HeapSort

É uma árvore binária ordenada, podendo esta árvore ser completa ou quase completa  (os nós folhas precisam estar no último nível ou no penúltimo nível).

    1- Max-Heap -> Os nós pais são sempre maiores ou iguais que os nós filhos.
    2- Reheap Up -> É a reconstrução do HeapMax. Em alguns casos, a prioridade do max-heap não estará sendo satisfeita. Com isso, o Reheap Up remove o elemento errado e insere ele na sua posição correta, restabelecendo o max-heap de novo. OBS: a comparação entre os elementos é feita de baixo para cima.
    3- (Heapfy) Reheap Down -> Recontrução para baixo. Segue a mesma lógica do Reheap Up, mas a idéia é reconstruir o Heap após remover a raíz e substituir pelo último elementda raíz.
    3- Min-Heap -> o inverso do max-heap

O Heap geralmente é implementado em um array, a montagem (de array para árvore) deve ser feita da esquerda para a direita, logo, em um heapMax, o array inicial é invertido, para que assim, os maiores valores sejam os primeiros inseridos na árvore.

### Montagem do Heap em um vetor

    i -> posição(índice) de um nó qualquer
    2i + 1 -> posição do filho esquerdo
    2i + 2 -> posição do filho direito
    [(i - 1/2)] -> posição (indice) do pai de um nó em um índice i.

### Heap Sort

 Serve para ordenar um array, por exemplo, usando o conceito de Heap. É mais agrdável pois o maior elemento ja esta na raiz da árvore. 

 passo a passo: 
    
    1- Construir um max-heap. Para isso, vamos inserir elementos no vetor. Para respeitar as condições de um max-heap, usar-se o reheap up, pois precisamos garantir que os elementos estejam na posição certa.
    
    2- Mover a raíz para o final e implementa o reheap Down para manter a propriedade de max-heap.

    3- Reduzir o tamanho do heap, isso é feito após a troca da raiz pelo ultimo elemento do array.

    4- Reajustar o Heap com reheap Down

    5- repetir o processo.