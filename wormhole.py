"""
ID: nbjarvi1
LANG: PYTHON3
TASK: wormhole
"""

from collections import defaultdict

def readnint(handle):
    return list(map(
        int,
        handle.readline().strip().split()))

def pairgen(l):
    if len(l) < 2:
        yield ()
    else:
        for i in range(1, len(l)):
            for tail in pairgen(l[1:i] + l[i+1:]):
                yield (l[0], l[i], *tail)

def walk(holes, cow):
    for hole in sorted(holes, key=lambda i: i[0]):
        if hole[1] == cow[1] and hole[0] > cow[0]:
            return hole
    return None

with open("wormhole.in", "r") as fin:
    (N,) = readnint(fin)
    holes = [tuple(readnint(fin)) for _ in range(N)]
    pairings = pairgen(holes)
    
    cycles = 0
    for pairing in pairings:
        jumps = dict()
        jumps.update({
            pairing[i*2]:(pairing[i*2+1][0]+1, pairing[i*2+1][1])
            for i in range(len(pairing)//2) })

        jumps.update({
            pairing[i*2+1]:(pairing[i*2][0]+1, pairing[i*2][1])
            for i in range(len(pairing)//2) })

        
        jumps.update({
            (hole[0]+1, hole[1]):walk(holes, (hole[0]+1, hole[1]))
            for hole in holes
            if (hole[0]+1, hole[1]) not in holes })

        cyclic = False
        for hole in holes:
            cow = hole
            visited = defaultdict(lambda: False)
            while True:
                if cow in jumps.keys():
                    if visited[cow]:
                        cyclic = True
                        break
                    visited[cow] = True
                    cow = jumps[cow]
                    if cow == None:
                        break
            if cyclic:
                break

        cycles += cyclic
        
    with open("wormhole.out", "w") as fout:
        fout.write("{}\n".format(cycles))
