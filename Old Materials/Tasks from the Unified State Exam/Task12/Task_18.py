min_units = float('inf')
min_length = 0

for start_length in range(101, 200):
    s = "1" * start_length

    while "111" in s:
        s = s.replace("111", "2", 1)
        s = s.replace("2222", "333", 1)
        s = s.replace("33", "1", 1)

    final_units = s.count("1")

    if final_units < min_units:
        min_units = final_units
        min_length = start_length

print("Минимальное количество единиц в итоговой строке:", min_units)
print("Минимальная начальная длина строки:", min_length)