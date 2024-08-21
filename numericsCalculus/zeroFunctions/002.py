
import math
import numpy as np
import matplotlib.pyplot as plt

a = 1
b = 6

error = 0.01

def f(x):
    return x**2 - 5

xp = np.linspace(a,b,100)
yp = f(xp)

plt.plot(xp,yp,color = "red")
plt.title("Funcao x**2 - 5 no intervalo [1,6]")
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
