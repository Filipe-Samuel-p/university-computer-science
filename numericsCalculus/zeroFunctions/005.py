import math
import numpy as np
import matplotlib.pyplot as plt

a = -2
b = 2

error = 0.01


def f(x):
    return np.exp(x) - 2

xp = np.linspace(a,b,100)
yp = f(xp)

plt.plot(xp,yp,color = "red")
plt.title("Funcao np.exp(x) - 2 no intervalo [-4,4]")
plt.xlabel("eixo x")
plt.ylabel("eixo y")
plt.grid()

plt.show()

if f(a) * f(b) < 0:
    while math.fabs((b-a)/2) > error:
        m = (a+b)/2
        if(f(m)) == 0:
            print(f"a raiz e {m}")
            break
        else:
            if f(a) * f(m) < 0:
                b = m
            else:
                a = m
                print("O valor aproximado é: ", m)
else:
    print('Não existe raíz real!') 
