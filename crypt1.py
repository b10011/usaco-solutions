"""
ID: nbjarvi1
LANG: PYTHON3
TASK: crypt1
"""

from itertools import product

def readnint(handle):
    return list(map(
        int,
        handle.readline().strip().split()))

def list2int(lst):
    return sum(
        item*10**i
        for i, item in enumerate(reversed(lst)))

with open("crypt1.in", "r") as fin:
    readnint(fin)
    digits = set(readnint(fin))

    solutions = 0
    for a in map(list2int, product(*[digits]*3)):
        for b in product(*[digits]*2):
            m_parts = [a*bb for i, bb in enumerate(b)]

            subparts_ok = not any(
                (len(set(map(int, str(m_part))) - digits) != 0 or len(str(m_part)) != 3)
                for m_part in m_parts)
                    
            m = str(sum(
                item*10**i
                for i, item in enumerate(reversed(m_parts))))
            
            if subparts_ok and len(set(map(int, m)) - digits) == 0 and len(m) == 4:
                solutions += 1

    with open("crypt1.out", "w") as fout:
        fout.write("{}\n".format(solutions))
