# Implementação principal
# Para a busca em largura foram utilizados como referência:
# O livro Algoritmos de Thomas Cormen
# O site https://favtutor.com/blogs/breadth-first-search-python

from estruturas.lista import ListaEncadeada
from estruturas.pilha import Pilha
import random
import copy
import time

class Estado:
    def __init__(self, pai=None):
        self.pai = pai
        self.pilhas = [Pilha(), Pilha(), Pilha()]
    
    def __str__(self) -> str:
        return str(self.pilhas)
    
    def __repr__(self) -> str:
        return str(self.pilhas)

    def __eq__(self, __o: object) -> bool:
        return self.pilhas == __o.pilhas

    def cria_estado_aleatorio(self):
        blocos = ["A", "B", "C"]
        while blocos:
            self.pilhas[random.randint(0, 2)].push(blocos.pop())

    def cria_estado_obj(self):
        blocos = ["A", "B", "C"]
        while blocos:
            self.pilhas[1].push(blocos.pop())

    # Retorna os vértices que podem ser gerados a partir do estado atual
    def expande(self):
        vertices = []
        for i in range(0, len(self.pilhas)):
            # Se a pilha atual estiver vazia, o loop vai direto para a próxima iteração
            if self.pilhas[i].contador == 0:
                continue
            else:
                # É feito uma cópia temporária do estado atual 
                temp1 = copy.deepcopy(self)
                # É retirado bloco do topo da pilha 
                bloco = temp1.pilhas[i].pop()
                for j in range(0, len(self.pilhas)):
                    # Se i for igual a j a pilha é a mesma da iteração do loop mais externo
                    if i != j:
                        # É feita uma nova copia agora com o bloco já retirado
                        temp2 = copy.deepcopy(temp1)
                        # Aponta o estado atual como pai
                        temp2.pai = self
                        # Adiciona o bloco retirado de temp1 para o estado filho(temp2)
                        temp2.pilhas[j].push(bloco)
                        # Anexa temp2 como um dos vertices filhos
                        vertices.append(temp2)
        return vertices

    # Retorna uma lista com o caminho para o resultado
    def caminho(self) -> list:
        caminho = []
        vertice = self
        # Enquanto vertice != de None
        while vertice:
            # Anexa o vértice na lista caminho
            caminho.append(vertice)
            # Atualiza para que o vertice aponte para seu pai
            vertice = vertice.pai
        return caminho[::-1]

def busca_largura(raiz, objetivo):
    vertices = []
    visitados = []
    nivel = 0
    vertices.append(raiz)
    visitados.append(raiz)

    # Enquanto houverem vértices a busca continua
    while vertices:
        vertice = vertices.pop()
        vizinhos = vertice.expande()
        # A cada expansão do vértice um nível é aumentado
        nivel = nivel + 1
        for vizinho in vizinhos:
            if vizinho == objetivo:
                print("Resultado encontrado no nível " + str(nivel) + " da árvore!")
                return vizinho
            # Se o vizinho já foi visitado, ele não é adicionado a lista de adjascência
            elif vizinho not in visitados:
                visitados.append(vizinho)
                vertices.append(vizinho)

if __name__ == "__main__":
    estado_ini = Estado()
    estado_obj = Estado()

    estado_ini.cria_estado_aleatorio()
    estado_obj.cria_estado_obj()

    print("Estado inicial: " + str(estado_ini))
    print("Estado objetivo:" + str(estado_obj))
    
    inicio = time.time()
    resultado = busca_largura(estado_ini, estado_obj)
    fim = time.time()

    print("Resultado: " + str(resultado.caminho()))
    print("Tempo total: " + str(fim - inicio))