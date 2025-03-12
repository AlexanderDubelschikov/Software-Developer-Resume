r=0
P=range(10,31)
Q=range(12,25)
for a1 in range(0, 100):
    for a2 in range(a1, 100):
        OK = True
        for x in range(0, 100):
            A = range(a1,a2+1)
            if (((x in P) and (x in Q)) <= (x in A))==0:
                OK = False
        if OK == True:
            r = a2 - a1
            break
print(r)