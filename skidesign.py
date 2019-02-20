"""
ID: nbjarvi1
LANG: PYTHON3
TASK: skidesign
"""

def readnint(handle):
    return list(map(
        int,
        handle.readline().strip().split()))

def vecadd(A, B):
    return [a+b for a,b in zip(A, B)]

def vecsub(A, B):
    return [a-b for a,b in zip(A, B)]

def buildhills(hills, diffs):
    currenthills = vecadd(hills, diffs)
    newmin = min(currenthills) + 1
    newhills = [max(newmin, i) for i in currenthills]
    return vecsub(newhills, hills)

def destroyhills(hills, diffs):
    currenthills = vecadd(hills, diffs)
    newmax = max(currenthills) - 1
    newhills = [min(newmax, i) for i in currenthills]
    return vecsub(newhills, hills)

def calccost(diffs):
    return sum(i**2 for i in diffs)

def calcdiff(hills):
    return max(hills) - min(hills)

with open("skidesign.in", "r") as fin:
    (N,) = readnint(fin)
    hills = sorted([readnint(fin)[0] for _ in range(N)])
    diffs = [0]*len(hills)

    while calcdiff(vecadd(hills, diffs)) > 17:
        current_cost = calccost(diffs)

        build = buildhills(hills, diffs)
        destroy = destroyhills(hills, diffs)

        build_cost = calccost(build)
        destroy_cost = calccost(destroy)

        if build_cost < destroy_cost:
            diffs = build
        else:
            diffs = destroy
        
    with open("skidesign.out", "w") as fout:
        fout.write("{}\n".format(calccost(diffs)))
