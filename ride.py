"""
ID: nbjarvi1
LANG: PYTHON3
TASK: ride
"""

from functools import reduce
from operator import mul

with open("ride.in", "r") as fin:
    comet = reduce(mul, [ord(c)-64 for c in fin.readline().strip()], 1) % 47
    group = reduce(mul, [ord(c)-64 for c in fin.readline().strip()], 1) % 47

    with open("ride.out", "w") as fout:
        fout.write(["STAY", "GO"][comet == group] + "\n")
