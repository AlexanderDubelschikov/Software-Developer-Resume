c = '3'+'5'*57

while ('25' in c) or ('355' in c) or ('4555' in c):
    if ('25' in c):
        c = c.replace('25', '3',1)

    if ('355' in c):
        c = c.replace('355', '4',1)

    if ('4555' in c):
        c = c.replace('4555', '2',1)


print (c)