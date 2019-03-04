"""
ID: nbjarvi1
LANG: PYTHON3
TASK: comehome
"""
from collections import defaultdict

def search(edges, start="Z"):
    nodequeue = []
    distances = {}
    for nodename in edges.keys():
        nodequeue.append(nodename)
        distances[nodename] = float("inf")
    distances[start] = 0
    while nodequeue:
        current = None
        smallest = float("inf")
        for key in nodequeue:
            if distances[key] < smallest:
                current = key
                smallest = distances[key]
        nodequeue.remove(current)
        for nbdist, nbname in edges[current]:
            dist = distances[current] + nbdist
            if dist < distances[nbname]:
                distances[nbname] = dist
    return distances

with open("comehome.in", "r") as fin, open("comehome.out", "w") as fout:
    edges = defaultdict(list)
    vertices = []
    N = int(fin.readline().strip())
    for i in range(N):
        frm, to, dst = fin.readline().strip().split()
        dst = int(dst)
        edges[frm].append((dst, to))
        edges[to].append((dst, frm))

    res = (None, float("inf"))
    for k,v in search(edges, "Z").items():
        print(k, v)
        if k.isupper() and k != "Z" and v < res[1]:
            res = (k, v)
    
    fout.write("{} {}\n".format(*res))
