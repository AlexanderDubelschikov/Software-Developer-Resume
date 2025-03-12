for A in range(1, 10000):
    OK = True
    for x in range(1, 1000):
        if (((x%A == 0) and (x%50 != 0)) <= ((x%18!=0)or(x%50==0)))==0:
            OK = False
    if OK == True:
         print(A)
         break