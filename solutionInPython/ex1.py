

def main()->None:
    count: int = 0
    number = int(input("Entre com o número de linhas: "))
    for index1 in range(1,number + 1):
        print("\n")
        for index2 in range(index1):
            count += 1
            print(f"{count}", end="\t")
main()