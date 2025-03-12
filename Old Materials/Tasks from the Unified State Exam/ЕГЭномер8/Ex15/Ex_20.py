for A in range(1, 10000):
    OK = True
    for x in range(1, 1000):
        if ((x%18 == 0) <= ((x%54 == 0) <= (x%A == 0))) == 0:
            OK = False
    if OK == True:
         print(A)