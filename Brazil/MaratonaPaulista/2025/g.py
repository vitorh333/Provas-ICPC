s = input()

if s == "BR-S?" or s == "BR-?P":
    print("T")
elif s in ("B?-SP", "?R-SP", "BR?SP"):
    print("S")
else:
    print("N")
