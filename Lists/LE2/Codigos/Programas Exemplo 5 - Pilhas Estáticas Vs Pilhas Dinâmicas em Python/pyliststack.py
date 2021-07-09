# Livro: Data Structures and Algorithms Using Python. Rance Necaise. 2011.
# pyliststack.py - 
# Implementa uma TAD pilha usando uma list Python.


class Stack :
    # Cria uma pilha vazia.
    def __init__( self ):
       self._elementos = list()


    # Retorna verdadeiro se a pilha esta vazia ou false caso contrário.
    def estaVazia( self ):
       return len( self ) == 0


    # Retorna o número de elementos na pilha.
    def __len__( self ):
       return len( self._elementos )


    # Retorna o elemento no topo da pilha sem removê-lo.
    def peek( self ):
       assert not self.estaVazia(), "Não pode recuperar de uma pilha vazia"
       return self._elementos[-1]   # Acessa o último elemento.


    # Remove e retorna o elemento no topo da pilha.
    def pop( self ):
       assert not self.estaVazia(), "Não pode remover de uma pilha vazia"
       return self._elementos.pop()


    # Insere o item no topo da pilha.
    def push( self, elemento ):
       self._elementos.append( elemento )