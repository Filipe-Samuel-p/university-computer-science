from random import randint

    
def selection_sort(vet, tamanho: int):
    x = 0
    while x < tamanho:
       menor_idx = x 
       inicio = x + 1
       for i in range(inicio,tamanho):
           if vet[menor_idx] > vet[inicio]:
               menor_idx = inicio

       if x != menor_idx:
           aux = vet[x]
           vet[x] = vet[menor_idx]
           vet[menor_idx] = aux
       x += 1


tamanho_vet = int(input("Digite o tamanho do vetor: "))
vetor = [randint(0,100) for x in range(tamanho_vet)] #criando vet aleatorio

print("******* VETOR ALEATÓRIO ********\n")
print(vetor, "\n")
selection_sort(vetor,tamanho_vet)
print("******* VETOR ORDENADO ********\n")
print(vetor)