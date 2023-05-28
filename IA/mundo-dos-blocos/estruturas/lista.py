# Implementação da estrutura de dados do tipo Lista
# Baseado na implementação disponível em:
# https://algoritmosempython.com.br/cursos/algoritmos-python/estruturas-dados/listas-encadeadas/
#
import copy

"""Representa um único nodo de uma lista encadeada"""
class NodoLista:
    """Construtor da classe NodoLista"""
    def __init__(self, dado=0, proximo_nodo=None):
        self.dado = dado
        self.proximo = proximo_nodo

    """Gera o imprimível de um objeto NodoLista"""
    def __repr__(self) -> str:
        return "%s" % (self.dado)

"""Representa uma lista encadeada"""
class ListaEncadeada:
    """Construtor da classe"""
    def __init__(self):
        self.cabeca = None

    """Imprime o cabeca da lista"""
    def __repr__(self) -> str:
        nodo = copy.deepcopy(self.cabeca)
        string = ""
        while nodo:
            string += str(nodo)
            nodo = nodo.proximo
        return string

    """Insere um novo dado ao final da lista"""
    def inserir(self, dado):
        novo = NodoLista(dado)
        novo.proximo = self.cabeca
        self.cabeca = novo
        
    def busca(lista, valor):
        atual = lista.cabeca
        while atual and atual.dado != valor:
            atual = atual.proximo
        return atual

    def remove(self, valor):
        assert self.cabeca, "Impossível remover valor de lista vazia."
        # Nodo a ser removido é a cabeça da lista.
        if self.cabeca.dado == valor:
             self.cabeca = self.cabeca.proximo
        else:
        # Encontra a posição do elemento a ser removido.
           anterior = None
           atual = self.cabeca
           while atual and atual.dado != valor:
                anterior = atual
                atual = atual.proximo
            # O nodo atual é o nodo a ser removido.
                if atual:
                    anterior.proximo = atual.proximo
                else:
            # O nodo atual é a cauda da lista.
                    anterior.proximo = None
