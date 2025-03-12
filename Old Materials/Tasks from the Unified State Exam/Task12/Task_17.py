initial_length = 138
max_units = 0
best_length = initial_length

for length in range(initial_length, 200):
    s = "1" * length
    while "111" in s:
        s = s.replace("111", "2", 1)
        s = s.replace("2222", "1", 1)

    unit_count = s.count("1")

    if unit_count > max_units:
        max_units = unit_count
        best_length = length

print("Минимальная длина исходной строки:", best_length)
print("Максимальное количество единиц в итоговой строке:", max_units)