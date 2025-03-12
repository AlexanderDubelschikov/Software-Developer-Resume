alph = '0123456789ABCDEFGHI'

for x in alph:
    n = int(f'55{x}36', 19) + int(f'{x}2724', 19)
    if n % 11 == 0:
        print(n // 11)
        break