k = 0
for i in range(0,2**20):
    x = bin(i)[2:]
    if (5+x.count('1'))%3 != 0:
        k += 1
print(k)
