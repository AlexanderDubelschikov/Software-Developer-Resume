for A in range(1, 2000):
    OK = True
    for x in range(1, 10000):
        if (((x % 3 == 0) <= (x % 5 != 0)) or (x + A >= 70)) == 0:
            OK = False
    if OK == True:
        print(A)
        break
