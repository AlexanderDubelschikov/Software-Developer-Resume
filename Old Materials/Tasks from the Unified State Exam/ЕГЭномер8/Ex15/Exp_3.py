for A in range(-100, 100):
    OK = True
    for x in range(0, 100):
        for y in range(0, 100):
            if (((x<=9)<=(x*x<=A)) and ((y*y<=A)<=(y<=9))) == 0:
                OK = False
    if OK == True:
        print(A)