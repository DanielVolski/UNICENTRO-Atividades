from scipy.optimize import differential_evolution as de
from scipy.optimize import NonlinearConstraint as nc
from math import sin
import numpy as np
import time
import threading

files = [
    "Caso_13geradores_econ_ponto_valvula.txt",
    "Caso_13geradores_econ_ponto_valvula2.txt",
    "Caso_40geradores_econ_ponto_valvula.txt"
]
generators = 0
demanded_potency = 0
bound = 0
p_min = []
p_max = []
a = []
b = [] 
c = []
d = []
e = []
f = []
bounds = []
results = []

def obj_func(p):
    summation = 0
    for i in range(0, len(p)):
        summation += a[i] * p[i] ** 2 + b[i] * p[i] + c[i] + abs(d[i] * sin(e[i] *(p_min[i] - p_max[i])))
    return summation

def potency(p):
    summation = 0
    for i in range(0, len(p)):
        summation += p[i]
    return summation

file = open(files[2], 'r')

with file as opened_file:
    try:
        number_of_generators = int(opened_file.readline())
        demanded_potency = int(opened_file.readline())
        for _ in range(0, number_of_generators):
            p_min.append(float(opened_file.readline()))
        for _ in range(0, number_of_generators):
            p_max.append(float(opened_file.readline()))
        for _ in range(0, number_of_generators):
            a.append(float(opened_file.readline()))
        for _ in range(0, number_of_generators):
            b.append(float(opened_file.readline()))
        for _ in range(0, number_of_generators):
            c.append(float(opened_file.readline()))
        for _ in range(0, number_of_generators):
            d.append(float(opened_file.readline()))
        for _ in range(0, number_of_generators):
            e.append(float(opened_file.readline()))
        for i in range(0, number_of_generators):
            bounds.append((p_min[i], p_max[i]))
    finally:
        opened_file.close()

bound = nc(potency, demanded_potency, np.inf)

start = time.time()
results.append(de(obj_func, bounds, strategy="best1bin", maxiter=1000, popsize=50, mutation=(0.5, 1.0), recombination=0.7, init="latinhypercube", constraints = (bound)))
best1bin_time = time.time() - start

start = time.time()
results.append(de(obj_func, bounds, strategy="best1exp", maxiter=1000, popsize=40, mutation=(0.5, 1.0), recombination=0.7, init="latinhypercube", constraints = (bound)))
best1exp_time = time.time() - start

start = time.time()
results.append(de(obj_func, bounds, strategy="rand1exp", maxiter=1000, popsize=40, mutation=(0.5, 1.0), recombination=0.7, init="latinhypercube", constraints = (bound)))
rand1exp_time = time.time() - start

start = time.time()
results.append(de(obj_func, bounds, strategy="currenttobest1exp", maxiter=1000, popsize=40, mutation=(0.5, 1.0), recombination=0.7, init="latinhypercube", constraints = (bound)))
currenttobest1exp_time = time.time() - start

start = time.time()
results.append(de(obj_func, bounds, strategy="best2bin", maxiter=1000, popsize=40, mutation=(0.5, 1.0), recombination=0.7, init="latinhypercube", constraints = (bound)))
best2bin_time = time.time() - start

print(f"Resultado best1bin - Tempo: {best1bin_time}\n{results[0]}\n")
print(f"Resultado best1exp - Tempo: {best1exp_time}\n{results[1]}\n")
print(f"Resultado rand1exp - Tempo: {rand1exp_time}\n{results[2]}\n")
print(f"Resultado currenttobest1exp - Tempo: {currenttobest1exp_time}\n{results[3]}\n")
print(f"Resultado best2bin - Tempo: {best2bin_time}\n{results[4]}\n")