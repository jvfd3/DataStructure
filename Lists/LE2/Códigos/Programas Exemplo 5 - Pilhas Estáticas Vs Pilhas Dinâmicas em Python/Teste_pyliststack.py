# Livro: Data Structures and Algorithms Using Python. Rance Necaise. 2011.
# pyliststack.py - 
# Implementa uma TAD pilha usando uma list Python.


from pyliststack import Stack


PROMPT = "Ingresse um valor inteiro (<0 para finalizar): "
mPilha = Stack()
valor = int(input( PROMPT ))
while valor >=0 :
    mPilha.push( valor )
    valor = int(input( PROMPT ))


while not mPilha.estaVazia() :
    valor = mPilha.pop()
    print( valor )