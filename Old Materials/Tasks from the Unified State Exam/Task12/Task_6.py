c = '6'*79

while ('2222' in c) or ('666' in c):
    if ('2222' in c):
        c = c.replace('2222', '6',1)
    else:
        c = c.replace('666', '2', 1)

print (c)