def permutationen(seq):
    if len(seq) == 1:
        yield seq
    else:
        for i, let in enumerate(seq):
            for perm in permutationen(seq[:i] + seq[i+1:]):
                yield let, perm


for p in permutationen([1, 2, 3]):
    print(p)

