f = open('9.txt','r')
k = 0
for s in f:
    a = list(map(int,s.split()))
    c = set(a)
    p = []
    n = []
    if len(c)==5:
        for i in range(len(a)):
            if a.count(a[i]) == 1:
                n.append(a[i])
            else:
                p.append(a[i])

        if sum(n) / len(n) <= sum(p):
            k = k + 1
print(k)
