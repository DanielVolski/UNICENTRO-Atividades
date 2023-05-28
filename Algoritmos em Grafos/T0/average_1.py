# T0 - Average 1

def calc_average(num1, weight1, num2, weight2):
    return ((num1 * weight1) + (num2 * weight2)) / (weight1 + weight2)

if __name__ == "__main__":
    scoreA = float(input())
    scoreB = float(input())

    average = calc_average(scoreA, 3.5, scoreB, 7.5)

    print("MEDIA = %.5f" % average)