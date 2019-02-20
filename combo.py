"""
ID: nbjarvi1
LANG: PYTHON3
TASK: combo
"""

from functools import reduce

def get_valid_combinations(dial, code, tolerance):
    dial = list(range(1, dial+1))
    return [
        set([*dial[n-tolerance-1:], *dial[:n+tolerance]][:tolerance*2+1])
        for n in code]

def readnint(handle):
    return list(map(
        int,
        handle.readline().strip().split()))

with open("combo.in", "r") as fin:
    (N,) = readnint(fin)
    A = readnint(fin)
    B = readnint(fin)

    a = get_valid_combinations(N, A, 2)
    b = get_valid_combinations(N, B, 2)

    overlapping = [len(da & db) for da, db in zip(a, b)]
    overlapping_count = reduce(lambda acc,val: acc*val, overlapping, 1)

    valid_combinations = 0
    valid_combinations += reduce(lambda acc,val: acc*val, [len(d) for d in a], 1)
    valid_combinations += reduce(lambda acc,val: acc*val, [len(d) for d in b], 1)

    unique_combinations = valid_combinations - overlapping_count

    with open("combo.out", "w") as fout:
        fout.write("{}\n".format(unique_combinations))
