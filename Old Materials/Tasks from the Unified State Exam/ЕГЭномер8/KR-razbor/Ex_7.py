for N in range(1, 1000):
    x = bin(N)[2:]
    if (x.count('0')+x.count('1'))%2==0:
        x = '10'+ x[2:] + '0'
    K = int(x,2)
    if (x.count('0')+x.count('1'))%2!=0:
        x = '11' + x[2:] + '1'
    R = int(x,2)
    print(N, R)
    if R>15:
        break