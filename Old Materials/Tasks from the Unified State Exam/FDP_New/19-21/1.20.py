def f(x,p,k):
    if x >= 88:
        return p == k
    if p > k:
        return False
    v = [f(x+1,p+1,k), f(x+4,p+1,k), f(x*3,p+1,k)]
    if p%2 != k%2:
        return any(v)
    else:
        return all(v)

for s in range(1, 88):
    if f(s,0,3) == True and f(s,0,1) == False:
        print(s)