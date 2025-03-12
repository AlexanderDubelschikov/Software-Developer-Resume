for x in range(20):
    for y in range(20):
        for z in range(20):
            s='0'+x*'1'+y*'2'+z*'3'
            while '01' in s or '02' in s or '03' in s:
                s=s.replace('01','302',1)
                s=s.replace('02','3103',1)
                s=s.replace('03','20',1)
            if s.count('1')==30 and s.count('2')==39 and s.count('3')==42:
                print(y)
                break