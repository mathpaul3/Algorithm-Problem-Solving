a,b = (list(x) for x in input().split())
a.reverse()
b.reverse()
print("".join(a) if int("".join(a)) > int("".join(b)) else "".join(b))