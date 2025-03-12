f = open('9-1.txt')
count = 0
for s in f:
    m = [int(x) for x in s.split()]
    pov = [x for x in m if m.count(x)==3]
    nepov = [x for x in m if m.count(x)==1]
    if len(pov) == 3 and len(nepov) == 4:
        if (sum(nepov)/4) <= (pov[0]):
            count += 1
print(count)