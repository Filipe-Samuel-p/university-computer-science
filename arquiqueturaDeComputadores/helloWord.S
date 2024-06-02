.data
     str: .string: .asciiz "Hello, world\n"

.text
    #a0 e a1 sao registradores 
    li a0,4 #l1 guarda o valor e o 4 é o comando para printar
    la a1, str # la le o endereço
    ecall # recebe linhas anteriores

    li a0, 11 # 0 11 quebra a linha
    li a1, 13 #puxa o \n da tabela ascii e quebra linha
    ecall #imprime uma quebra linha


    li a0,10 #10 encerra o programa
    ecall 
    ret #retorna a funcao que o chamou 