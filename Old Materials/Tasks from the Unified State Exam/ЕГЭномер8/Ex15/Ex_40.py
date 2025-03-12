for A in range(-500, 500):
    OK = True
    for x in range(0, 100):
        for y in range(0, 100):
            if ((2*y+5*x<A) or (x + y > 80))==0:
                OK = False
    if OK == True:
        print(A)
        break

