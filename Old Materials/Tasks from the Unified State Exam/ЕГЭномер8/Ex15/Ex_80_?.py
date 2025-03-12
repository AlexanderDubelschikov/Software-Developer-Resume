r = 0
for a1 in range(0, 100):
    for a2 in range(a1, 100):
        OK = True
        for x in range(0, 10000):
            if ((a1 <=x+0.5<= a2) and not(not(11<= x+0.5<=28)<=(5<=x+0.5<=55)))==1:
                OK = False
        if OK == True and a2-a1 > r:
            r = a2 - a1
print(r)