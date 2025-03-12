def f(x,y,p,k):
    if x+y >= 77:
        return p%2 == k%2
    if p > k:
        return False
    v = [f(x+1,y,p+1,k), f(x,y+1,p+1,k), f(x*2,y,p+1,k), f(x,y*2,p+1,k)]
    if p%2 != k%2:
        return any(v)
    else:
        return all(v)

for s in range(1, 70):
    if f(7,s,0,4) == True and f(7,s,0,2) == False:
        print(s)
        break