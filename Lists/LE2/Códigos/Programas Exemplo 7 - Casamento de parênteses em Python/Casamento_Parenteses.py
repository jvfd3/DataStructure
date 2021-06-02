# Livro: Data Structures and Algorithms Using Python. Rance Necaise. 2011.
# casamento_parenteses.py - 
# Verifica o balanceamento de parenteses (, { e [ usando uma pilha em Python.


from lliststack import Stack


# Nome do Arquivo a abrir
FILE_NAME = "no-errors.txt"


def main() :
    arquivo = open( FILE_NAME, "r" )
    if isValidSource(arquivo) :
       print("O arquivo tem casamento de parenteses ok!")
    else:   
       print("O arquivo tem um erro no casamento de parenteses!!")
    arquivo.close() 


def isValidSource( srcfile ):
    s = Stack()
    for line in srcfile  :
       for token in line :
           if token in "{[(" :
              s.push( token )
           elif token in "}])" :
              if s.estaVazia():
                 return False
              else :
                 left = s.pop()
                 if (token == "}" and left != "{") or \
                    (token == "]" and left != "[") or \
                    (token == ")" and left != "(") :
                     return False
    return s.estaVazia()


# Executa a rotina principal
main()