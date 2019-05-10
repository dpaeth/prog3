import re


def isHawaiian(w):
    konsonanten = "hklmnpw"
    vokale = "aeiou"

    m1 = re.compile(r'[aeiouhklmnpw’]+[aeiou]', re.IGNORECASE)
    m2 = re.compile(r'([hklmnpw][aeiou])+|[aeiou]')

    if re.match(m1, w) and re.match(m2, w):
        return True
    return False


print(isHawaiian("Aloha"))
print(isHawaiian("Hawai’i"))
print(isHawaiian("wikiwiki"))
print(isHawaiian("Humuhumunukunukuapua’a"))
print(isHawaiian("Qui’juno"))
print(isHawaiian("Alaaf"))
print(isHawaiian("lekker"))
print(isHawaiian("Pu’kuuli"))
print(isHawaiian("ohamak’uluu"))






