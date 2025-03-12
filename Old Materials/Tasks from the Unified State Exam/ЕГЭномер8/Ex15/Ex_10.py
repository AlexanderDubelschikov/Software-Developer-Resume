for A in range(1, 100000):
    OK = True
    for x in range(1, 100000):
        if ((x&A!=0)<=(((x&17==0)and(x&5==0))<=(x&3!=0)))==0:
            OK = False
            break
    if OK == True:
        print(A)
