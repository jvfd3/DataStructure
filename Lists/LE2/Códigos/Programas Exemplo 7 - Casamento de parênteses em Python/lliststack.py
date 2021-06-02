# Livro: Data Structures and Algorithms Using Python. Rance Necaise. 2011.
# lliststack.py - 
# Implementa uma TAD pilha usando uma list Python.


class Stack :
    # Cria uma pilha vazia.
    def __init__( self ) :
       self._topo = None
       self._tam = 0


    # Retorna verdadeiro se a pilha esta vazia ou false caso contrário.
    def estaVazia( self ) :
       return self._topo is None


    # Retorna o número de elementos na pilha.
    def __len__( self ) :
       return self._tam


    # Retorna o elemento no topo da pilha sem removê-lo.
    def peek( self ) :
       assert not self.estaVazia(), "Não pode acessar o topo de uma pilha vazia"
       return self._topo.elem


    # Remove e retorna o elemento no topo da pilha.
    def pop( self ) :
       assert not self.estaVazia(), "Não pode remover de uma pilha vazia"
       no = self._topo
       self._topo = self._topo.prox
       self._tam -= 1
       return no.elem


    # Insere o item no topo da pilha.
    def push( self, elem ) :
       self._topo = _NoPilha( elem, self._topo)
       self._tam += 1


class _NoPilha :
    def __init__( self, elem, link ) :
       self.elem = elem
       self.prox = link