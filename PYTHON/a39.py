class MonotonieVerstossError(ValueError):
    pass

class Messwert:
    def __init__(self, *werte):
        if len(werte) is 1:
            self.zeitpunkt = str(werte[0].split(",")[0]).strip('"')
            self.temperatur = float(werte[0].split(",")[1])
        if len(werte) is 2:
            self.zeitpunkt = werte[0]
            self.temperatur = float(werte[1])

    def __repr__(self):
        return "'"+str(self.zeitpunkt)+"\', "+str(self.temperatur)

    def __lt__(self, other):
        if self.zeitpunkt is other.zeitpunkt:
            return self.messwert < other.messwert
        else:
            return self.zeitpunkt < other.zeitpunkt

    def __eq__(self, other):
        if (self.temperatur is other.temperatur) and (self.zeitpunkt is other.zeitpunkt):
            return True
        return False

    def __hash__(self):
        return hash((self.zeitpunkt, self.temperatur))


class Messreihe:
    def __init__(self, logdatei=None):
        if logdatei is None:
            self.messwerte = []
        else:
            self.messwerte = [Messwert(x) for x in open(logdatei).readlines()]

    def __len__(self):
        return len(self.messwerte)

    def add(self, other):
        assert (isinstance(other, Messwert) or isinstance(other, str)), "Kein gültiger Datentyp"
        if isinstance(other, Messwert):
            return self.messwerte.append(other)
        if isinstance(other, list):
            for mw in other:
                if mw not in self.messwerte:
                    self.messwerte.append(mw)

        return self.messwerte

    def addNew(self, other):
        assert isinstance(other, Messwert), "Kein Messwert"
        if other < sorted(self.messwerte)[-1]:
            raise RuntimeError("Wert "+str(other)+" liegt unter neuestem Wert ("+str(self.messwerte[-1])+")")
        else:
            self.add(other)

    def __add__(self, other):
        new = self.add(other.messwerte)
        return new

    def __iter__(self):
        return iter([self.messwerte])

    def __getitem__(self, item):
        if isinstance(item, slice):
            return self.messwerte[item.start:item.stop:item.step]
        if isinstance(item, int):
            return self.messwerte[item]
        if isinstance(item, str):
            new = Messreihe()
            for mw in self.messwerte:
                if item in mw.zeitpunkt:
                    new.add(mw)
            return new


def enum(iterable):
    for i in range(len(iterable)):
        yield (i, iterable[i])


mw = [Messwert(x) for x in open("messwerte.csv").readlines()][:5]
mr = Messreihe("messwerte.csv")

try:
    mr.addNew(mw[0])
except ValueError as exc:
    print(exc)
