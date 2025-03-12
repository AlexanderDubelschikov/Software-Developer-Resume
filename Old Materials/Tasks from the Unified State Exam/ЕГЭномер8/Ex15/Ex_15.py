for A in range(1, 100000):
    OK = True
    for x in range(1, 100000):
        if ((x&A!=0)and(x&58==0)and(x&22==0))==1:
            OK = False
            break
    if OK == True:
        print(A)