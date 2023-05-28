#T0 - Even or Odd - 1066

if __name__ == "__main__":
    pos_numbers = neg_numbers = even_numbers = odd_numbers = 0
    numbers = []
    
    for i in range(0, 5):
        numbers.append(int(input()))
    
    for number in numbers:
        if number % 2 == 0:
            even_numbers += 1
        else:
            odd_numbers += 1
        if number > 0:
            pos_numbers += 1
        elif number != 0:
            neg_numbers += 1

    print("%d valor(es) par(es)\n%d valor(es) impar(es)" % (even_numbers, odd_numbers))
    print("%d valor(es) positivo(s)\n%d valor(es) negativo(s)" % (pos_numbers, neg_numbers)) 