import copy

class Graph:
    def __init__(self, qt_nodes: int):
        self.adj_list = {}
        for i in range(0, qt_nodes):
            self.adj_list[i] = []

    """
    Adds an edge to an undirected graph
    """
    def add_edge(self, u: int, v: int):
        if u < len(self.adj_list):
            self.adj_list[u].append(v)
            self.adj_list[v].append(u)

    """
    Returns the degree of a single node
    """
    def get_degree(self, u) -> int:
        return len(self.adj_list[u])

    """
    Returns a list of the nodes in decrescent order of degree
    """    
    def list_ordered_degree(self) -> list:
        degrees = [(l, len(self.adj_list[l])) for l in self.adj_list]
        return sorted(degrees, key=lambda x: x[1], reverse=True)
    
    """
    Returns a new list wit all the sets that aren't null
    """
    def get_not_null_set(st):
        not_null_sets = []
        for lst in st:
            if len(lst) > 0:
                not_null_sets.append(lst)
        return not_null_sets
    
    """
    Returs the minimum amount of colors needed to color the graph
    """
    def welsh_powell(self) -> tuple:
        vertices = self.list_calculate_degree(graph)
    
        colors = [[] for _ in range(len(graph))]

        for v in vertices:
            for color_set in colors:
                available = True
                for adj in graph[v[0]]:
                    if adj in color_set:
                        available = False
                        break
                if available:
                    color_set.append(v[0])
                    break
        return len(self.get_not_null_set(colors))   

graph = Graph(4)
graph.add_edge(0, 1)
graph.add_edge(1, 2)
graph.add_edge(1, 3)

print(graph.welsh_powell())