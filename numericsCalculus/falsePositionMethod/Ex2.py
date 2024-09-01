import numpy as np
import matplotlib.pyplot as plt

def f(x):
    return x**2 - 8*x

def encontrar_raizes():
    a = 1 
    b = -8  
    c = 0 

    discriminante = b**2 - 4*a*c
    raiz1 = (-b + np.sqrt(discriminante)) / (2*a)
    raiz2 = (-b - np.sqrt(discriminante)) / (2*a)
    
    return raiz1, raiz2

def grafico_com_retas_parciais(a, b):
    vetor_x = np.linspace(a-2, b+2, 100)
    vetor_y = f(vetor_x)
    plt.plot(vetor_x, vetor_y, color='red', label='Função $x^2 - 8x$')
    
    raizes = encontrar_raizes()
    x_atual = a
    iteracoes = 10 

    for i in range(iteracoes):
        y_atual = f(x_atual)
        plt.plot(x_atual, y_atual, 'bo')
        plt.plot([x_atual, raizes[0]], [y_atual, 0], 'g--', label='Iteração {}'.format(i+1))
        plt.pause(0.5)
        x_atual += (raizes[0] - a) / iteracoes  

    plt.plot(raizes, [0, 0], 'bo', label='Raízes')

    plt.axis([a-1, b+1, f(a)-10, f(b)+10])
    plt.title(r"Função $x^2 - 8x$ com Retas Parciais em [{},{}]".format(a, b))
    plt.xlabel("Eixo x")
    plt.ylabel("Eixo y")
    plt.grid()
    plt.legend()
    plt.show()

a = 5
b = 12
grafico_com_retas_parciais(a, b)

raizes = encontrar_raizes()
print("As raízes da equação são:", raizes)