"""
ID: nbjarvi1
LANG: PYTHON3
TASK: milk2
"""

def combine_overlapping(times):
    if times == []:
        return []

    times = sorted(times, key=lambda i: i[0])
        
    longest = [times[0]]

    for s, e in times[1:]:
        found_matches = False
        for li, (ls, le) in enumerate(longest):
            if ls <= s <= le or ls <= e <= le:
                longest[li] = (min(ls, s), max(le, e))
                found_matches = True
        if not found_matches:
            longest.append((s, e))

    return longest

with open("milk2.in", "r") as fin:
    n_times = int(fin.readline())
    times = [tuple(map(int, fin.readline().strip().split()))
             for _ in range(n_times)]
    
    times = combine_overlapping(times)

    idle_times = [
        (times[i][1], times[i+1][0])
        for i in range(len(times)-1)
        if times[i+1][0] - times[i][1] > 0]
    
    idle_times = combine_overlapping(idle_times)

    if times == []:
        times = [(0, 0)]

    if idle_times == []:
        idle_times = [(0, 0)]

    with open("milk2.out", "w") as fout:
        fout.write("{} {}\n".format(
            max(e-s for s,e in times),
            max(e-s for s,e in idle_times)))
