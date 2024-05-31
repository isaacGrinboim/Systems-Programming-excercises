a = [("tim",3), ("anna",3), ("steve",3), ("bob",3) , ("john",20)]

print(sorted(a, key=lambda x : (x[1], len(x[0]), x[0])))

