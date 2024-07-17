
import math

def deltA(a: int, b: int, c: int) -> float:
    return (b ** 2) - (4 * a * c)

def bhaskaraEquation (a: int, b: int, delta: float)->None:
    if delta > 0:
        x1 = (-b + math.sqrt(delta))/ 2 * a
        x2 = (-b - math.sqrt(delta))/ 2 * a
        return x1,x2
    elif delta == 0:
        return -b/2*a
    else:
        return 


def main()->None:

    a = int(input(f"Entre com o coeficiente da variavel de expoente {2} "))
    b = int(input(f"Entre com o coeficiente da variavel de expoente {1} "))
    c = int(input(f"Entre com o coeficiente da variavel de expoente {0} "))

    delta: float = deltA(a,b,c)
    print(f"As raizes: {bhaskaraEquation(a,b,delta)}")

main()