"""
ID: nbjarvi1
LANG: PYTHON3
TASK: palsquare
"""

from math import log

def with_base_raw(num, base):
    return [num // div % base
            for div in map(
                    lambda c: base**c,
                    range(int(log(num, base))+1))]

def prettyprint(numlist):
    return "".join(map(lambda i: str(i) if i < 10 else chr(55+i), numlist))

with open("palsquare.in", "r") as fin:
    with open("palsquare.out", "w") as fout:
        base = int(fin.readline())
    
        for i in range(1, 301):
            square = i**2
            num = with_base_raw(square, base)
    
            rev = list(reversed(num))
    
            if num == rev and sum(num):
                pretty_i = prettyprint(reversed(with_base_raw(i, base)))
                pretty_num = prettyprint(rev)
                fout.write("{} {}\n".format(pretty_i, pretty_num))
