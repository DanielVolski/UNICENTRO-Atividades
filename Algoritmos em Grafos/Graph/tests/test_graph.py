import sys, os, unittest

#This is to aceess parent directory and import Graph.py module
current = os.path.dirname(os.path.realpath(__file__))
parent = os.path.dirname(current)
sys.path.append(parent)

from Graph import *

if __name__ == '__main__':
    graph = AdjMatrixGraph(3, True)
    graph.add_edge(1, 2, 22)

    for i in range(0, 3):
        print(graph.matrix[i])