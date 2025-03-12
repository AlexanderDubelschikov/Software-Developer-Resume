def F(n):
    if n > 12:
        return n*n*n + 3
    if n <= 12:
        return F(n+2) + 2*F(n+1)
k = 0
for i in range(1,1001):
    if F(i) % 12 == 0:
        k = k + 1
print(k)