# Trabalho sobre Evolução Diferencial

## Enunciado do trabalho

Implementar diferentes versões/configurações de Evolução Diferencial para resolver o problema do Despacho Econômico de Energia Elétrica.

Definição do problema:

Minimizar FC = Somatório_i(FC_i(P_i))

Sujeito a Somatório_i(P_i) - P_D = 0 e P^min_i <= P_i <= P^max_i

FC_i(P_i) = a_i * P_i ** 2 + b_i * P_i + c_i + |e_i * seno(f_i * (P^min_i - P_i))|

Onde FC é a função de custo a ser minimizada, P_D é a potência total demandada, P^min_i e P^max_i são os limites inferiores e superiores da potência gerada por cada gerador, FC_i é o custo decorrente do i-ésimo gerador e a_i, b_i, c_i, e_i e f_i são parâmetros da função de custo.

A Evolução Diferencial deve encontrar os valores de P_i.

No trabalho o objetivo é entender o funcionamento/comportamento do algoritmo ao resolver o problema, portanto, o importante é analisar os efeitos dos diferentes parâmetros do algoritmo.

Formato dos arquivos:

Primeira linha é a quantidade de geradores (n) e a segunda linha é a potência demandada. As próximas linhas (em blocos de n linhas) correspondem aos P^min, P^max, a, b, c, e, f.
