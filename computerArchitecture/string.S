.data
str1: .string "teste de string" #define uma string chamada str1 com o conteudo "teste de string"
str2: .space 20    #aloca 20 bytes de memoria para a string str2 
str3: .string "Hello World" #define uma string chamada str3 com o conteudo "hello world"

.text
   li a0, 4 #configura o codifo chamada do sistema para imprimir uma string
   la a1, str1 # carrega p endereco da string str1 no registrador a1
   ecall 

   li a0,11  #configura p cpdofp da chamada do sistema para imprimir um caractere 
   li a1, 13  # define o valor ASCII para o caractere de nova linha
   ecall   #chama o servico do sistema para imprimir o caractere de nova linha

   #segunda string

   la s0,str2 #carrega o endereco da string str2 no registrador
   li s1, 20 # inicializa o contador para 20(numero de bytes a serem...)
   li s3, 65  #Define o valor ASCII "A" (65) para preencher a string

   do_while:
     sb s3, 0(s0)  #armazena o valor de s3 no byte atual de str2 
     addi s0, s0,1 #Avanca para o proximo byte
     addi s1, s1, -1 #decrementa o contador
   bne s1,zero, do_while #repete o loop ate que o contador seja zero
    
    li a0,4
    la a1,str2
    ecall
    
fim:
   li a0,10
   ecall
   ret