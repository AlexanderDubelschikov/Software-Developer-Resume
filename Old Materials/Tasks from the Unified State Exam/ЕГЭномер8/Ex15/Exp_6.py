r = 0
for a1 in range(0, 100):
    for a2 in range(a1, 100):
        OK = True
        for x in range(0, 100):
            if (((5 <=x+0.5<= 30)==(14 <=x+0.5<= 23))<=(not(a1 <=x+0.5<= a2))) == 0:
                OK = False
        if OK == True and a2-a1 > r:
            r = a2 - a1
print(r)

