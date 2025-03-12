for A in range(-100, 100):
    OK = True
    for x in range(1, 100):
        for y in range(1, 100):
            if ((y+3*x < A) or (2*y+x > 50) or (4*y-x < 40)) == 0:
                OK = False
    if OK == True:
        print(A)
        break