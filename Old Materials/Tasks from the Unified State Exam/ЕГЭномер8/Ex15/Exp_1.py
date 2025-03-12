for A in range(1, 3000):
    OK = True
    for x in range(1, 1000):
        if ((x%A != 0) <= ((x%21 != 0) and (x%35 != 0))) == 0:
            OK = False
    if OK == True:
         print(A)