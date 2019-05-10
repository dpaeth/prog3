import re

cur = re.compile("(\d*((\.\d{3})*)*(,\d{2})?(\sEUR)?)$")

if cur.match("1.234,56"):
    print("YES")
else:
    print("NO")
