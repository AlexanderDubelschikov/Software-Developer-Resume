c = '8'*125

while ('333' in c) or ('888' in c):
    if ('333' in c):
        c = c.replace('333', '8',1)
    else:
        c = c.replace('888', '3', 1)

print (c)