def dreh(lst):
    """Dreht mitgegebene Liste rekursiv um."""

    if len(lst) == 2:
        return [lst[1], lst[0]]

    elif len(lst) > 2:
        rest = lst[1:]
        rest = dreh(rest)
        rest.append(lst[0])
        return rest


print()

lst1 = ["a", "b", "c", "d", "e", "f"]
print(lst1)
print(dreh(lst1))
print()


lst2 = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
print(lst2)
print(dreh(lst2))
print()
