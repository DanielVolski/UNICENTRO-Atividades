def calculate_degree(graph):
    degrees = [(l, len(graph[l])) for l in graph]
    return sorted(degrees, key=lambda x: x[1], reverse=True)

def is_available(v, color_set):
        return all(adj not in color_set for adj in graph[v])
   
def welsh_powell(graph):
    vertices = calculate_degree(graph)

    colors = [[] for _ in range(len(graph))]

    for v in vertices:
        available_sets = filter(lambda s: is_available(v[0], s), colors)
        first_set = next(available_sets, None)
        if first_set is not None:
            first_set.append(v[0])

    return len(list(filter(lambda s: len(s) > 0, colors)))

graph = {
    0: [1],
    1: [2, 3],
    2: [1, 3],
    3: [1, 2]
}

print(welsh_powell(graph))