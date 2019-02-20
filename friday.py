"""
ID: nbjarvi1
LANG: PYTHON3
TASK: friday
"""

from itertools import cycle
from collections import defaultdict

calcfebdays = lambda y: (y % 4 == 0) - (y % 100 == 0) + (y % 400 == 0) + 28
days = [31, calcfebdays, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
weekdays = ["Sat", "Sun", "Mon", "Tue", "Wed", "Thu", "Fri"]
calcdays = lambda y, m: days[m] if type(days[m]) == int else days[m](y)

def rotate(lst, n):
    l = len(lst)
    for i in range(l):
        yield lst[(i-n) % l]

with open("friday.in", "r") as fin:
    years = int(fin.readline().strip())

    gen = zip(
        cycle(rotate(weekdays, -2)),
        (d+1
         for y in range(years)
         for m in range(12)
         for d in range(calcdays(1900+y, m))))

    res = defaultdict(int)
    for wd, d in gen:
        if d == 13:
            res[wd] += 1

    with open("friday.out", "w") as fout:
        fout.write(" ".join(str(res[wd]) for wd in weekdays))
        fout.write("\n")
