#14/05/2024
.data
numeros: .word 5, 8, 3, 12, 7 #exemplo de sequencia de numeros

.text
main:
    la t0, numeros #carrega o endereço da sequencia
    lw t1, 0(t0)   #carrega o primeiro numero numero
    lw t2, 4(t0)   #carrega o segundo numero

    bge t1, t2, skip   #pula se o prmieiro numero for maior ou igual ao segundo
    mv t1, t2          #caso contrario, atualiza o maior numero

    skip:
        lw t2, 8(t0)     # carrega o terceiro numero
        bge t1, t2, skip2 # pula se o maior numero for igual ou maior ao terceiro
        mv t1, t2        # caso contrairio, atualiza o maior numero

    skip2:
        lw t2, 12(t0)     # carrega o quarto numero
        bge t1, t2, skip3 # pula se o maior numero for igual ou maior ao quarto
        mv t1, t2        # caso contrairio, atualiza o maior numero

    skip3:
        lw t2, 16(t0)     # carrega o quinto numero
        bge t1, t2, Imprimir  # pula se o maior numero for igual ou maior ao quinto
        mv t1, t2        # caso contrairio, atualiza o maior numero

    Imprimir:
        addi a0, x0, 1      #argumento para o ecall executar
        addi a1, t1, 0      #argumento para ecall, o valor a ser
        ecall               #imprime o ecall inteiro
    
        li a0, 11 # 0 11 quebra a linha
        li a1, 13 #puxa o \n da tabela ascii e quebra linha
        ecall #imprime uma quebra linha

    fim:
        li a0, 10
        ecall       #encerra o programa
        ret