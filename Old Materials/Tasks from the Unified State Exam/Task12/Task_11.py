c = '1'+'0'*75

while ('10' in c) or ('1' in c):
  if ('10' in c):
    c = c.replace('10', '001',1)
  else:
    c = c.replace('1', '00',1)

print (c.count('0'))