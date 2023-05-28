#T0 - Quadratic formula
import math

if __name__ == "__main__":
    input_nums = str(input()).split()
    coefficients = {
        "A" : float(input_nums[0]), 
        "B" : float(input_nums[1]), 
        "C" : float(input_nums[2])
    }

    delta = pow(coefficients["B"], 2) - 4.0 * coefficients["A"] * coefficients["C"]

    if delta >= 0 and coefficients["A"] != 0:
        delta = math.sqrt(delta)
        dividend = (2 * coefficients["A"])
        r1 = (-coefficients["B"] + delta) / dividend
        r2 = (-coefficients["B"] - delta) / dividend
        print("R1 = %.5f\nR2 = %.5f" % (r1, r2))
    else:
        print("Impossivel calcular")