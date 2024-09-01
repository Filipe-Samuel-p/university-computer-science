import numpy as np
import matplotlib.pyplot as plt

def f(x):
    return x**2 - 8*x

def grafico(a, b):
    vetor_x = np.linspace(a-2, b+2, 100)
    vetor_y = f(vetor_x)
    plt.plot(vetor_x, vetor_y, color='red')
    xline, yline = [a, b], [f(a), f(b)]
    plt.plot(xline, yline, marker='o')

    plt.axis([a-1, b+1, f(a)-10, f(b)+10])
    plt.title(r"função $3 \ x^2 - $8x em [5,12]")
    plt.xlabel("eixo x")
    plt.ylabel("eixo y")
    plt.grid()
    plt.show()

a = 5
b = 12
grafico(a,b)