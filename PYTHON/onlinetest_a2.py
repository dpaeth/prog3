'''
Created on 6 Feb 2019

@author: dorianpaeth
'''


def statistik(dateiname):
    result = {}

    for z in [x.split(";") for x in dateiname.readlines()]:
        plz = z[0]
        name = z[1]
        betrag = z[2]
        if plz not in result:
            result[plz] = {name: int(betrag)}
        else:
            if name not in result.get(plz):
                result.get(plz)[name] = int(betrag)
            else:
                result.get(plz)[name] = result.get(plz)[name] + int(betrag)

    for key in sorted([x for x in result]):
        ausgabe = []
        plz = str(key)
        kunden = result[key]
        for name in kunden:
            betrag = str(kunden[name])
            ausgabe.append(name + "(" + betrag + ") ")
        print(plz + ": " + "".join(sorted(ausgabe)))


bestellungen = open("bestellungen.txt")
statistik(bestellungen)
