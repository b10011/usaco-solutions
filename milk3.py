"""
ID: nbjarvi1
LANG: PYTHON3
TASK: milk3
"""

def readnint(handle):
    return list(map(
        int,
        handle.readline().strip().split()))

def pour(A, B, C, a, b, c, visited=[]):
    if (a, b, c) in visited:
        return ({ c } if a == 0 else set())

    visited.append((a, b, c))

    cset = set()

    canpour = min(a, B-b)
    if canpour:
        cset |= pour(A, B, C, a-canpour, b+canpour, c, visited)

    canpour = min(a, C-c)
    if canpour:
        cset |= pour(A, B, C, a-canpour, b, c+canpour, visited)

    canpour = min(b, A-a)
    if canpour:
        cset |= pour(A, B, C, a+canpour, b-canpour, c, visited)

    canpour = min(b, C-c)
    if canpour:
        cset |= pour(A, B, C, a, b-canpour, c+canpour, visited)

    canpour = min(c, A-a)
    if canpour:
        cset |= pour(A, B, C, a+canpour, b, c-canpour, visited)

    canpour = min(c, B-b)
    if canpour:
        cset |= pour(A, B, C, a, b+canpour, c-canpour, visited)

    return cset

with open("milk3.in", "r") as fin:
    import time
    s = time.time()
    A, B, C = readnint(fin)

    res = pour(A, B, C, 0, 0, C)
    e = time.time()
    
    print(res)

    print(e-s)

    with open("milk3.out", "w") as fout:
        fout.write(" ".join(map(str, sorted(list(res)))) + "\n")
