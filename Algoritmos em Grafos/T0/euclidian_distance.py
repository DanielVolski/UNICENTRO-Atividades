# T0 - Euclidian Distance
import math

if __name__ == "__main__":
    #point = (x, y)
    p1 = str(input()).split()
    p2 = str(input()).split()

    distance = math.sqrt(pow(float(p2[0]) - float(p1[0]), 2) + pow(float(p2[1]) - float(p1[1]), 2))

    print("%.4f" % distance)