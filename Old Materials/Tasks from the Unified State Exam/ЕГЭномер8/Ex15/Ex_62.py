for A in range(1, 2000):
    OK = True
    for x in range(1, 10000):
        if (((x%175==0)<=(x%25!=0))or(2*x+A>=1780))==0:
            OK = False
    if OK == True:
        print(A)
        break
