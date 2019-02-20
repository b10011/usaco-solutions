"""
ID: nbjarvi1
LANG: PYTHON3
TASK: beads
"""

def rotate(lst, n):
    l = len(lst)
    for i in range(l):
        yield lst[(i-n) % l]

def collect(beads):
    beads = list(beads)
    
    for bead in beads:
        color = bead
        if color != "w":
            break

    collected = 0
    for bead in beads:
        if bead in [color, "w"]:
            collected += 1
        else:
            break

    return collected

def break_collect(beads, n):
    rotated = list(rotate(beads, -n))
    collected = collect(rotated)
    collected += collect(reversed(rotated[collected:]))
    return collected

with open("beads.in", "r") as fin:
    fin.readline()
    beads = fin.readline().strip()

    collected = 0
    for i in range(len(beads)):
        collected = max(collected, break_collect(beads, i))

    with open("beads.out", "w") as fout:
        fout.write("{}\n".format(collected))
