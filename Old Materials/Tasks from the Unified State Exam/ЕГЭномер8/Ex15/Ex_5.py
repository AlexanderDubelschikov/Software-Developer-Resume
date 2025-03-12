for A in range(1, 100000):
    OK = True
    for x in range(1, 100000):
        if ((((x&13 != 0) or (x&A == 0)) <= (x&13 != 0)) or (x&A!=0) or (x&39==0))==0:
            OK = False
            break
    if OK == True:
        print(A)
        break