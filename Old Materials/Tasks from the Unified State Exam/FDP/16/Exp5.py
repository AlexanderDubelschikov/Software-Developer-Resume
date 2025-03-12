def F(n):
    if n <= 3:
        return n
    if n%2 == 0:
        return n + F(n-1)
    if n%2 != 0:
        return n*n+ F(n-2)
i = 1
while F(i) < 1e8:
    i = i + 1
print(i-1)
