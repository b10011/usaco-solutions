"""
ID: nbjarvi1
LANG: PYTHON3
TASK: transform
"""

transformations = []

def transform_1(mat):
    side = len(mat)
    return [[
        [mat[side-i-1][j] for i in range(side)]
        for j in range(side)]]
transformations.append(transform_1)

def transform_2(mat):
    side = len(mat)
    return [[
        [mat[side-j-1][side-i-1] for i in range(side)]
        for j in range(side)]]
transformations.append(transform_2)

def transform_3(mat):
    side = len(mat)
    return [[
        [mat[i][side-j-1] for i in range(side)]
        for j in range(side)]]
transformations.append(transform_3)

def transform_4(mat):
    side = len(mat)
    return [[
        list(reversed(mat[i]))
        for i in range(side)]]
transformations.append(transform_4)

def transform_5(mat):
    side = len(mat)
    return [
        f(transform_4(mat)[0])[0]
        for f in [transform_1, transform_2, transform_3]]
transformations.append(transform_5)

def transform_6(mat):
    side = len(mat)
    return [[
        [
            mat[j][i]
            for i in range(side)]
        for j in range(side)]]
transformations.append(transform_6)

with open("transform.in", "r") as fin:
    side = int(fin.readline().strip())

    mat = [
        list(fin.readline().strip())
        for _ in range(side)]

    res = [
        list(fin.readline().strip())
        for _ in range(side)]

    for index, transform in enumerate(transformations):
        if res in transform(mat):
            break
    else:
        index = 6

    with open("transform.out", "w") as fout:
        fout.write("{}\n".format(index+1))
