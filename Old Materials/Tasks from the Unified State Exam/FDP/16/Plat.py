from sys import setrecursionlimit
setrecursionlimit(6000)

def F(n):
    if n<=15:
        return n * n + 3 * n + 9
    if n > 15 and n % 3 == 0:
        return F(n-1) + n - 2
    if n <= 25 and n % 3 != 0:
        return F(n-2) + n + 2
k = 0
k2 = 0
for n in range(1, 1001):
    k2 = 0
    print(F(n),n)
