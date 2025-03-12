def F(n):
    if n <= 5:
        return 2*n
    if n > 5 and n%2 == 0:
        return F(n-2) + 3*F(n//2) + n
    if n > 5 and n%2 != 0:
        return F(n-1) + F(n-2) + F(n-3)
print(F(99) + F(100))