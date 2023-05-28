def calculate_coeficients(x, coeficients):
    calculated_coeficients = []
    for coeficient in coeficients:
        calculated_coeficients.append(coeficient*x**coeficients.index(coeficient))
    return calculated_coeficients

def calculate_polynomial(x, coeficients):
    calculated_coeficients = calculate_coeficients(x, coeficients)
    print(calculated_coeficients)
    return sum(calculated_coeficients)

print(calculate_polynomial(5, [22, 3, 6]))