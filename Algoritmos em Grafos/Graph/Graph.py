"""
Author: Daniel Flavio Volski Daum
Date: 18/09/2022

This module was created to store representations and algorithms seen
during the "Algoritmos em Grafos" classes with professor Mauro Henrique
Mulati. All the algorithms and representations are based on the
implementetions presented in the part VI from the book Algorithms, by
Thomas Cormen. 
"""
from enum import Enum
from math import inf

class NodeState(Enum):
    """
    Represents the actual state of a node related to the search algorithm
    """
    UNKNOWN = "UNKNOWN"
    DISCOVERED = "DISCOVERED"
    FINISHED = "FINISHED"

    def __str__(self) -> str:
        return f'{self.value}'

class Node:
    """
    Represents a node (or vertice from a graph). It includes some basic
    algorithms related to it
    ...

    Attributes
    ---------
    name : str
        A simple tag to differentiate a node from the others
    distance : int
        The distance between a u node to this actual instance
    parent : Node
        Indicates an node that is precede of the actual one
    state : NodeState 
        It represents the actual state of a node in according to a
        search algorithm
    adj : []
        A list of the nodes that are adjacents to the actual one

    Methods
    -------
    add_adj_node(node) -> None
        Add a node to the adjacence list of the actual node   
    """
    
    def __init__(self, name: str) -> None:
        self.name = name
        self.distance = inf
        self.parent = None
        self.state = NodeState.UNKNOWN
        self.adj = []
    
    def __repr__(self) -> str:
        return f'Node("{self.name}", {self.distance}, {self.parent}, "{self.state}")'

    def __str__(self) -> str:
        return f'{self.name}'
    
    def __eq__(self, __o: object) -> bool:
        if isinstance(__o, Node):
            return self.name == __o.name
        return False
    
    def add_adj_node(self, node: 'Node') -> None:
        self.adj.append(node)

class Edge:
    """
    Represents an edge of a graph
    ...

    Attributes
    ---------
    u : Node
        The node where the edge start
    v : Node
        The node where the edge finishes
    w : int
        The weight of the edge

    Methods
    -------

    """

    def __init__(self, u: Node, v: Node, w = 1.0) -> None:
        self.u = u
        self.v = v
        self.w = w
    
    def __repr__(self) -> str:
        return f'Edge({str(self.u)}, {str(self.v)}, {self.w})'
    
    def __str__(self) -> str:
        return f'({str(self.u)}, {str(self.v)}, {self.w})'
    
class Graph:
    def __init__(self, max_nodes = 1, directioned = False) -> None:
        self.max_nodes = max_nodes
        self.directioned = directioned

class AdjListGraph(Graph):
    def __init__(self, max_nodes = 1, directioned = False) -> None:
        super().__init__(max_nodes = 1, directioned = False)
        self.nodes = []
        self.edges = []
        for i in range(0, max_nodes):
            self.nodes.append(Node(i))

    def add_edge(self, u: Node, v: Node, w = 1.0) -> None:
        if len(self.nodes) > (u - 1) or len(self.nodes) > (v - 1):
            raise IndexError("u or v are not graph vertices")
        else:
            self.edges.append(Edge(u, v, w))

    #Search algorithms
    def dfs(self, source):
        pass

    def bfs(self, source):
        pass

    #Single source shorthest path
    def bellman_ford(self, source):
        pass

    def dijkstra(self, source):
        pass

class AdjMatrixGraph(Graph):
    def __init__(self, max_nodes = 1, directioned = False) -> None:
        super().__init__(max_nodes, directioned)
        self.matrix = [[None for j in range(max_nodes)] for i in range(max_nodes)]
    
    def add_edge(self, u, v, w = 1):
        if (u - 1) > self.max_nodes or (v - 1) > self.max_nodes:
            raise IndexError("u or v are not graph vertices")
        else:
            self.matrix[u - 1][v - 1] = w
            if not self.directioned:
                self.matrix[v - 1][u - 1] = w

    #Search algorithms
    def dfs(self, source):
        pass

    def bfs(self, source):
        pass
    
    #All pair shortest paths
    def floyd_warshall(self):
        pass