"""
ID: nbjarvi1
LANG: PYTHON3
TASK: barn1
"""

def readnint(handle):
    return list(map(
        int,
        handle.readline().strip().split()))

def longest_skip(arr):
    longest = 0
    index = 0
    for i in range(len(arr)-1):
        skip = arr[i+1]-arr[i]-1
        if longest < skip:
            longest = skip
            index = i
    return index, longest

with open("barn1.in", "r") as fin:
    M, S, C = readnint(fin)

    stalls = [sorted([readnint(fin)[0] for _ in range(C)])]

    for _ in range(M-1):
        skips = sorted([(stall_i, *longest_skip(item))
                        for stall_i, item in enumerate(stalls)],
                       key=lambda i: i[2],
                       reverse=True)
        stall_i, stall_longest_i, stall_longest = skips[0]
        left = stalls[stall_i][:stall_longest_i+1]
        right = stalls[stall_i][stall_longest_i+1:]
        stalls[stall_i] = left
        stalls.append(right)

    cover = sum(
        (stall[-1] - stall[0] + 1) if stall else 0
        for stall in stalls)

    print(cover)

    with open("barn1.out", "w") as fout:
        fout.write("{}\n".format(cover))
