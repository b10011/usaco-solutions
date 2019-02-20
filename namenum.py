"""
ID: nbjarvi1
LANG: PYTHON3
TASK: namenum
"""

import re

mapping = ["[ABC]", "[DEF]", "[GHI]", "[JKL]", "[MNO]", "[PRS]", "[TUV]", "[WXY]"]

with open("namenum.in", "r") as fin:
    with open("dict.txt", "r") as dictin:
        names = dictin.read()

        numbers = [mapping[n-2] for n in map(int, fin.readline().strip())]

        regex = "^{}$".format("".join(numbers))

        res = re.findall(regex, names, flags=re.MULTILINE)

        with open("namenum.out", "w") as fout:
            if res:
                fout.write("\n".join(res))
            else:
                fout.write("NONE")
            fout.write("\n")
