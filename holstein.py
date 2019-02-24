"""
ID: nbjarvi1
LANG: PYTHON3
TASK: holstein
"""

from itertools import combinations

def readnint(handle):
    return list(map(
        int,
        handle.readline().strip().split()))

def subtract(a, b):
    return list(map(lambda i: i[0]-i[1], zip(a, b)))

def ok(vec):
    return not any(map(lambda i: i > 0, vec))

def search():
    res = []
    for i in range(1, G+1):
        for c in combinations(gi, i):
            tmp = v[:]
            for cc in c:
                tmp = subtract(tmp, g[cc])
            if ok(tmp):
                return c

with open("holstein.in", "r") as fin:
    (V,) = readnint(fin)
    v = readnint(fin)
    (G,) = readnint(fin)
    g = [readnint(fin) for _ in range(G)]
    gi = list(range(len(g)))

    res = search()

    with open("holstein.out", "w") as fout:
        fout.write("{} {}\n".format(len(res), " ".join(map(lambda i: str(i+1), sorted(res)))))
