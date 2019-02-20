"""
ID: nbjarvi1
LANG: PYTHON3
TASK: dualpal
"""

from itertools import count
from math import log

def with_base_raw(num, base):
    return [num // div % base
            for div in map(
                    lambda c: base**c,
                    range(int(log(num, base))+1))]

def has_over_2_palindromes(n):
    pals = 0
    for base in range(2, 11):
        num = with_base_raw(s, base)
        rev = list(reversed(num))
        if num == rev:
            pals += 1
        if pals >= 2:
            break
    return pals >= 2

with open("dualpal.in", "r") as fin:
    N, S = fin.readline().strip().split()
    N, S = int(N), int(S)

    res = []
    
    for s in count(S+1):
        if has_over_2_palindromes(s):
            res.append(s)
            if len(res) >= N:
                break
    
    with open("dualpal.out", "w") as fout:
        fout.write("\n".join(map(str, res)))
        fout.write("\n")
