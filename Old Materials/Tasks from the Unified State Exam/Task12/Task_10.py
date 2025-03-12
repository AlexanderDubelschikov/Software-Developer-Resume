c = '4'+'6'*79+'4'

while ('63' in c) or ('664' in c) or ('6665' in c):
  if ('63' in c):
    c = c.replace('63', '4',1)
  else:
    if ('664' in c):
      c = c.replace('664', '5',1)
    else:
      c = c.replace('6665', '3',1)

print (c)