import sys
import re

log = open(sys.argv[1]).readlines()

result = []
for l in log:
    if re.compile(".*(GET).*(\.(png|gif|jpg))").match(l):
        result.append(l)

print(len(result))