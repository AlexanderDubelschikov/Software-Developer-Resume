c = '7'*108

while ('33333' in c) or ('777' in c):
    if ('33333' in c):
        c = c.replace('33333', '7',1)
    else:
        c = c.replace('777', '3', 1)

print (c)