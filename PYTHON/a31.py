import sys
import re

if len(sys.argv) > 1:
    filename = sys.argv[1]
else:
    print("Bitte Dateiname eingeben!")
    sys.exit()


def countwords(x):
    words = x.split()
    return len(words)


def countwordoccurences(x):
    words = re.split(", |. ", x)
    words = words.lower()
    d = {}


f = open(filename)

s = f.read()
actIPos = s.find("ACT I")

shakespeare = s[actIPos:]

print(countwords(shakespeare))
countwordoccurences(shakespeare)

