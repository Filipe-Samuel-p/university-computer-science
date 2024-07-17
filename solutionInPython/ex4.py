

def romanToInt(s: str) -> int:
       valueSymbols = {
        "I": 1,
        "V": 5,
        "X": 10,
        "L": 50,
        "C": 100,
        "D": 500,
        "M": 1000
       } 
       result = 0
       for index in range (len(s)): 
            if index < len(s) - 1 and valueSymbols[s[index]] < valueSymbols[s[index+1]]:
                result -= valueSymbols[s[index]]
            else:
                result += valueSymbols[s[index]]
       return result

def main()->None:
     roman = input("Entre com o número romano: ")
     intNumber = romanToInt(roman)
     print(f"O número romano {roman} represneta o valor {intNumber} em inteiro")


main()