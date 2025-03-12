for A in range(1, 10000):
    OK = True
    for x in range(1, 10000):
        if ((x & A != 0) <= ((x & 56 == 0) <= (x & 20 != 0))) == 0:
            OK = False
            break
    if OK == True:
        print(A)

