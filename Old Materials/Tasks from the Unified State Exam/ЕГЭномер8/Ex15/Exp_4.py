for A in range(-100, 100):
    OK = True
    for x in range(1, 100):
        for y in range(1, 100):
            if ((y+2*x != 99) or (y > A) or (x > A)) == 0:
                OK = False
    if OK == True:
        print(A)