from estruturas.pilha import NodoPilha, Pilha

def test_construtor_nodoPilha(nodo_pilha):
    assert str(nodo_pilha) == "0 -> None", \
        "test_construtor_nodoPilha falhou"
    
def test_construtor_Pilha(pilha):
    assert str(pilha) == "[Topo: None]", \
        f"test_construtor_Pilha falhou, valor da pilha {pilha}"
    
def test_push(pilha):
    pilha.push(1)
    pilha.push(2)
    assert str(pilha) == "[Topo: 2 -> 1 -> None]", \
        f"test_push falhou, pilha: {pilha}"

def test_top(pilha):
    assert pilha.top() == 2, \
        f"test_top falhou, pilha: {pilha.top()}"

def test_pop(pilha):
    pilha.pop()
    assert str(pilha) == "[Topo: 1 -> None]", \
        f"test_pop falhou, pilha: {pilha}"

    pilha.pop()
    assert str(pilha) == "[Topo: None]", \
        f"test_pop falhou, pilha: {pilha}"

    pilha.pop()
    assert str(pilha) == "[Topo: None]", \
        f"test_pop falhou, pilha: {pilha}"

if __name__ == "__main__":
    nodo_pilha = NodoPilha()
    test_construtor_nodoPilha(nodo_pilha)

    pilha = Pilha()
    test_construtor_Pilha(pilha)
    test_push(pilha)

    test_top(pilha)

    #test_pop(pilha)
    print(pilha)