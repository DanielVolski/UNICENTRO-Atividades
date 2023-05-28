def calculate_degree(graph):
    degrees = []
    for v in graph:
        degrees.append((v, len(graph[v])))
    return sorted(degrees, key=lambda x: x[1], reverse=True)

def get_not_null_set(st):
    not_null_sets = []
    for lst in st:
        if len(lst) > 0:
            not_null_sets.append(lst)
    return not_null_sets

def welsh_powell(graph):
    vertices = calculate_degree(graph)
    
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
    return len(get_not_null_set(colors))

graph = {
    0: [1],
    1: [2, 3],
    2: [1, 3],
    3: [1, 2]
}

print(welsh_powell(graph))