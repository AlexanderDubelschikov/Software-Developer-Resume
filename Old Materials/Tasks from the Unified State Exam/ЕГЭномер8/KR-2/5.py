def f(n):
    s = ''
    while n > 0:
        s = str(n % 3) + s
        n //= 3
    return s


c = set()
for n in range(1, 100):
    s = f(n)
    if n % 3 == 0:
        s = s + s[-2:]
    else:
        s = s + f((n % 3) * 5)
    r = int(s, 3)
    if r > 133:
        c.add(r)
print(min(c))