.data 
  str: .string: .asciiz "\n soma de 123 + 37= "

.text 
main: 
   # soma
  addi t0, zero, 123  # t0 = zero + 123
  addi t1, zero, 37  # t0 = zero + 37
  add t2, t1, t0   # t2 = t1 + t0
  
  #imprime a mensagem str
  li a0, 4
  la a1, str
  ecall
  
  #o valor esta t2
  addi a0,x0,1
  addi a1,t2,0
  ecall
   
  li a0, 11 # 0 11 quebra a linha
  li a1, 13 #puxa o \n da tabela ascii e quebra linha
  ecall #imprime uma quebra linha


fim:  
   li a0, 10 #encerra o programa 
   ecall
   ret
  
