import matplotlib.pyplot as plt
import numpy as np

#Uma clínica médica possui um único médico atendendo os pacientes.\ 
#Os pacientes chegam à clínica a uma taxa média de 8 pacientes por hora (λ = 8).
#O médico consegue atender, em média, 10 pacientes por hora (μ = 10).''' 


# Funções para calcular métricas
def taxaDeUtilizacao(lambda_, mu):
    return lambda_ / mu

def numeroMedioDeUsuariosNoSistema(lambda_, mu):
    return lambda_ / (mu - lambda_)

def numeroMedioNaFila(lambda_, mu):
    return (lambda_ ** 2) / (mu * (mu - lambda_))

def tempoGastoNoSistemaPorUsuario(lambda_, mu):
    return 1 / (mu - lambda_)

def tempoMedioDeEsperaNaFila(lambda_, mu):
    return lambda_ / (mu * (mu - lambda_))

print("-------- EXEMPLO DE APLICAÇAO --------\n\n")
print("Um banco possui um único atendente.\
Os clientes chegam ao banco a uma taxa média de 10 clientes por hora . O atendente\
 consegue atender, em média, 12 clientes por hora.\n\n")

lambda_ = int(input("Qual a taxa média de chegadas por hora? ") )
mu = int(input("Qual a taxa média de atendimento por hora? "))
print("\n\n")


rho = taxaDeUtilizacao(lambda_, mu)
L = numeroMedioDeUsuariosNoSistema(lambda_, mu)
Lq = numeroMedioNaFila(lambda_, mu)
W = tempoGastoNoSistemaPorUsuario(lambda_, mu)
Wq = tempoMedioDeEsperaNaFila(lambda_, mu)

print(f"Taxa de utilização (ρ): {rho:.2f}")
print(f"Número médio de clientes no sistema (L): {L:.2f}")
print(f"Número médio de clientes na fila (Lq): {Lq:.2f}")
print(f"Tempo médio no sistema (W): {W:.2f} horas")
print(f"Tempo médio na fila (Wq): {Wq:.2f} horas")
print("\n\n")


# Função para calcular a distribuição de probabilidade do número de clientes no sistema
def probDeQuantidadeDeUsu(lambda_, mu, n):
    rho = taxaDeUtilizacao(lambda_, mu)
    return (1 - rho) * rho**n

# Intervalo de valores de n (número de clientes no sistema)
n_values = np.arange(0, 31)  # Vamos considerar de 0 a 30 clientes
prob_values = [probDeQuantidadeDeUsu(lambda_, mu, n) for n in n_values] #probabilidade de ter de 0 a 20 usuarios de acordo com a taxa rho

verificacao = input("Deseja mostrar o gráfico? [s] ou [n] ")

if verificacao.lower() == "s":

    plt.figure(figsize=(10, 6))
    plt.bar(n_values, prob_values, color='skyblue')
    plt.xlabel('Número de Clientes no Sistema')
    plt.ylabel('Probabilidade')
    plt.title('Distribuição de Probabilidade do Número de Clientes no Sistema (M/M/1)')
    plt.grid(True)
    plt.show()


# a probabilidade vai abaixando, pois a taxa de atendimento é maior que a taxa de chegada. Logo
#com o tempo, a probabilidade de ficar mais pessoas na fila, é menor
