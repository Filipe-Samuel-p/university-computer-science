.data
numeros: .word 30, 8, 3, 12, 25 #exemplo de sequencia de numeros

.text
main:
    la t0, numeros  #carrega o endereco da sequencia
    lw t1, 0(t0)    # carrega o primeiro numero(inicalmente o maior numero)
    li t3, 20     # define o tamanho da sequencia (5 numeros)

loop:
    addi t0, t0, 4  #avanca para proximo numero na sequencia
    lw t2, 0(t0) # carrega o proximo numero

    bge t1, t2, skip #pula ser o maior numero for maior ou igual ao proximo numero
    mv t1,t2   #caso contrario, atualiza o maior numero

skip:
    addi t3, t3, -1 # decrementa o contador de interacoes
    bnez t3, loop

imprime:
    addi a0,x0,1
    addi a1, t1,0
    ecall

fim:
    li a0, 10  
    ecall
