def h(a, b, c=1000, *d, **e): print(a, b, c, d, e)


tup = ('ene', 'mene', 'mu')

kw = {'x': 'iks', 'b': 'beh', 'lst ': [17, 17, 17]}

h(10, 20, 30, tup, **kw)
