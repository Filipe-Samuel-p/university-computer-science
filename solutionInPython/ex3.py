

def isPalindrome(x: int) -> bool:
        string = str(x)
        value = True if string == string[::-1] else False
        
        return value


def main()->None:
    number = int(input("Entre com o numero: "))
    print(isPalindrome(number))

main()