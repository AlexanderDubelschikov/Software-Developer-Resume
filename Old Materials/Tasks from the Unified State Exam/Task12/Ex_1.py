c = '8'*70

while ('2222' in c) or ('8888' in c):
  if ('2222' in c):
    c = c.replace('2222', '88', 1)
  else:
    c = c.replace('8888', '22', 1)

print (c)