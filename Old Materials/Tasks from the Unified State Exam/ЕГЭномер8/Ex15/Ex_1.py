for A in range(1, 1000):
    OK = True
    for x in range(1, 1000):
        if ((x&102 != 0) <= ((x&36 == 0) <= (x&A != 0))) == 0:
            OK = False
            break
    if OK == True:
        print(A)
        break