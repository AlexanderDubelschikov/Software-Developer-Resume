for N in range(1, 13):
    x = bin(N)[2:]
    if N%2 == 0:
        x = x + '10'
    K = int(x,2)
    if K%2!=0:
        x = '1' + x + '01'
    R = int(x,2)
    print(N, R)
